#ifndef SIAOD5_DTNODE_H
#define SIAOD5_DTNODE_H

#include "iostream"
#include "cstring"
#include "TNode.h"

using namespace std;

class DTNode: public TNode {
public:
    explicit DTNode(char key_[10], int value_, DTNode* parent_);
protected:
    static long long KeyToInt(const char key_[10]);
public:
    void add(char key_[10], int value_);
    DTNode* find(char key_[10]);
    DTNode* del(char key_[10]);
};


#endif
