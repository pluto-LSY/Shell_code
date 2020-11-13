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
    int count = 0;
    char buffer[BUFFSIZE][BUFFSIZE];

    //如果有-n，就将line的默认值改了。这里有错误默认是会自动提示的。
    while((c=getopt(argc,argv,"n:"))!=-1)
    {
        int x = atoi(optarg);
        line = x;
    }
    //获取文件路径，optind是某个头文件里的东西，不是我定义的，指示的是argv中下一个要读取的数据的下标
    char *path = argv[optind];


    FILE *fp;
    int index = 0;
    //如果文件打开不成功，肯定是文件没找到，就报错
    if((fp = fopen(path,"r")) == NULL)
    {
        printf("File dosen't exit!");
        return -1;
    }

    //下面就是前面讲的思路了，读取文件保存到数组
    while(!feof(fp))
    {
      //  count++;
        fgets(buffer[index],BUFFSIZE,fp);
	index++;
    }
    //记得关闭fp
	//printf("%d@",index);
    fclose(fp);
    int i;

    for(i = 0;i<=line;i++)
    {
	//printf("%d``````",index);
        printf("%s",buffer[i-1]);
        /*if(index >= line)
        {
            index = 0;
        }*/
    }
}
