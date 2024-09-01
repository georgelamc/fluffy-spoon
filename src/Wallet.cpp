#include <openssl/pem.h>
#include <openssl/rsa.h>

#include "../include/Wallet.h"

Wallet::Wallet() {
    generateKeyPair();
}

Wallet::~Wallet() {
    EVP_PKEY_free(publicKey);
    EVP_PKEY_free(privateKey);
}

void Wallet::generateKeyPair() {
    BIGNUM *e = BN_new();
    BN_set_word(e, RSA_F4);
    RSA *rsa = RSA_new();
    RSA_generate_key_ex(rsa, 2048, e, nullptr);

    publicKey = EVP_PKEY_new();
    privateKey = EVP_PKEY_new();
    if (EVP_PKEY_assign_RSA(publicKey, RSAPublicKey_dup(rsa)) != 1 || EVP_PKEY_assign_RSA(privateKey, RSAPrivateKey_dup(rsa)) != 1) {
        EVP_PKEY_free(publicKey);
        EVP_PKEY_free(privateKey);
        publicKey = nullptr;
        privateKey = nullptr;
    }

    RSA_free(rsa);
    BN_free(e);
}
