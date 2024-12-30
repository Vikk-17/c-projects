/**
* getaddrinfo() - prepare to launch!
*/

#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>

/**
 * stuct sockaddr
*/ 
struct sockaddr{
    unsigned short sa_family; // address family, AF_xxx
    // basically destination address and port number of the socket
    // 8 bytes for address and 5 bytes for port and 1 byte for NULL (assumption)
    char sa_data[14]; // 14 bytes of protocol address
};

// "in" for internet
struct in_addr{
    uint32_t s_addr; // that's a 32-bit int (4 bytes)
};

struct in6_addr{
    unsigned char s6_addr[16];
};

struct sockaddr_in {
    short int sin_family; // Address family
    unsigned short int sin_port; // port number
    struct in_addr sin_addr; // Internet address
    unsigned char sin_zero[8]; // same size as struct sockaddr
};

struct sockaddr_in6{
    u_int16_t sin6_family;
    u_int16_t sin6_port;
    u_int32_t sin6_flowinfo;
    struct in6_addr sin6_addr;
    u_int32_t sin6_scope_id;
};

/**
 * struct addrinfo
*/ 
struct addrinfo{
    int ai_flags; // AI_PASSIVE, AI_CANONNAME, AI_ADDRCONFIG, AI_V4MAPPED etc.
    int ai_family; // AF_INET, AF_INET6, AF_UNSPEC
    int ai_socktype; // SOCK_STREAM, SOCK_DGRAM
    int ai_protocol; // use 0 for "any"
    size_t ai_addrlen; // size of ai_addr in bytes
    struct sockaddr *ai_addr; // struct sockaddr_in or _in6
    char *ai_canonname; // full canonical hostname:
    struct addrinfo *ai_next; // linked list, next node
};


int getaddrinfo(
    const char *node, // -> "www.example.com"
    const char *service, // -> "http" or port number
    const struct addrinfo *hints,
    struct addrinfo **res
);
