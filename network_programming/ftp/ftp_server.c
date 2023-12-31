// Let's make a simple ftp server
// 1. Start 
// 2. Declare the variable for the socket
// 3. Specify the family, protocol, IP addr and port num
// 4. Create a socket using socket() function
// 5. Bind the IP address and the PORT number
// 6. Listen and accept the client's request for the connection
// 7. Establish the connection with the client
// 8. Close the socket
// 9. Stop

/*
#include<stdio.h>
#include<string.h>
#include<sys/type.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#inlude<unistd.h>
#include<arpa/inet.h>
#include<netdb.h>
*/

#include "headerFiles.h"

#define TCP_PORT 5035
#define MAX 60


/*
 * int socket(int domain, int type, int protocol);
 * socket() simply returns to us a socket descriptor that we can use
 * in later system calls or -1 on error.
 *
 * domain -> Specifies the communication domain in which a socket is to be created
 * type -> type of socket to be created
 * protocol -> particular protocol to be used. Specifying a protocol of 0
 * causes a socket() to use an unspecified default protocol appropriate for 
 * the requested socket type.
 * socket(IPv4 or IPv6, stream or datagram, TCP or UDP);
 */

int main(int argc, char *argv[]){
  int sockfd;

  struct sockaddr_in serv_addr, cli_addr;
  serv_addr.sin_family = AF_INET;
  serv.addr.sin_addr.s_addr = INADDR_ANY;


  // Create a socket
  sockfd=socket(AF_INET, SOCK_STREAM, 0);
  return 0;
}
