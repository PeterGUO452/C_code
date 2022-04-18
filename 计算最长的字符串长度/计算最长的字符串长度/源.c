#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 10
#define MAXS 20

int max_len(char* s[], int n)
{
	int max, pmax = 0, i, j, k;
	for (i = 0; i < n; i++)
	{
		max = strlen(s[i]);
		if (max > pmax)
			pmax = max;

	}
	return pmax;


}

int main()
{
	int i, n;
	char* string[MAXN] = { NULL };//指针数组

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		string[i] = (char*)malloc(sizeof(char) * MAXS);
		scanf("%s", string[i]);
	}
	printf("%d\n", max_len(string, n));

	return 0;
}

/* 你的代码将被嵌在这里 */
