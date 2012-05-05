#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#define BACKLOG 5
#define MAXBUFF_SIZE 32
#define BUFFSIZE 32

void Die(char *mess) { perror(mess); exit(1); }
void HandleClient(int sock) {
  char buffer[BUFFSIZE];
  int received = -1;
  /* Receive message */
  if ((received = recv(sock, buffer, BUFFSIZE, 0)) < 0) {
    Die("Failed to receive initial bytes from client");
  }
   /* fprintf(stdout,"%s",buffer); */
   /* fflush(stdout); */
  /* Send bytes and check for more incoming data in loop */
  while (received > 0) {
    /* Send back received data */
    if (send(sock, buffer, received, 0) != received) {
      Die("Failed to send bytes to client");
    }
    /* Check for more data */
    if ((received = recv(sock, buffer, BUFFSIZE, 0)) < 0) {
      Die("Failed to receive additional bytes from client");
    }
  }
  close(sock);
}
int main(){

  int port = 91111;
  //  char *ip_addr = "127.0.0.1";
  int server_sock,clientsock;
  struct sockaddr_in addr,echoclient;
  char buff[MAXBUFF_SIZE];


  if ((server_sock = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP))<0) exit(1);
  
  memset(&addr,0,sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(port);
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  

  if (bind(server_sock, (struct sockaddr *) &addr,sizeof(addr))<0) exit(1);

  if (listen(server_sock,BACKLOG)<0) exit(1);
  //  int echo_len;

      /* Run until cancelled */
  /* while (1) { */
  /*   unsigned int clientlen = sizeof(echoclient); */
  /*   /\* Wait for client connection *\/ */
  /*   if ((clientsock = */
  /* 	 accept(server_sock, (struct sockaddr *) &echoclient, */
  /* 		&clientlen)) < 0) { */
  /*     Die("Failed to accept client connection"); */
  /*   } */
  /*   fprintf(stdout, "Client connected: %s\n", */
  /* 	    inet_ntoa(echoclient.sin_addr)); */
  /*   HandleClient(clientsock); */
  /* } */
  int echo_len;
  while(1){
    //    fprintf(stdout,"%s","ok");
    unsigned int client_len = sizeof(echoclient);
    if ((clientsock = accept(server_sock,(struct sockaddr *) &echoclient,&client_len))<0) exit(1);
    //    fprintf(stderr,"%s",inet_ntoa(echoclient.sin_addr));
    echo_len = recv(clientsock,buff,MAXBUFF_SIZE,0);
    buff[echo_len+1] = '\0';
    //    fprintf(stdout,"ok%s",buff);
    fprintf(stdout,"%s\n",buff);
    close(clientsock);

  }

    /* unsigned int client_len = sizeof(client_addr); */
    /* client_sock = accept(server_sock,(struct sockaddr *) &client_addr,&client_len); */
    /* echo_len = recv(client_sock,buff,MAXBUFF_SIZE,0); */
    /* buff[echo_len+1] = '\0'; */
    /* fprintf(stdout,"%s",buff); */
}
