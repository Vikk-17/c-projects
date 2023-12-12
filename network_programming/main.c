#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>

int getaddrinfo (const char *node, // eg. "www.example.com" or IP
                 const char *service, // eg. "http" or port number
                 const struct addrinfo *hints,
                 struct addrinfo **res);


/*
 * The node parameter is the host name to connect to, or an IP address
 * Ther service parameter, which can be a port number, like 80 or the name of the particular service
 like "http" or "ftp" or "telnet" or "smtp" or whatever.
 
 * Finally the hints parameter points to a struct addrinfo that you have already filled out
 with relevent information.
*/

/*
 * Here is a sample call if you are a server who wants to listen on your host's ip addr 
 port 3490. Note that this does not actually do any listening or network setup.
 It merely sets up structures we'll use later:
 */ 

int status;
struct addrinfo hints;
struct addrinfo *servinfo; // will point to the results


memset(&hints, 0, sizeof hints); // make sure the struct is empty
hints.ai_family = AF_UNSPEC; // don't care IPv4 or IPv6
hints.ai_socktype = SOCK_STREAM; // TCP stream sockets
hints.ai_flags = AI_PASSIVE; // fill in my IP for me 

if ((status = getaddrinfo(NULL, "3490", &hints, &servinfo)) != 0){
  fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
  exit(1);
}

// servinfo now points to a linked list of 1 or more struct addrinfos
//
// ... do everything until you don't need servinfo anymore

freeaddrinfo(servinfo); // free the linked-list


/*-------------------------------------------------------*/
int status;
struct addrinfo hints; 
struct addrinfo *servinfo; // will point to the results

memset(&hints, 0, sizeof hints); // make sure the struct is empty
hints.ai_family = AF_UNSPEC;
hints.ai_socktype = SOCK_STREAM; // TCP stream sockets

// get ready to connect
status = getaddrinfo("www.example.net", "3490", &hints, &servinfo);

// servinfo now points to a linked list of 1 or more struct addrinfo
//
// etc.
//
// servinfo is a linked list with all kinds of address information.
// Let's write a quick demo program to show off the information. this
// Short program will ptint the IP address for whatever host you specify
// on the command line.

/*
 ** showip.c -- show IP address for a host given on the command line
 */
