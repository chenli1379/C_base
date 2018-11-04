#define _CRT_SECURE_NO_WARNINGS 1
/**************************
*strstr(str1,str2)  查找字串str2是否在str1中,若在返回子串首地址,不在返回NULL
********************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
int main()
{
	//memcpy()  注意:内存函数是以字节为单位操作的
	//char str1[20] = "anvhdbAABBCC";
	//char str2[10] = "123456";
	//int t;
	//t=memcpy(str1+1, str1, strlen(str1));
	//if (t != 0)
	//	printf("%d:%s\n", errno, strerror(errno));
	//printf("%s\n",str1);


	//memmove() 如果字符串有重叠,则,memmove(),会从后往前拷贝,防止出错
	//char str1[20] = "anvhdbAABBCC";
	//char str2[10] = "123456";
	//int t;
	//t = memmove(str1 + 1, str1, strlen(str1));
	//if (t != 0)
	//	printf("%d:%s\n", errno, strerror(errno));
	//printf("%s\n", str1);

	//strerror() 打印错误描述符(errno)的详细描述
	//FILE *p = fopen("nofile.txt", "r");
	//if (p == NULL)
	//	printf("%d:%s\n", errno, strerror(errno));


	//strtok()检测分割符,给被检测字符串中加'\0',多个分隔符连续,只把第一个该'\0',检测到没分隔符结束.
	char pstr1[] = "this is:a C,program";
	char *fenge = " ,:";
	char *p=NULL;
	p = strtok(pstr1, fenge);
	printf("%s\n", p);
	while (p!=NULL)
	{
		p = strtok(NULL, fenge);
		printf("%s\n", p);
	}


	// strstr(str1, str2)  查找字串str2是否在str1中, 若在返回子串首地址, 不在返回NULL 
//	char *pstr1 = "this is a C program";
//	char *pstr2 = "a ";
//	pstr2 = strstr(pstr1, pstr2);
//	puts(pstr2);
	system("pause");
	return 0;
}