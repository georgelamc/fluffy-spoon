#include "../include/Block.h"
#include "../include/HashUtil.h"

#include <chrono>

Block::Block(const std::string &prevHash, const std::string &data) : prevHash(prevHash), data(data) {
    hash = std::string(64, '1');
}

std::string Block::getPrevHash() const {
    return prevHash;
}

std::string Block::getHash() const {
    return hash;
}

void Block::mine(int difficulty) {
    const auto now = std::chrono::system_clock::now();
    const auto sinceEpoch = now.time_since_epoch();
    long long timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(sinceEpoch).count();

    int nonce{0};
    std::string target(difficulty, '0');
    do {
        std::string input = prevHash + data + std::to_string(timestamp) + std::to_string(nonce);
        hash = HashUtil::hash(input);
        nonce += 1;
    } while (hash.substr(0, difficulty) != target);
}
