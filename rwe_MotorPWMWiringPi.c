#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>

int motorControl(int gpio)
{
   int i;

   pinMode(gpio, OUTPUT) ;            /* Pin의 모드 설정 */
	
	int status;
	int initialValue = 50;
	int pwmRange = 100;
	status = softPwmCreate (gpio, initialValue, pwmRange) ;
   
   if(status != 0){
      perror("Can't setup softPwmCreate!");
      return -1;
   }

   for (i = 10; i <= 100; i=i+5) {
      softPwmWrite (gpio, i) ;            /* HIGH(1) 값을 출력 : 모터 켜기 */
      delay(1000);                               /* 1초(1000ms) 동안 대기 */
	  printf("motor speed : %d \n", i);
   };

   digitalWrite(gpio, LOW) ;            /* HIGH(1) 값을 출력 : 모터 켜기 */
   return 0;
}

int main(int argc, char** argv)
{
   int gno;

   if(argc < 2) {
      printf("Usage : %s GPIO_NO\n", argv[0]);
      return -1;
   }
   gno = atoi(argv[1]);

   wiringPiSetup(); 
   motorControl(gno);

   return 0;
}