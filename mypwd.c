#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#define LENTH 255

//利用getcwd函数的返回值来输出当前路径
int main()
{
	char path[LENTH];//定义一个路径数组
	puts(getcwd(path,LENTH));
	//puts函数用来向标准输出设备输出字符并换行
	//getcwd是unistd.h库中的函数，会将当前工作目录的绝对路径复制到参数path所指的内存空间中，参数LENTH是path的空间大小
	return 0;
}
