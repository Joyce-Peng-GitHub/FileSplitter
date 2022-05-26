#ifndef CP_DIR_H
#define CP_DIR_H

/* C standard library */
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/* Platform library */
#ifdef _WIN32
#include <direct.h>
#include <io.h>
#elif _LINUX
#include <stdarg.h>
#include <sys/stat.h>
#endif

/* Function for each platform */
#ifdef _WIN32
#define ACCESS _access
#define MKDIR(a) _mkdir((a))
#elif _LINUX
#define ACCESS access
#define MKDIR(a) mkdir((a), 0755)
#endif

/* Cross-platform function to create a directory */
int32_t create_dir(const char *s_path)
{
	int32_t i = 0, ret, sz_len = strlen(s_path);
	char *s = (char *)calloc(sz_len + 3, sizeof(char));

	if (!s)
	{
		return -1;
	}
	strcpy(s, s_path);
	/* append '/' */
	if (s[sz_len - 1] != '\\' && s[sz_len - 1] != '/')
	{
		s[sz_len++] = '/';
		s[sz_len++] = '\0';
	}

	/* make directory */
	for (i = 0; i < sz_len; i++)
	{
		if (s[i] == '\\' || s[i] == '/')
		{
			s[i] = '\0';

			/* create if not exist */
			ret = ACCESS(s, 0);
			if (ret != 0)
			{
				ret = MKDIR(s);
				if (ret)
				{
					return -1;
				}
			}
			/* replace '\\' with '/' */
			s[i] = '/';
		}
	}

	return 0;
}

#undef ACCESS
#undef MKDIR

#endif