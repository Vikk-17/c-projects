#include "headerFiles.h"

#define SERVER_PORT 5035

int main(){
  
  // Declare and define
  int ls = socket(PF_INET, SOCK_STREAM, 0);                   // socket descriptor;
  int s;                    // socket descriptor (reference);
  char buffer[256];         // Data buffer
  char *ptr = buffer;       // Data buffer
  int len = 0;              // Number of bytes to be send or rcv
  int maxLen = sizeof(buffer);  // Maximum number of bytes
  int n=0;                  // Number of bytes in each rcv call
  int waitSize = 16;        // Size of waiting clients
  struct sockaddr_in server_addr; // server address
  struct sockaddr_in client_addr; // client address
  int client_addr_len;        // Length of client address
  

  // create local(server) socket address
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family=AF_INET;
  server_addr.sin_addr.s_addr=htonl(INADDR_ANY); // Default IP
  server_addr.sin_port=htons(SERVER_PORT);  // Default Port 

  // create listen socket
  if(ls < 0 ){
    perror("Error: Listen socket failed!");
    exit(1);
  }
  // bind listen socket to local socket address
  if(bind(ls, &server_addr, sizeof(server_addr)) < 0 ){
    perror("Error: binding failed!");
    exit(1);
  }
  // listen to connection requests
  if(listen(ls, waitSize) < 0){
    perror("Error: listening failed!");
    exit(1);
  }
  // handle the connection
  // Run forever
  for(;;){
    // Accept connection from client
    if(s=accept(ls, &client_addr, &client_addr_len) < 0){
      perror("Error: acepting failed");
      exit(1);
    }
    // Data Transfer section
    while((n=recv(s, ptr, maxLen, 0)) > 0){
      // move pointer along the buffer
      ptr += n;
      // Adjust maximum number of bytes to be receive
      maxLen -= n;
      // Update number of bytes received
      len += n;
    }
    // Send back (echo) all bytes received
    send(s, buffer, len, 0);
    // close the socket
    close(s);
  }
  return 0;
}
