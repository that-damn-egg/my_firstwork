#include <stdio.h>

void menu()
{
    printf("-----------------------\n");
    printf("-----------------------\n");
    printf("------- 1. play -------\n");
    printf("------- 0. exit -------\n");
    printf("-----------------------\n");
    printf("-----------------------\n");
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
			
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误,请重新输入\n");
			break;
		}
	} while (imput);
    return 0;
}