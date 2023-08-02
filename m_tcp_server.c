#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifdef WIN32
#include <windows.h>
#include <winsock.h>
#define exit(__Z) WSACleanup();exit(__Z)
#define close(__Z) closesocket(__Z);
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#endif
#define BUFSIZE 2048

char buf[BUFSIZE];  //  dynamic allocation に変えなければいけません

void pthread(int rs) {
	int i,n;
        printf("%d\n",rs);
	send(rs,"\nHello\n\n",8, 0);
	while ((n = recv(rs, buf, BUFSIZE, 0)) > 0) {
		for(i=0; i< n; ++i)
			buf[i] = toupper(buf[i]);
		send(rs,"Masa -> ",8, 0);
		send(rs, buf, n, 0);
		if(buf[0]=='Q') break;
	}
	//close(rs);
}

int main()
{
	pthread_t t1;
	struct sockaddr_in client, server;
	int s, rs, len, i, n;
#ifdef WIN32
	WSADATA wsaData;
	WSAStartup(0x0101, &wsaData);
#endif
	s = socket(AF_INET, SOCK_STREAM, 0);
	memset((char *)&server, 0, sizeof(server));
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port	= htons(42999);

	bind(s, (struct sockaddr *)&server, sizeof(server));
	listen(s, 1);
	len= sizeof(client);
	while(1) {
	  rs = accept(s, (struct sockaddr *) &client, &len);
          printf("<<<>>>\n");
          printf("%d\n",rs);
 	  pthread_create(&t1,NULL,(void *)pthread,(void *)rs);
	}
        //close(s);
	return 0;
}
