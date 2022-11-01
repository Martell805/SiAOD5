#ifndef SIAOD4_PBBTNODE_H
#define SIAOD4_PBBTNODE_H

#include "iostream"
#include "cstring"
#include "TNode.h"

using namespace std;

class PBBTNode: public TNode {
public:
    PBBTNode(char key_[10], int value_, PBBTNode* parent_);
public:
    void add(char key_[10], int value_);
    PBBTNode* find(char key_[10]);
    PBBTNode* del(char key_[10]);
};


#endif //SIAOD4_PBBTNODE_H
