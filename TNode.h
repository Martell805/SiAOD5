#ifndef SIAOD5_TNODE_H
#define SIAOD5_TNODE_H

#include "iostream"
#include "cstring"

using namespace std;

class TNode {
protected:
    int children = 0;
    TNode *parent = nullptr;
    TNode *left = nullptr;
    TNode *right = nullptr;
    char key[10]{};
    int value;
public:
    explicit TNode(char key_[10], int value_, TNode* parent_);
public:
    [[nodiscard]] int getChildren() const;
    [[nodiscard]] TNode *getParent() const;
    void setParent(TNode *parent_);
    [[nodiscard]] TNode *getLeft() const;
    void setLeft(TNode *left_);
    [[nodiscard]] TNode *getRight() const;
    void setRight(TNode *right_);
    [[nodiscard]] char* getKey() const;
    [[nodiscard]] int getValue() const;
    void setValue(int value_);
public:
    TNode* getRightmost();
    TNode* getLeftmost();
public:
    virtual void add(char key_[10], int value_) = 0;
    virtual TNode* find(char key_[10]) = 0;
    virtual TNode* del(char key_[10]) = 0;
    void print(int tabLevel = 0) const;
};

#endif //SIAOD5_TNODE_H