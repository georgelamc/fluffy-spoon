#include "../include/BlockChain.h"

BlockChain::BlockChain() {
    difficulty = 5; // TODO: make it variable depending on the mining speed
}

std::optional<Block> BlockChain::getLastBlock() const {
    if (chain.empty()) {
        return std::nullopt;
    }
    return chain.back();
}

int BlockChain::getDifficulty() const {
    return difficulty;
}

void BlockChain::addBlock(const Block &block) {
    chain.push_back(block);
}

bool BlockChain::validateChain() const {
    for (int i = 1; i < chain.size(); i++) {
        Block prev = chain[i - 1];
        Block curr = chain[i];
        if (curr.getPrevHash() != prev.getHash()) {
            return false;
        }
    }
    return true;
}
