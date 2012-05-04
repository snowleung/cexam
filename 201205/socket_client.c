#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#define BUFF_SIZE 32

int main(){
  int port = 91111;
  char *ip_addr = "127.0.0.1";
  int client_sock;
  struct sockaddr_in server_addr;
  char *buff = "hello!";
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(ip_addr);
  server_addr.sin_port = htons(port);
  
  client_sock = socket(PF_INET,SOCK_STREAM,IPPROTO_TCP);
  connect(client_sock,(struct sockaddr *) &server_addr,sizeof(server_addr));
  send(client_sock,buff,strlen(buff),0);
}
