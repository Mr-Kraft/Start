#include <stdio.h>

int main( )
{
      double fahr,celcious;
      int lower,upper,step;
      lower = 0;
      upper = 300;
      step = 20;
      
      printf("   f      c\n");
      while(fahr <= upper)
      {
          celcious = (5.0/9.0) * (fahr - 32);
          printf("%-3.0f  %9.2f\n",fahr,celcious);
      }
}