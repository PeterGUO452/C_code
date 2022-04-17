#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int max(int x, int y)
{
	return x > y ? x : y;
}
int main()
{
	int  n, i, j, flag, flag1 = 0, count = 1, pcount = 0;
	//flag1 用来记录初始状态，同时也表示前一次flag的值，即前一次a[i] a[i+1]之间的大小关系
	//count用来记录每一次锯齿数组变化,pcount用来记录当锯齿数组不成力的是count的值
	int a[1000] = { 0 };
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	if (n == 0 || n == 1)
		printf("%d", n);

	for (i = 0; i < n - 1; i++)
	{

		if (a[i] == a[i + 1])//这是里判断的即是中间断开，也可以是一直就是数组元素相等，因此要保存cnt的值
		{
			pcount = max(count, pcount);//用pcount 保留了 count的值
			count = 1;
			flag1 = 0;
		}
		else
		{
			if (a[i] > a[i + 1])
				flag = 1;
			else if (a[i] < a[i + 1])
				flag = -1;
			if (flag1 != flag)//前后两个不相等
			{
				count++;
				flag1 = flag;
			}
			else
			{
				pcount = max(count, pcount);
				count = 2;
			}
		}
	}
	printf("%d", max(count, pcount));
}