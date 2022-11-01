#include "TNode.h"

TNode::TNode(char key_[10], int value_, TNode* parent_) : value(value_), parent(parent_) {
    strcpy(this->key, key_);
}

int TNode::getChildren() const {
    return children;
}

TNode *TNode::getLeft() const {
    return left;
}

void TNode::setLeft(TNode *left_) {
    this->left = left_;
    this->children++;
    this->left->setParent(this);
}

TNode *TNode::getRight() const {
    return right;
}

void TNode::setRight(TNode *right_) {
    this->right = right_;
    this->children++;
    this->right->setParent(this);
}

char *TNode::getKey() const {
    return (char*)this->key;
}

int TNode::getValue() const {
    return value;
}

void TNode::setValue(int value_) {
    this->value = value_;
}

void TNode::print(int tabLevel) const {
    for(int q = 0; q < tabLevel; q++) cout << ' ';
    cout << key << '(' << value << ')' << endl;
    if(this->left != nullptr) this->left->print(tabLevel + 1);
    if(this->right != nullptr) this->right->print(tabLevel + 1);
}

TNode *TNode::getRightmost() {
    if(this->right == nullptr) {
        return this;
    }

    return this->right->getRightmost();
}

TNode *TNode::getLeftmost() {
    if(this->left == nullptr) {
        return this;
    }

    return this->left->getLeftmost();
}

TNode *TNode::getParent() const {
    return this->parent;
}

void TNode::setParent(TNode *parent_) {
    this->parent = parent_;
}
