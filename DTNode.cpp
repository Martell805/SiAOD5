#include "DTNode.h"

DTNode::DTNode(char key_[10], int value_, DTNode *parent_): TNode(key_, value_, parent_) {}

void DTNode::add(char key_[10], int value_) {
    long long newKey = DTNode::KeyToInt(key_);
    long long curKey = DTNode::KeyToInt(this->key);

    if(newKey < curKey) {
        if(this->left == nullptr) {
            this->setLeft(new DTNode(key_, value_, this));
            return;
        }

        this->left->add(key_, value_);
        return;
    }

    if(this->right == nullptr) {
        this->setRight(new DTNode(key_, value_, this));
        return;
    }

    this->right->add(key_, value_);
}

DTNode *DTNode::find(char key_[10]) {
    long long newKey = DTNode::KeyToInt(key_);
    long long curKey = DTNode::KeyToInt(this->key);

    if(newKey == curKey) {
        return this;
    }

    if(newKey < curKey) {
        if(this->left == nullptr) {
            return nullptr;
        }
        return (DTNode*)this->left->find(key_);
    }

    if(this->right == nullptr) {
        return nullptr;
    }
    return (DTNode*)this->right->find(key_);
}

DTNode *DTNode::del(char key_[10]) {
    return nullptr;
}

long long DTNode::KeyToInt(const char key_[10]) {
    long long result = 0;

    for(int q = 9; q > 0; q--) {
        result = result * 10 + (key_[q] - '0');
    }

    return result;
}
