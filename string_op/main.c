#define _CRT_SECURE_NO_WARNINGS 1
/**************************
*strstr(str1,str2)  �����ִ�str2�Ƿ���str1��,���ڷ����Ӵ��׵�ַ,���ڷ���NULL
********************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
int main()
{
	//memcpy()  ע��:�ڴ溯�������ֽ�Ϊ��λ������
	//char str1[20] = "anvhdbAABBCC";
	//char str2[10] = "123456";
	//int t;
	//t=memcpy(str1+1, str1, strlen(str1));
	//if (t != 0)
	//	printf("%d:%s\n", errno, strerror(errno));
	//printf("%s\n",str1);


	//memmove() ����ַ������ص�,��,memmove(),��Ӻ���ǰ����,��ֹ����
	//char str1[20] = "anvhdbAABBCC";
	//char str2[10] = "123456";
	//int t;
	//t = memmove(str1 + 1, str1, strlen(str1));
	//if (t != 0)
	//	printf("%d:%s\n", errno, strerror(errno));
	//printf("%s\n", str1);

	//strerror() ��ӡ����������(errno)����ϸ����
	//FILE *p = fopen("nofile.txt", "r");
	//if (p == NULL)
	//	printf("%d:%s\n", errno, strerror(errno));


	//strtok()���ָ��,��������ַ����м�'\0',����ָ�������,ֻ�ѵ�һ����'\0',��⵽û�ָ�������.
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


	// strstr(str1, str2)  �����ִ�str2�Ƿ���str1��, ���ڷ����Ӵ��׵�ַ, ���ڷ���NULL 
//	char *pstr1 = "this is a C program";
//	char *pstr2 = "a ";
//	pstr2 = strstr(pstr1, pstr2);
//	puts(pstr2);
	system("pause");
	return 0;
}