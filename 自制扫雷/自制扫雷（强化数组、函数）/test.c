#define _CRT_SECURE_NO_WARNINGS

#include"game.h"

void game()
{
	//雷的位置信息存储
	//1.布置好的雷的信息 
	char mine[ROWS][COLS] = {0};//是大的棋盘

	//2.排查雷
	char show[ROWS][COLS] = { 0 };

	//3.初始化两个数组
	Initboard(mine, ROWS, COLS, '0');//初始化布置雷的信息的数组
	Initboard(show, ROWS, COLS, '*');//初始化排查雷的信息的数组

	//4.打印棋盘
	//Displayboard(mine, ROW, COL);
	//Displayboard(show, ROW, COL);

	//5.布置雷
	Setmine(mine, ROW, COL);
	Displayboard(mine, ROW, COL);
	Displayboard(show, ROW, COL);

	//6.扫雷
	Findmine(mine,show, ROW, COL);
	
}

void menu()//菜单实现
{
	printf("*****************\n");
	printf("****  1.play  ***\n");
	printf("****  0.exit  ***\n");
	printf("*****************\n");
}
void test()
{
	int input;
	srand(( unsigned int)time(NULL));
	do//多次玩游戏
	{
		printf("\n");
		menu();//进入游戏界面打印菜单
		printf("请选择\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//用来实现这个游戏的简易函数
			break;
		case 0:printf("退出游戏");
			break;
		default:printf("输入错误 ，从新选择");
			break;
		}
	} while (input);
}

int main()//主函数放在test.c内，用来测试这个程序
{
	test();//主要测试的核心
	return 0;
}
