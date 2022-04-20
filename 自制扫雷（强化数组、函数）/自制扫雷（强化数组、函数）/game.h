#pragma once
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define counts 80

#include<stdlib.h>
#include<stdio.h>
#include<time.h>

void Initboard(char board[ROWS][ROWS], int rows, int cols, char set);//初始化棋盘函数的声明

void Displayboard(char board[ROWS][COLS], int row, int col);//打印棋盘信息

void Setmine(char board[ROWS][COLS],int row,int col);//布置雷函数

void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//排查雷