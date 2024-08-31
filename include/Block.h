#ifndef BLOCK_H
#define BLOCK_H

#include <string>

class Block {

    private:
        std::string prevHash;
        std::string data;
        std::string hash;

    public:
        Block(const std::string &prevHash, const std::string &data);

        std::string getHash();

        void mine(int difficulty);

};

#endif
