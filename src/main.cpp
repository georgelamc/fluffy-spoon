#include <iostream>
#include "../include/Block.h"
#include "../include/HashUtil.h"

int main() {
    HashUtil hu;
    std::string x { "testing" };
    hu.hash(x);
    return 0;
}
