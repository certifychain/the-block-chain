#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

typedef struct {
    int data;
} HashContent;

typedef struct {
    HashContent content;
    char previous[SHA_DIGEST_LENGTH*2 + 1];
    char current[SHA_DIGEST_LENGTH*2 + 1];
} Block;

void sha1_digest(const void *data, size_t len, char *digest) {
    SHA_CTX sha_ctx;
    SHA1_Init(&sha_ctx);
    SHA1_Update(&sha_ctx, data, len);
    SHA1_Final((unsigned char*)digest, &sha_ctx);
}

Block new_block(int data, const char *previous) {
    HashContent content = { data };

    size_t content_size = sizeof(content);
    char *bytes = malloc(content_size);
    memcpy(bytes, &content, content_size);

    char digest[SHA_DIGEST_LENGTH*2 + 1];
    sha1_digest(bytes, content_size, digest);

    free(bytes);

    Block new_block;
    new_block.content = content;
    strcpy(new_block.previous, previous);
    strcpy(new_block.current, digest);

    return new_block;
}

const char* get_current(const Block *block) {
    return block->current;
}

const HashContent* get_content(const Block *block) {
    return &block->content;
}

void main(){}
