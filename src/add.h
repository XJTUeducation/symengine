#ifndef CSYMPY_ADD_H
#define CSYMPY_ADD_H

#include <unordered_map>

#include "basic.h"

namespace CSymPy {

class Add : public Basic {
private:
    std::unordered_map<int, int> dict;

public:
    Add(std::unordered_map<int, int> &dict);
};

} // CSymPy

#endif
