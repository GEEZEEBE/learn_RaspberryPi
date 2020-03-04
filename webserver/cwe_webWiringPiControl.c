#include "cwe_webHeader.h"

int ledControl(int gpio, int onoff)
{
	printf("ledControl function : %d, %d\n",gpio,onoff);
    pinMode(gpio, (onoff)?OUTPUT:INPUT) ; 			/* 핀(Pin)의 모드 설정 */
   digitalWrite(gpio, (onoff)?HIGH:LOW); 	/* LED 켜고 끄기 */

    return 0;
}

int MoterControl(int gpio, int onoff)
{
	printf("MoterControl function : %d, %d\n",gpio,onoff);
    pinMode(gpio, (onoff)?OUTPUT:INPUT) ; 			/* 핀(Pin)의 모드 설정 */
   digitalWrite(gpio, (onoff)?HIGH:LOW); 	/* LED 켜고 끄기 */

    return 0;
}
