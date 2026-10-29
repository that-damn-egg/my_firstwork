#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2
#define MINE_COUNT 10



void InitBoard(char Board[ROWS][COLS], int r, int c, char set)//初始化棋盘
{
	int i = 0;
	int j = 0;
	for (i = 0;i < r;i++)
	{
		for (j = 0;j < c;j++)
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
	for (j = 0;j <= c;j++)
	{
		printf("%d ", j);
	}printf("\n");
		for (i = 1;i <= r;i++)
	{ 
			printf("%d ", i);
			for (j = 1;j <= c;j++)
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
size_t GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] + mine[x - 1][y - 1] + mine[x + 1][y - 1] +
		mine[x + 1][y] + mine[x + 1][y + 1] + mine[x - 1][y + 1] +
		mine[x][y - 1] + mine[x - 1][y + 1] - 8 * '0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int r, int c)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < r*c-MINE_COUNT)
	{
		printf("请输入要排查的坐标\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= r && y >= 1 && y <= c)
		{
			if (show[x][y] == '*')
			{
				if (mine[x][y] == '1')
				{
					printf("die\n");
					DisplayBoard(mine, ROW, COL);
					DisplayBoard(show, ROW, COL);
					break;
				}
				else
				{
					size_t count = GetMineCount(mine, x, y);
					show[x][y] = (char)count + '0';
					DisplayBoard(show, ROW, COL);
					win++;
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
	char mine[ROWS][COLS];//布置存放雷的棋盘
	char show[ROWS][COLS];//布置查出雷的信息
	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');//mine数组开始全是‘0’
	InitBoard(show, ROWS, COLS, '*');
	
	
	 DisplayBoard(show, ROW, COL);
	

	// DisplayBoard(mine, ROW, COL);

	 SetMine(mine, ROW, COL);//布置雷
	//isplayBoard(mine, ROW, COL);新的

	 FindMine(mine,show, ROW, COL);

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
	do {
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