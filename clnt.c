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
       	socklen_t tolen;
	struct sockaddr_un name;
	char buf[1024];

	sock = socket(PF_UNIX, SOCK_DGRAM, 0);
	name.sun_family = PF_UNIX;
	strcpy(name.sun_path, NAME);

	bind(sock, (struct sockaddr *)&name, sizeof(struct sockaddr_un));
	
	strcpy(buf, "This is message from the client");
	tolen = sizeof(struct sockaddr_un);
	sendto(sock, buf, 1024, 0, (struct sockaddr *)&name, tolen);
	unlink(NAME);
	close(sock);
}

