#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define TCP_PORT	5100

int led_control(char on_off)
{
	int fd;
	char buf[32];

	memset(buf, 0x00, 32);

	fd = open("/sys/class/gpio/export", O_WRONLY);
	write(fd, "18", 3);
	close(fd);

	memset(buf, 0x00, 32);
	fd = open("/sys/class/gpio/gpio18/direction", O_WRONLY);
	write(fd, "out", 4);
	close(fd);

	memset(buf, 0x00, 32);
	fd = open("/sys/class/gpio/gpio18/value", O_WRONLY);

	if(on_off == '1')
		write(fd, "1", 2);
	else if(on_off == '0')
		write(fd, "0", 2);
	else
		printf("On/Off Error !!");

	close(fd);

	memset(buf, 0x00, 32);
	fd = open("/sys/class/gpio/unexport", O_WRONLY);
	write(fd, "18", 3);
	close(fd);

	return 0;

}

int main(int argc, char* argv[])
{
	int socket_fd;
	socklen_t clen;
	int n;
	struct sockaddr_in client_addr, server_addr;
	char buf[16];

	memset(buf, 0x00, 16);

	if((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0);
	{
		perror("socket()");
		return -1;
	}

	bzero(&server_addr, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(TCP_PORT);

	if(bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
	{
		perror("bind()");
		return -1;
	}

	if(listen(socket_fd, 0) < 0)
	{
		perror("listen()");
		return -1;
	}

	clen = sizeof(client_addr);

	while(1)
	{
		int client_sockfd = accept(socket_fd, (struct sockaddr *)&client_addr, &clen);

		printf("Client is connected  : %s\n", inet_ntoa(client_addr.sin_addr));

		if((n = read(socket_fd, buf, 2)) <= 0)
		{
			perror("read()");
		}

		led_control(buf[0]);

		close(client_sockfd);
	}
	close(socket_fd);

	return 0;
}
