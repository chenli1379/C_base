#define _CRT_SECURE_NO_WARNINGS 1
/**********************
*用函数指针实现计算器
****************************/
//#include<stdio.h>
//#include<stdlib.h>
//int add_(int x, int y)
//{
//	return x + y;
//}
//int sub_(int x, int y)
//{
//	return x - y;
//}
//int mul_(int x, int y)
//{
//	return x * y;
//}
//int div_(int x, int y)
//{
//	return x / y;
//}
//
//int menu()
//{
//	int chose=0;
//	printf("################################\n");
//	printf("     0.add           1.sub      \n");
//	printf("     2.mul           3.div      \n");
//	printf("################################\n");
//	printf("enter you chose:");
//	scanf("%d", &chose);
//	return chose;
//}
//int main()
//{
//	char sign[4] = { '+','-','*','/' };
//	int(*pfun[4])(int, int) = {add_,sub_,mul_,div_};
//	while (1)
//	{
//		int x = 0;
//		int y = 0;
//		int chose=menu();
//		printf("请输入两个操作数<x,y>:");
//		scanf("%d %d", &x, &y);
//		printf("%d %c %d = %d\n", x, sign[chose], y, pfun[chose](x, y));
//	}
//	system("pause");
//	return 0;
//}



#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[2][2] = {1,2,3,4};
	int *p = (int *)(*(arr + 1));
	printf("%d\n",*(p-1));
	system("pause");
	return 0;
}