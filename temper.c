#include <stdio.h>

int main( )
{
      int fahr,celcious;
      int lower,upper,step;
      lower = 0;
      upper = 300;
      step = 20;
      fahr = lower;

      while(fahr <= upper) 
      {
          celcious =5 * (fahr - 32) / 9;
          printf("%d  %d\n",fahr,celcious);
          fahr = fahr + 20;
      }
}