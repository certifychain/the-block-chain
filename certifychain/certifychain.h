#ifndef CERTIFYCHAIN_H
#define CERTIFYCHAIN_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/ec.h>
#include <openssl/err.h>

// blockchain constants
#define BLOCKCHAIN_BLOCK_SIZE 1024
#define BLOCKCHAIN_TRANSACTION_SIZE 256

// certificate constants
#define CERTIFICATE_SIZE 1024

// function prototypes
void init_blockchain(void);
void add_transaction(uint8_t *transaction, uint32_t transaction_size);
void verify_blockchain(void);

// ECDSA key pair structure
typedef struct {
    EC_KEY *private_key;
    EC_KEY *public_key;
} ECDSA_KeyPair;

// blockchain structure
typedef struct {
    uint32_t block_number;
    uint8_t *transactions;
    uint32_t transaction_count;
    uint8_t *hash;
} Block;

// node structure
typedef struct {
    uint32_t node_id;
    char *node_address;
    uint16_t node_port;
} Node;

#endif // CERTIFYCHAIN_H