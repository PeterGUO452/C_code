#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/***你编写的函数将放在这里***/

void Union(int* A, int* B, int* C, int Asize, int Bsize, int* Csize)//比较A，b中的元素；
{
	int i, j, k = 0, l, m = 0;
	for (i = 0; i < Asize; i++)
	{
		C[i] = A[i];
		*Csize += 1;
	}
	while (Bsize != 0)
	{
		k = 0;
		for (j = 0; j < Asize; j++)
		{
			if (C[j] == B[m])
			{
				k = 1;
				break;
			}

		}
		if (k != 1)
		{
			C[i] = B[m];
			*Csize += 1;
			i++;
		}
		m++;

		Bsize -= 1;
	}



}

void display(int* T, int p)
{
	int i;
	printf("%d", p);
	if (p > 0)
	{
		for (i = 0; i < p - 1; i++)
			printf(" %d", T[i]);
		printf(" %d\n", T[i]);
	}
}
void read(int* B, int size)
{
	int i;
	for (i = 0; i < size; i++)
		scanf("%d", &B[i]);
}
int main()
{
	int a[100], b[100], c[200];
	int m, n, o = 0;
	scanf("%d", &m);
	read(a, m);
	scanf("%d", &n);
	read(b, n);
	Union(a, b, c, m, n, &o);
	display(c, o);
	return 0;
}
