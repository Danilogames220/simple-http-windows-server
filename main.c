#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include "renderfile.h"

int server;

void initServer(void); 

int main(void) {
	WSADATA wsaData;
    	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
    		printf("WSAStartup failed.\n");
        return 1;
   	}
	//------------------------------------server stuff begins here

	initServer();

	int client;

	while (1) {
		char buffer[1024];
		char * index = renderFile("index.html");

    		char thing[4048] = "HTTP/1.0 200 OK\r\nContent-Type: text/html\r\n\r\n"; //send anything
		char * aa = strcat(thing, index); //i had no name for this :/
		strcat(aa, "\r\n");

		client = accept(server, NULL, NULL);

		recv(client, buffer, 1024, 0);
		printf("\n%s\n", buffer);
		send(client, thing, strlen(thing), 0);
		
		/*if (strstr(buffer, "message")) {
			printf("the frontend sended a message\n");
		}*/
		if (strstr(buffer, "POST")) { // handle POST request
			char *messageStart = strstr(buffer, "\r\n\r\n") + 4;

			char *messageEnd = strchr(messageStart, ';');
			if (messageEnd) {
               		 	*messageEnd = '\0'; //remove the semicolon and whatever is after it
            		}
			
			printf("Message from frontend: %s\n", messageStart);
		}
		if (strstr(buffer, "GET")) { // handle GET request
			char *token;
			token = strtok(buffer, " "); 
			token = strtok(NULL, " "); // we only need the second token

			printf("GET request: %s\n", token);
		}
		closesocket(client);
		free(index);
	}
	closesocket(server);
	
	WSACleanup();
	return 0;
}

void initServer(void) {
	const int port = 21842;
	server = socket(AF_INET, SOCK_STREAM, 0); 

	struct sockaddr_in serveraddress;
	serveraddress.sin_family = AF_INET;
	serveraddress.sin_port = htons(21842);
	serveraddress.sin_addr.s_addr = inet_addr("192.168.1.3");

	bind(server, (struct sockaddr *) &serverAddress, sizeof(serverAddress));

	listen(server, 5);

	printf("> server working on http://192.168.1.3:%d/\n", port);
	/*printf("> server workin' on localhost, port:%d\n", port);
	printf("> btw http://localhost:%d/ or http://127.0.0.1:%d/ cuz ik u forgot about is :)\n\n", port, port);*/

}
