#include "crypto/ecdsa.h"
#include "certifychain.h"
#include <openssl/ec.h>
#include <openssl/err.h>

ECDSA_KeyPair *generate_ecdsa_key_pair(void) {
    ECDSA_KeyPair *key_pair = (ECDSA_KeyPair *)malloc(sizeof(ECDSA_KeyPair));
    key_pair->private_key = EC_KEY_new_by_curve_name(NID_secp256k1);
    key_pair->public_key = EC_KEY_new_by_curve_name(NID_secp256k1);
    EC_KEY_generate_key(key_pair->private_key);
    EC_KEY_set_public_key(key_pair->public_key, EC_KEY_get0_public_key(key_pair->private_key));
    return key_pair;
}

void ecdsa_sign(ECDSA_KeyPair *key_pair, uint8_t *message, uint32_t message_size, uint8_t *signature) {
    ECDSA_SIG *sig;
    sig = ECDSA_SIG_new();
    ECDSA_sign(message, message_size, sig, key_pair->private_key);
    int sig_len = i2d_ECDSA_SIG(sig, &signature);
    ECDSA_SIG_free(sig);
}

int ecdsa_verify(ECDSA_KeyPair *key_pair, uint8_t *message, uint32_t message_size, uint8_t *signature) {
    ECDSA_SIG *sig;
    sig = d2i_ECDSA_SIG(NULL, &signature, sizeof(signature));
    int result = ECDSA_verify(message, message_size, sig, key_pair->public_key);
    ECDSA_SIG_free(sig);
    return result;
}