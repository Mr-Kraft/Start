#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/*

r目的地
0箱子
I人
X墙
 路
W上
A左
D右
S下
*/

void menu( );
int level 1 ( );
int level 2 ( );
void swap (char*,char*);
int opera(char *p,int *ren,int xzs);
void dituprint ();

void menu ( );
{
        printf("     推箱子\n");
        printf("     1.新游戏              2.选关\n");
        printf("     0.退出\n");
}
void xuanguan()
{
        int choice_level 1;
        while(1)
         {
         printf("请选择关卡: \n")；
         scanf("%d",&choice_level;)
         switch(choice_level)
         {
         case 1:
               level1 ();
               break;
        case 2:
               level2();
               break;
         default:
               printf("输入有误，请重新选择关卡！");
               }
               }
}
void swap(char  *a,char    *b)
{
       system("cls");
       char ch;
       ch=*a;
       *a=*b;
       *b=ch;
}
void dituprint(char *p)
{
     //system("cls");
     for (int   i=0;i<9;i++)
     {
                for(int  j=0;j=9;j<9;j++) 
                     printf("%3c",p[i*9+j]);
                printf("\n");
     }
}
int opera(char *p,int  *ren, int xzs)
{
     dituprint(p);
     while(1)
     { 
         for(int  i=1,panduan=0;i<=xzs;i++)
           {
                      if (p[ren[i]]=='O')
     {
         panduan+=1;
         printf("panduan=%d\n",panduan);
     }
if(panduan==xzs)
    {        
         printf("恭喜过关!");
         getchar();
         return 0;
    }
}
char ch;
printf("你的按键为：");
scanf("%c",ch);
switch(ch)
{
case'w':
      {
           if(p[ren[0]]=='r')
            {
                if(p[ren[0]-9]=='r')
                       {
                           ren[0]-=9;
                           p[ren[0]]='I';
                           p[ren[0]+9]='r';
                           break;
                       }
                       if (p[ren[0]-9]=='x')
                       {
                              printf("人碰到墙了>>>>>");
                              break;
                       }
                       if(p[ren[0]-9]==' ')
                       {
                                   ren[0]-=9;
                                   p[ren[0]]='I';
                                   p[ren[0]-9]='r';
                                   break;
                       }
                       if(p[ren[0]-9]=='O')
                       { 
                            printf（p[ren[0]-9='o']）