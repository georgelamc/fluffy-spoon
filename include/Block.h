#ifndef BLOCK_H
#define BLOCK_H

#include <string>

class Block {

    private:
        std::string hash;
        std::string prevHash;
        std::string data;
        long long timestamp;

    public:
        Block(const std::string &prevHash, const std::string &data);

        std::string getHash() const;

};

#endif
