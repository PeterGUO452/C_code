#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void Initboard(char board[ROWS][COLS], int rows, int cols, char set)//初始化棋盘
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void Displayboard(char board[ROWS][COLS], int row, int col)//打印棋盘
{
	int i, j;
	for (i = 0; i <= col; i++)
		printf("%d ", i);
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void Setmine(char board[ROWS][COLS], int row, int col)//布置雷
{
	int count = counts;
	int x, y;
	while (count)
	{
		x = rand() % 9 + 1;//  %9  的范围在0-8，+1之后范围刚刚好1-9；
		y = rand() % 9 + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}

}

int  Getcount(char mine[ROWS][COLS],int x,int y )
{
	return mine[x - 1][y] + 
		mine[x - 1][y - 1] + 
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x][y + 1] +
		mine[x + 1][y + 1] + 
		mine[x-1][y + 1] - 8 * '0';
}
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)//排查雷
{
	int x, y;
	int win=0;
	while (win<ROW*COL-counts)
	{
		printf("请输入排查雷的坐标-->");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//坐标是否合法
		{
			//坐标合法
			
			if (mine[x][y] == '1')//1.踩雷
			{
				printf("很遗憾，你被炸死了\n");
				Displayboard(mine, row, col);//打印雷的情况
				break;
			}
			else                 //2.没踩雷		
			{
				//统计此坐标周围有几个雷
				int count=Getcount(mine, x,y);
				show[x][y] = count+'0';//将这个数字转化为字符放进去
				Displayboard(show, row, col);
				win++;
			}
		}
		else
			printf("输入的坐标非法,请从新输入\n");
	}
	if (win == ROW * COL - counts)
		printf("\n\n*****恭喜你排雷成功*****\n\n");
}