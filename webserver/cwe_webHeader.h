#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <wiringPi.h>
#define LED	1	/* GPIO18 */
#define	MOTOR	2	/* GPIO13 */

int ledControl(int gpio, int onoff);
int MoterControl(int gpio, int onoff);

