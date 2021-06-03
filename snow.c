#include <stdio.h>
main(void)
{
    int r;
    printf("请输入降雪量r:\n");
    scanf("%d",&r);
    printf("降雪量r = %d:  ",r);
    if(r<1.0)
    printf("小雪\n")；
    else if(r<3.0||r>1.0) printf("中雪\n");
    else if(r<6.0||r>3.0) printf("大雪\n");
    else printf("暴雪\n");
}