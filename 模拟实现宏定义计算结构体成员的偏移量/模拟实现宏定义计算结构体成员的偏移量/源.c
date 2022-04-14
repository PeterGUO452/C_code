#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define OFFSETOF(struct_name,member_name)   (int )( &(((struct_name*)0)->member_name))
struct S
{
	char c1;//0 
	int i1;//4 5 6 7
	char c2;//8
	int i2;//12 13 14 15
};
int main()
{
	//模拟实现宏定义计算偏移量
	printf("%d\n", OFFSETOF(struct S, c1));
	printf("%d\n", OFFSETOF(struct S, i1));
	printf("%d\n", OFFSETOF(struct S, c2));
	printf("%d\n", OFFSETOF(struct S, i2));

}
