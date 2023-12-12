// showip.c -- show IP address for a host given on the command line

#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<netint/in.h>


int main(int argc, char *argv[]) {
  struct addrinfo hints, *res, *p;
  int status;
  char ipstr[INET6_ADDRSTRLEN];

  if(argc != 2){
    fprintf(stderr, "usage: showip hostname\n");
    return 1;
  }
}
