#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <optional>
#include <vector>

#include "Block.h"


class BlockChain {

    private:
        std::vector<Block> chain;

        int difficulty;

    public:
        BlockChain();

        std::optional<Block> getLastBlock() const;

        int getDifficulty() const;

        void addBlock(const Block &block);

        bool validateChain() const;

};

#endif
