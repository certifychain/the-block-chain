#include "blockchain/block.h"
#include "certifychain.h"
#include <openssl/sha.h>

Block *create_block(uint32_t block_number, uint8_t *transactions, uint32_t transaction_count) {
    Block *block = (Block *)malloc(sizeof(Block));
    block->block_number = block_number;
    block->transactions = transactions;
    block->transaction_count = transaction_count;
    block->hash = (uint8_t *)malloc(SHA256_DIGEST_LENGTH);
    return block;
}

void add_transaction_to_block(Block *block, uint8_t *transaction) {
    block->transactions = (uint8_t *)realloc(block->transactions, block->transaction_count + 1);
    block->transactions[block->transaction_count] = transaction;
    block->transaction_count++;
}

void calculate_block_hash(Block *block) {
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, block->transactions, block->transaction_count * BLOCKCHAIN_TRANSACTION_SIZE);
    SHA256_Final(block->hash, &sha256);
}