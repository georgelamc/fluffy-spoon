#ifndef HASHUTIL_H
#define HASHUTIL_H

#include <string>

#include "Block.h"

class HashUtil {

    public:
        static std::string hash(std::string &input);

};

#endif
