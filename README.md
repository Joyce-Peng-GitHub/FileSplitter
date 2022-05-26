###### *English*
# File Splitter
## Compile Command
```bash
bash build.sh
```
```bash
g++ FileSplitter.cpp -o FileSplitter
```
#### Warning
###### Language Standard
You must use a C++ standard not earlier than `C++0x`, which means you must choose a standard from `C++0x`(the same as `C++11`), `C++14`, `C++17`, `C++20`, and even later standards.

As for me, I recommend to use `C++14` standard, like the `build.sh`:
```bash
g++ FileSplitter.cpp -o FileSplitter -std=c++14
```
###### OS support
The code above is surely correct in *Windows*, probably correct in *Linux*, with unknown correctness in other operating systems.

## Usage
#### Command Use
```bash
./FileSplitter ...[[maximal size] [file path]]
```
This allows you to split each file `[input file path]` into output files each of which is no larger than the `[maximal size]`.

The res for each input file will be saved in path `[file path]-split_res/`

For example, suppose that there's 3 files *1.cpp*, *2.cpp*, and *3,cpp*, and you'd like to split them into subfiles each of which is no larger than $50 \rm{kB}$, $80 \rm{kB}$, $100 \rm{kB}$, and then you can open the terminal and type:
```bash
# cd ... (to the directory)
./FileSplitter 50 1.cpp 80 2.cpp 100 3.cpp
```
After that, unless there's any error, you'll see there are 3 directories created beside the 3 input files, *1.cpp-split_res/*, *2.cpp-split_res/* and *3.cpp-split_res/*. 

That's how to use it as a command.

#### Interactive usage
Click the executable file, or run it in terminal (maybe like this):
```bash
./FileSplitter
```
Then input the maximal file size and file path according to the tips.

Input `'\0'` to quit the program. It's `Ctrl-z` in *Windows*, while `Ctrl-d` in *Linux*. Use `Ctrl-c` to stop the program urgently, or other commands according your operating system.


<br><br><br>

###### 中文
# 文件拆分器
## 编译命令
```bash
bash build.sh
```
```bash
g++ FileSplitter.cpp -o FileSplitter
```
#### 警告
###### 语言标准
你必须使用不早于`C++0x`的C++标准，这意味着你必须从`C++0x`（等价于`C++11`，`C++14`，`C++17`，`C++20`，以及更新的标准中选择一个。

对于我个人来说，我推荐使用`C++14`标准，就像`build.sh`那样：
```bash
g++ FileSplitter.cpp -o FileSplitter -std=c++14
```
###### 系统支持
上述代码在*Windows*中一定正确，在*Linux*中可能正确，而在其它操作系统中正确性未知。

## 使用方法
#### 命令用法
```bash
./FileSplitter ...[[maximal size] [file path]]
```
这条命令可以把每个`[input file path]`拆分成每个大小不超过`[maximal size]`的输出文件。

拆分每个输入文件的结果将被保存在路径`[file path]-split_res/`下。

例如，假设有3个文件*1.cpp*，*2.cpp*，以及*3,cpp*，并且你想要把它们都拆分成子文件，每个文件的子文件大小分别不超过$50 \rm{kB}$, $80 \rm{kB}$, $100 \rm{kB}$，于是你可以打开终端并输入：
```bash
# cd ... (到相应目录)
./FileSplitter 50 1.cpp 80 2.cpp 100 3.cpp
```
在那之后，如果没有出现任何错误，你将看见有3个目录创建在3个输入文件旁边，分别是*1.cpp-split_res/*，*2.cpp-split_res/*和*3.cpp-split_res/*

以上就是它的命令用法。

#### 交互用法
点击可执行文件，或者在命令行中运行它（也许像这样）：
```bash
./FileSplitter
```
然后根据提示输入最大文件大小和文件路径。

输入`'\0'`来退出程序。这个字符在*Windows*下是`Ctrl-z`，在*Linux*中是`Ctrl-d`。使用`Ctrl-c`来紧急停止程序，或者根据你的系统输入相应命令。