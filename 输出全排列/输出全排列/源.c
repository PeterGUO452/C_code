#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void swap(int* n1, int* n2)//两个两个之间的交换
{
	int temp;
	temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}
//                      j       k      j-k
void upswap(const int* s1, int* s2, int n)//从后往前交换
{
	int* p = s1 - 1;
	int temp;
	for (int i = 0; i < n; i++)
	{
		swap(s1, p);
		s1--;
		p--;
	}
}
void dwswap(const int* s1, int* s2, int n)//从前往后交换，也是两个两个交换
{
	int* p = s1 + 1;
	int temp;
	for (int i = 0; i < n; i++)
	{
		swap(s1, p);
		s1++;
		p++;
	}
}
void Xu(int* n1, int k, int m)//递归主函数
{
	if (k == m)
	{
		for (int j = 0; j <= m; j++)
			printf("%d", n1[j]);
		printf("\n");
	}
	else
	{
		for (int j = k; j <= m; j++)
		{
			upswap(&n1[j], &n1[k], j - k);
			Xu(n1, k + 1, m);
			dwswap(&n1[k], &n1[j], j - k);
		}
	}
}

int main()
{
	int n1[9] = { 1,2,3,4,5,6,7,8,9 };
	int n;
	scanf("%d", &n);
	Xu(n1, 0, n - 1);
}