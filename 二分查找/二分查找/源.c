#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int s = 0;
#define MAX 10
int main()
{
	int First = 0, Mid = 0, End = 0;//在一个有序数组中快速查找元素
	int arr[10];
	int n;
	for (int i = 0; i < MAX; i++)
		arr[i] = i + 1;
	End = MAX - 1;
	First = 0;
	scanf("%d", &n);
	while (First < End)
	{
		s++;

		Mid = First + (End - First) / 2;
		if (arr[Mid] < n)
		{
			First = Mid + 1;
		}
		else if (arr[Mid] > n)
			End = Mid;
		else if (arr[Mid] == n)
		{
			printf("n的下标 = %d,查找次数 = %d", Mid, s);
			return 0;
		}

	}
	printf("要查查找的元素不在次数组中");
}