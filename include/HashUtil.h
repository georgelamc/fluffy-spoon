#ifndef HASHUTIL_H
#define HASHUTIL_H

#include <iomanip>
#include <iostream>
#include <openssl/sha.h>
#include <sstream>
#include <string>

class HashUtil {

    public:
        std::string hash(std::string &input) {
			unsigned char hash[SHA256_DIGEST_LENGTH];
			SHA256(reinterpret_cast<const unsigned char *>(input.c_str()), input.length(), hash);

            std::ostringstream oss;
            for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
                oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(hash[i]);
            }

            return oss.str();
        }

};

#endif
