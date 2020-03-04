include <stdio.h>
#include <wiringPi.h>

#define LED1 1 // BCM_GPIO 18

int main (void)
{
  if (wiringPiSetup () == -1)
  return 1 ;

  pinMode (LED1, OUTPUT) ;

  int i;
  for (i=0;i<=10;i++)
  {
    digitalWrite (LED1, 1) ; // On

    delay (1000) ; // ms

    digitalWrite (LED1, 0) ; // Off

    delay (1000) ;
  }
  return 0 ;
}