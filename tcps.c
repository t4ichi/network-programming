#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
//#ifdef WIN32
//#include <windows.h>
//#include <winsock.h>
//#define exit(__Z) WSACleanup();exit(__Z)
//#define close(__Z) closesocket(__Z);
//#else
//#include <sys/types.h>
#include <sys/socket.h>
//#include <netinet/in.h>
#include <arpa/inet.h>
//#endif
#define BUFSIZE 2048
void main()
{
	struct sockaddr_in client, server;
	int s, rs, len, i, n;
	char buf[BUFSIZE];//文字列を管理する
#ifdef WIN32
	WSADATA wsaData;
	WSAStartup(0x0101, &wsaData);
#endif
	s = socket(AF_INET, SOCK_STREAM, 0);//ソケットを作成する
	memset((char *)&server, 0, sizeof(server));//中身を0で初期化する
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_port	= htons(52999);

	bind(s, (struct sockaddr *)&server, sizeof(server));
	listen(s, 1);
	len= sizeof(client);
	rs = accept(s, (struct sockaddr *) &client, &len);//rsという別のポートを作成する
	send(rs,"\nHello\n\n",8, 0);
	while ((n = recv(rs, buf, BUFSIZE, 0)) > 0) {
		//小文字を大文字に変換する
		// for(i=0; i < n; ++i)
		// 	buf[i] = toupper(buf[i]);
		// send(rs,"Masa -> ",8, 0);
		// send(rs, buf, n, 0);

		//計算プログラム
		int a = 0;
		int b = 0;
		char c;
		// + 1 2
		sscanf(buf,"%c %d %d",&c,&a,&b);
		int ans = 0;
		if(c == '+'){
			ans = a + b;
		}
		else if(c == '*'){
			ans = a * b;
		}
		else if(c == '-'){
			ans = a - b;
		}
		else if(c == '/'){
			ans = a / b;
		}
		else{
			ans = 0;
		}

		sprintf(buf,"a %c b =  %d\n\n",c,ans);
		send(rs, buf,strlen(buf), 0);

		if(buf[0]=='Q') break;
	}
	close(rs);
	close(s);
	exit(0);
}

