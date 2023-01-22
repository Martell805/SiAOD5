#ifndef SIAOD5_DTNODE_H
#define SIAOD5_DTNODE_H

#include "iostream"
#include "cstring"

using namespace std;

class DTNode {
protected:
    DTNode *parent = nullptr;
    DTNode *left = nullptr;
    DTNode *right = nullptr;
    char key[10]{};
    int value;
protected:
    static long long KeyToInt(const char key_[10]);
public:
    explicit DTNode(char key_[10], int value_, DTNode* parent_ = nullptr);
public:
    [[nodiscard]] DTNode *getParent() const;
    void setParent(DTNode *parent_);
    [[nodiscard]] DTNode *getLeft() const;
    void setLeft(DTNode *left_);
    [[nodiscard]] DTNode *getRight() const;
    void setRight(DTNode *right_);
    [[nodiscard]] char* getKey() const;
    [[nodiscard]] int getValue() const;
    void setValue(int value_);
    DTNode* getRoot();
public:
    DTNode* getRightmost();
    DTNode* getLeftmost();
public:
    void add(char key_[10], int value_);

    virtual DTNode* find(char key_[10]);
    DTNode* del(char key_[10]);
    void print(int tabLevel = 0) const;
};

#endif //SIAOD5_DTNODE_H