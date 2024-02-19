# include "block.h"

struct Block {
    int index;
    time_t timestamp;
    char data[BLOCK_DATA_SIZE];
    char previousHash[32];
    char hash[32];
};

void calculateHash(struct Block *block, char *hash){

}

struct Block* createBlock(int index, char *data, char *previousHash) {
    struct Block *block = (struct Block*)malloc(sizeof(struct Block));

    block->index = index;
    block->timestamp = time(NULL);
    strncpy(block->data, data, BLOCK_DATA_SIZE - 1);
    strncpy(block->previousHash, previousHash, 32);

    calculateHash(block, block->hash);

    return block;
}
