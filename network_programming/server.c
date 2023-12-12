#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>

#define PORT 8080

int main(int argc, char const* argv[]){
    int server_fd; // socker descriptor
    int new_socket;
    ssize_t valread; // count of bytes of an error indication

    struct sockaddr_in address;
    int opt = 1;

    // socklen_t -> data byte count, including the cmsghdr
    socklen_t addrlen = sizeof(address);

    char buffer[1024] = {0};
    char* hello = "Hello from the server";

    // Creating the socket file descriptor
    if((server_fd)=socker(AF_INET, SOCK_STREAM, 0) < 0){
        perror("socket failed");
    }

    return 0;
}