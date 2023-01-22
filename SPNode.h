#ifndef SIAOD5_SPNODE_H
#define SIAOD5_SPNODE_H

#include "iostream"
#include "cstring"
#include "DTNode.h"

using namespace std;

class SPNode: public DTNode {
public:
    SPNode(char key_[10], int value_, SPNode* parent_ = nullptr);
public:
    void rightRotate();
    void leftRotate();
public:
    SPNode* find(char key_[10]) override;
};


#endif //SIAOD5_SPNODE_H
