#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define NAME "socket"

int main()
{
	int sock;
       	socklen_t fromlen;
	struct sockaddr_un name, from;
	char buf[1024];

	unlink(NAME);

	sock = socket(PF_UNIX, SOCK_DGRAM, 0);
	name.sun_family = PF_UNIX;
	strcpy(name.sun_path, NAME);
	bind(sock, (struct sockaddr *)&name, sizeof(struct sockaddr_un));
	printf("socket -> %s\n", NAME);
	
	fromlen = sizeof(struct sockaddr_un);
	recvfrom(sock, buf, 1024, 0, (struct sockaddr *)&from, &fromlen);
	printf(" -> %s\n", buf);
	unlink(NAME);
	close(sock);
}
