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

        std::string getPrevHash() const;

        std::string getHash() const;

        void mine(int difficulty);

};

#endif
