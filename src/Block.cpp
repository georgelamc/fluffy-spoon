#include <chrono>

#include "../include/Block.h"
#include "../include/HashUtil.h"

Block::Block(const std::string &prevHash, const std::string &data) : prevHash(prevHash), data(data) {
    const auto now = std::chrono::system_clock::now();
    const auto sinceEpoch = now.time_since_epoch();
    timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(sinceEpoch).count();

    std::string input = prevHash + data + std::to_string(timestamp);
    hash = HashUtil::hash(input);
}

std::string Block::getHash() const {
    return hash;
}
