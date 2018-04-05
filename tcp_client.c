#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define die(e) do{ \
    fprintf(stderr, "Error %d: %s\n", e, strerror(e));\
    exit(EXIT_FAILURE);\
}while(0);

int main(){
    // Creación del socket
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);
    //if(network_socket)
        //die(network_socket);

    // Especificación de una dirección para el socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;
    int connection_status = connect(network_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    //if(connection_status)
        //die(connection_status);

    char server_response[256];
    recv(network_socket, &server_response, sizeof(server_response), 0);
    printf("%s\n", server_response);
    close(network_socket);
    return 0;
}