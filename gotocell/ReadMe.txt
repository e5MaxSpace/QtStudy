gotocell 这个例子主要是为了练习qmake和make命令的：
1、qmake -project # qmake会自动识别当前目录下的.h和.cpp以及.ui文件，并生产合适的.pro工程文件（或叫项目文件，与平台无关）。
2、qmaek *.pro    # qmake会根据*.pro文件生成makefile文件（此makefile文件与平台相关）
3、make           # make会根据上一步生成的makefile文件（其实就是一些构建规则）构建程序，并生产exe文件（windows平台）
4、gotocell.exe   # 直接输入gotocell.exe，回车运行该程序