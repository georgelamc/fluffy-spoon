#ifndef BLOCK_H
#define BLOCK_H

#include <chrono>
#include <string>

class Block {

    private:
        std::string hash;
        std::string prevHash;
        std::string data {};
        long long timestamp {};

    public:
        Block(const std::string &data, const std::string &prevHash) : data(data), prevHash(prevHash) {
          const auto now = std::chrono::system_clock::now();
          const auto sinceEpoch = now.time_since_epoch();
          timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(sinceEpoch).count();
        }

        std::string getHash() {
            return hash;
        }

};

#endif
