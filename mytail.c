#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#define BUFFSIZE 512
int main(int argc,char **argv)
{
    char c;
    int line = 10;
    char buffer[BUFFSIZE][BUFFSIZE];
    int count=0;
    //如果有-n，就将line的默认值改了,自定义读取文件行数，这里有错误默认是会自动提示的。
//getopt函数是unistd.h头文件中的函数，执行时会依次扫描每一个命令行参数，如果扫描完毕就会返回-1
//getop函数用来解析命令行选项参数 前两个参数是从main直接传递来的，最后一个包含正确选项字符字符串，如果一个字符后面有冒号，那么在传递参数时就绪要跟着一个参数
    while((c=getopt(argc,argv,"n:"))!=-1)
	{
        int x=atoi(optarg);//optarg保存的选项参数，字符串形式
	//atoi是stdlib.h的函数，是将保存的选项参数字符串转换成一个整数并返回结果
        line = x;//获取要读取的行数
    }
    //获取文件路径，optind是某个头文件里的东西，不是我定义的，指示的是argv中下一个要读取的数据的下标
    char *path = argv[optind];//获取文件路径，optind传递给主函数的参数
    FILE *fp;
    int index = 0;
    //如果文件打开不成功，肯定是文件没找到，就报错
    if((fp = fopen(path,"r")) == NULL)
    {
        printf("文件不存在");
        return -1;
    }
   
    //下面就是前面讲的思路了，读取文件保存到数组
    while(!feof(fp))//feof在stdio.h库中，用于检测流上的文件结束符，若文件结束，则返回非0值，否则返回0
    {
	count++;
        fgets(buffer[index],BUFFSIZE,fp);//读取一行
	index++;//将index进行自增，把读取到的数据存储到buffer数组中
    }
    //记得关闭fp
    fclose(fp);
    if(count<line){
	printf("文件行数不够\n");
	}
    else{
	index=0;
    for(int i=0;i<line;i++)
    {//先输出buffer[index],再进行自增
        printf("%s",buffer[index++]);
    }
}

}
