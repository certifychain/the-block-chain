#ifndef BLOCK_H
#define BLOCK_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    uint32_t block_number;
    uint8_t *transactions;
    uint32_t transaction_count;
    uint8_t *hash;
} Block;

Block *create_block(uint32_t block_number, uint8_t *transactions, uint32_t transaction_count);
void add_transaction_to_block(Block *block, uint8_t *transaction);
void calculate_block_hash(Block *block);

#endif // BLOCK_H