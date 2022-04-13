#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int s;
int main()
{
	int i=0,k,m;
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(a)/sizeof(a[0]);
	int temp;
	for (int i = 0; i < n - 1; i++)//循环趟数比数组元素小一
	{
		for (int j = 0; j < n - i -1; j++)//总共 n 个元素，每一趟两两比较的次数为 n-1次；
								//每完成一趟就要减少 1个元素，这个元素已经到了最右边，走几趟就要减少几个元素参与下一次的比较
		{
			if (a[j] < a[j + 1])//前面一个元素小于后面一个元素，则把他们互换位置，把较小的元素放到后面去，实现从大到小的排序
			{
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
				s++;
			}
		}
		for (k = 0; k < n; k++)//检查没每一趟之后元素的顺序是否已经达到目的，如果已经达到则跳出数组
		{
			if (a[k] > a[k + 1])
				m = 1;
		}
		if (m != 1)
			break;
	}
	for (int i = 0; i < n; i++)
	printf("%d ", a[i]);
	printf("%d", s);
	return 0;
}