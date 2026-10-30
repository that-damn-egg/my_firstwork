#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ROW 9
#define COL 9
#define ROWS ROW + 2    
#define COLS COL + 2
#define MINE_COUNT 10

char mine[ROWS][COLS];     
char show[ROWS][COLS];  



void InitBoard(char Board[ROWS][COLS], int r, int c, char set)  
{
	int i = 0;
	int j = 0;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			Board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int r, int c)
{
	int i = 0;
	int j = 0;
	printf("-------游戏开始----------\n");
	for (j = 0; j <= c; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= r; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= c; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void SetMine(char board[ROWS][COLS], int r, int c)
{
	int count = MINE_COUNT;

	while (count)
	{
		int x = rand() % r + 1;
		int y = rand() % c + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1]+
		mine[x][y - 1] + mine[x][y + 1]+mine[x + 1][y - 1] +
		mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';
}

int OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int r, int c)
{
	int count = 0;
	int opened = 0;
	int i = 0;
	int j = 0;

	if (x < 1 || x > r || y < 1 || y > c)  
	{
		return 0;
	}
	if (show[x][y] != '*')                 
	{
		return 0;
	}
	count = GetMineCount(mine, x, y);
	if (count == 0)
		show[x][y] = ' ';
	else
		show[x][y] = ('0' + count);
	opened = 1;

	if (count == 0)                        
	{
		for (i = -1; i <= 1; i++)
		{
			for (j = -1; j <= 1; j++)
			{
				if (i != 0 || j != 0)
				{
					opened += OpenMine(mine, show, x + i, y + j, r, c);
				}
			}
		}
	}
	return opened;
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int r, int c)
{
	int x = 0;
	int y = 0;
	int win = 0;

	while (win < r * c - MINE_COUNT)
	{
		printf("请输入要排查的坐标: ");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= r && y >= 1 && y <= c)
		{
			if (show[x][y] == '*')
			{
				if (mine[x][y] == '1')
				{
					printf("你被雷炸飞了\n");
					DisplayBoard(mine, r, c);
					DisplayBoard(show, r, c);
					break;
				}
				else
				{
					win += OpenMine(mine, show, x, y, r, c);
					DisplayBoard(show, r, c);
				}
			}
			else
			{
				printf("该坐标已被排查\n");
			}
		}
		else
		{
			printf("输入错误\n");
		}
	}
	if (win == r * c - MINE_COUNT)
	{
		printf("扫雷成功\n");
	}
}

void game()
{	
	InitBoard(mine, ROWS, COLS, '0');   
	InitBoard(show, ROWS, COLS, '*');

	DisplayBoard(show, ROW, COL);

	SetMine(mine, ROW, COL);            

	FindMine(mine, show, ROW, COL);
}

void menu()
{
	printf("----------------------\n");
	printf("----------------------\n");
	printf("-------1.play --------\n");
	printf("-------0.exit --------\n");
	printf("----------------------\n");
	printf("----------------------\n");
}

int main()
{
	
	int imput = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入：\n");
		scanf("%d", &imput);
		switch (imput)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (imput);
	return 0;
}