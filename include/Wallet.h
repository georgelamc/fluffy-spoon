#ifndef WALLET_H
#define WALLET_H

class Wallet {

    private:
        EVP_PKEY *publicKey;
        EVP_PKEY *privateKey;

        void generateKeyPair();

    public:
        Wallet();

        ~Wallet();

};

#endif
