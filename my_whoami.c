#include<stdio.h>
#include<sys/types.h>//基本数据类型
#include<pwd.h>//口令文件

int main(int ac,char *av[])
{
	struct passwd *pw=NULL;//调用了passwd结构体中记录了uid与username的变量pw
	/*passwd的结构体：
	char *pw_name 用户名
	char *pw_passwd 密码
	__uid_t pw_uid  用户id
	__gid_t pw_gid 组id
	char  *pw_gecos 真实名
	char  *pw_dir  主目录
	char *pw_shell 使用的shell
	*/
	pw= getpwuid(getuid());//getuid来取得执行程序的uid
	//getpwuid是专门记录了uid与username的函数 根据uid返回指向passwd的结构体，该结构体初始化了里面的所有成员
	//如果没有获取到pw则输出错误信息	
	if(pw==NULL){
		perror(*av);
		return -1;
	}
	//因为结构体中有pw_name记录了用户名，直接指向此变量即可
	printf("%s\n",pw->pw_name);
}
