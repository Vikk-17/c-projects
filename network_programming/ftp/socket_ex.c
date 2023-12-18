
// The struct sockaddr holds socket address info for many
// typed of socket


struct sockaddr{
  unsigned short sa_family; // address family, AF_INET/AF_INET6
  char sa_data[14]; // 14 bytes of protocol address
};

/*
* Example = 192.168.1.0
* family = AF_INET
* sa_data[0] = 192 = 0xC0
* sa_data[1] = 168 = 0xA8
* sa_data[2] = 1 = 0x01
* sa_data[3] = 0 = 0x00
*
* Remaining 10 bytes of sa_data typically hold padding, usually
* filled with zeros.
*
* This is rather unwieldy since we don't want to tediously pack
* the address in the sa_date by hand;
*/

/*
* To deal with struct sockaddr, programmers created a parallel
* structure: struct sockaddr_in(in for internet) to be used with
* ipv4
*
* This is important bit: a pointer to struct sockaddr_in can be 
* cast to a pointer to a struct sockaddr and vice-versa.
* So even though connect() wants a struct sockaddr*, we can still
* use a struct sockaddr_in and cast it at the last minute!
*/ 

// (IPv4 only, see struct sockaddr_in6 for IPv6)

 struct sockaddr_in{
     short int           sin_family; // AF_INET
     unsigned short int  sin_port; // Port number
     struct in_addr      sin_addr; //internet address
     unsinged char       sin_zero[8]; // Same size as struct sockaddr
 };

/*
* The structure makes it easy to reference elements of the socket address.
* Note that: siz_zero (which is include to pad the structures to the length
* of a struct sockaddr) should be set to all zeros with the function memset().
* Also notice that sin_family corresponds to sa_family in a struct sockaddr and
* should be set to "AF_INET". Finally the sin_port must be in Network Byte order
* by using the htons().
*/ 
 
// internet address
 struct in_addr{uint32_t s_addr; // that's a 32-bit int (4 bytes)};


 // IPv6

 struct in6_addr{
   unsinged char   s6_addr[16];
 };

 struct sockaddr_in6{
   u_int16_t       sin6_family;  // address family, AF_INET6
   u_int16_t       sin6_port;    // port number, Network byte order
   u_int32_t       sin6_flowinfo;  // IPv6 flow information
   struct          sin6_addr;  // IPv6 address
   u_int32_t       sin6_scope_id;  // Scope ID
 };

