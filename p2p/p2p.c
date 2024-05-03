#include "p2p/p2p.h"
#include "certifychain.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

Node *create_node(uint32_t node_id, char *node_address, uint16_t node_port) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->node_id = node_id;
    node->node_address = node_address;
    node->node_port = node_port;
    return node;
}

void connect_to_node(Node *node) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(node->node_port);
    inet_pton(AF_INET, node->node_address, &server_addr.sin_addr);
    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
}

void send_transaction_to_node(Node *node, uint8_t *transaction) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(node->node_port);
    inet_pton(AF_INET, node->node_address, &server_addr.sin_addr);
    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    send(sockfd, transaction, BLOCKCHAIN_TRANSACTION_SIZE, 0);
    close(sockfd);
}