#define _CRT_SECURE_NO_WARNINGS

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include<stdio.h>
int main()
{
	int n, i, j, k, m;
	int prime[105] = { 0 };
	scanf("%d", &n);
	for (i = 2; i <= n; i++)
	{
		if (prime[i] == 0)//没有被标记
		{
			prime[++prime[0]] = i;//prime[0] 只用来存放素数的个数,prime[1]以后用来存放每一个素数,不是下标表示，就是把素数存进去
		}
		for (int j = 1; j <= prime[0]; j++)//j 要小于当前的素数个数  这个循环用来标记后面的的数
		{
			if (i * prime[j] > n)//用来判断这个 i 在那个范围，与 sqrt(n)作用类似
				break;

			prime[i * prime[j]] = 1;//用来标记后后后面的每一个数不是合数，如果是合数就会标记成 1 ，
									//只要后面的数被标记成了 1 ，在第一个 if 时就不会把这个数存到 prime 数组里里面去

			if (i % prime[j] == 0)// prime[j] 始终是从 2 开始，且因为在在这个内循环的条件里面，j<素数的个数;
				break;			//所以每一个prime[j]都是素数,prime[].j从 1 开始就是用来存放素数的
								//每一个合数都是若干个素数相乘，因此每一个素数都至少会被他前面的一个素数整除
								//因此这个数如果是合数，那么不用一直除到这个数本身就能被整除				
		}
	}
	for (i = 1; i <= prime[0]; i++)
	{
		printf("%d ", prime[i]);
	}

}