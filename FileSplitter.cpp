#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstring>
#include "cp_dir.h"

using byte_t = char;

inline int split(std::size_t mx_fsz, std::string path)
{
	std::ifstream in = std::ifstream(path, std::ios::in | std::ios::binary);
	byte_t *buf = new byte_t[mx_fsz + 1]{'\0'};
	std::size_t cnt = 0;
	std::ofstream out;
	if (!buf)
	{
		std::cerr << "Fatal error: Failed to allocate memory for the buffer!" << std::endl;
		goto ERR_RET;
	}
	if (!in)
	{
		std::cerr << "Failed to open the input file: " << path << std::endl;
		goto FAIL_RET;
	}
	if (create_dir((path += "-split_res/").c_str()))
	{
		std::cerr << "Failed to create the output directory: "
				  << path << std::endl;
		goto FAIL_RET;
	}
	while (in)
	{
		in.read(buf, mx_fsz);
		out.open(path + std::to_string(cnt) + ".out",
				 std::ios::out | std::ios::trunc | std::ios::binary);
		if (!out)
		{
			std::cerr << "Failed to open the output file: "
					  << path + std::to_string(cnt) + ".out"
					  << std::endl;
			goto FAIL_RET;
		}
		out.write(buf, (in ? mx_fsz : std::strlen(buf)));
		out.close();
		std::fill(buf, buf + mx_fsz + 1, '\0'); // clear buffer
		++cnt;
	}
	in.close();
	delete[] buf;
	return 1;
FAIL_RET:
	delete[] buf;
	return 0;
ERR_RET:
	return -1;
}

int main(int argc, char *argv[])
{
	std::ios::sync_with_stdio(false);
	std::size_t mx_fsz = 0;
	std::string path;
	std::stringstream ss;
	if (argc > 2)
	{
		for (int i = 1; i + 1 < argc; i += 2)
		{
			ss.clear();
			ss << argv[i];
			if (!(ss >> mx_fsz))
			{
				std::cerr << "Invalid parameter for maximal file size!" << std::endl;
				continue;
			}
			if (split(mx_fsz, path = argv[i + 1]) == -1)
			{
				goto ERR_RET;
			}
		}
	}
	else
	{
		while (std::cin)
		{
			std::cout << "Input the maximal size of each output file: ";
			if (!(std::cin >> mx_fsz))
			{
				if (std::cin.eof())
				{
					std::cout << "Exit." << std::endl;
					goto RET;
				}
				std::cerr << "Invalid input for maximal file size!" << std::endl;
				goto RET;
			}
			std::getline(std::cin, path); // blank
			std::cout << "Input the path of the file to split: ";
			if (!std::getline(std::cin, path))
			{
				if (std::cin.eof())
				{
					std::cout << "Exit." << std::endl;
					goto RET;
				}
				std::cerr << "Fatal error: Failed to write data into the string!" << std::endl;
				goto ERR_RET;
			}
			if (split(mx_fsz, path) == -1)
			{
				goto ERR_RET;
			}
		}
	}
RET:
	return 0;
ERR_RET:
	return -1;
}