#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 51511
#define BUFFER_SIZE 1024

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
    printf("Conectado ao servidor!\n");

    char* msg = "Olá servidor!";
    send(sock, msg, strlen(msg), 0);

    recv(sock, buffer, BUFFER_SIZE, 0);
    printf("Servidor respondeu: %s\n", buffer);

    close(sock);

    return 0;
}