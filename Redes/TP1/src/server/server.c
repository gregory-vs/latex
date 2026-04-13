#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 51511
#define BUFFER_SIZE 1024

int main() {
    int server_fd, client_fd;
    struct sockaddr_in addr;
    char buffer[BUFFER_SIZE];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (struct sockaddr*)&addr, sizeof(addr));

    listen(server_fd, 1);
    printf("Servidor esperando conexão na porta %d...\n", PORT);

    client_fd = accept(server_fd, NULL, NULL);
    printf("Cliente conectado!\n");

    recv(client_fd, buffer, BUFFER_SIZE, 0);
    printf("Recebido: %s\n", buffer);

    char* resposta = "Mensagem recebida!";
    send(client_fd, resposta, strlen(resposta), 0);

    close(client_fd);
    close(server_fd);

    return 0;
}