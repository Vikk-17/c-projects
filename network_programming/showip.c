/*
 * showip.c -- show IP addresses for a host given on the command line
 */

#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<netinet/in.h>


/*
  #include<netdb.h>
  
  struct addrinfo{
    int ai_flags;
    int ai_family;
    int ai_socktype;
    int ai_protocol;
    size_t ai_addrlen;
    char* ai_canonname;
    struct sockaddr *ai_addr;
    struct addrinfo *ai_next;
  }
 */


int main(int argc, char *argv[]){
    struct addrinfo hints, *res, *p;
    int status;
    char ipstr[INET6_ADDRSTRLEN];

    // if command line args is not of length 2 
    if(argc != 2){
        fprintf(stderr, "usage: showip hostname\n");
        return 1;
    }

    // memset(ptr, x, n); -> is used to fill a block of memory with a particular value.
    // ptr -> starting address of memory to be filled
    // x -> value to be filled
    // n -> number of bytes to be filled starting from ptr to be filled
    memset(&hints, 0, sizeof hints);

    hints.ai_family = AF_UNSPEC; // AF_INET or AF_INET6 to force version
    hints.ai_socktype = SOCK_STREAM;

    status = getaddrinfo(argv[1], NULL, &hints, &res);
  
    if(status !=0){
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return 2;
    }

    printf("IP address for %s:\n\n", argv[1]);

    // stuck in infinite loop
    for(p=res; p!=NULL; p->ai_next){

        void *addr;
        char *ipver;

        // get the pointer to the address itself.
        // different fields in IPv4 and IPv6:
        if(p->ai_family == AF_INET) { // IPv4
            struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
            addr = &(ipv4->sin_addr);
            ipver = "IPv4";
        } else { // IPv6
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
            addr = &(ipv6->sin6_addr);
            ipver = "IPv6";
        }
        
        // convert the IP to a string and print it:
        inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);
        printf("  %s: %s\n", ipver, ipstr);
    }
    
    freeaddrinfo(res); // free the linked list

    return 0;
}
