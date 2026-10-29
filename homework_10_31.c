#include <stdio.h>

void meau()
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
    int input = 0;
   do{
    meau();
    printf ("请选择:\n");
    scanf ("%d",&input);
     switch(input)
    {
         case 1:
         printf ("game");
          break;
        case 0:
        printf ("退出游戏\n");
          break;
        default:
          printf ("输入错误，请重新输入\n");
          break;
       }
    }while(input);


    return 0;
      
}
