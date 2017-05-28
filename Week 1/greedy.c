#include <stdio.h>
#include <math.h>

int main(void){
  float f;
  	do
  	{
  	   printf(" How much change is owed? ");
       scanf("%f", &f);
  	} while (f <= 0);

    int coins = 0;
    int change = round(f * 100);

  	while (change > 0)
  	{
      if (change >= 25)
	    {
	        change -= 25;
	    }
	    else if (change >= 10)
	    {
	        change -= 10;
	    }
	    else if (change >= 5)
	    {
	        change -= 5;
	    }
	    else
	    {
	        change -= 1;
	    }
	    coins++;
  	}


  	printf("%i\n", coins);
}
