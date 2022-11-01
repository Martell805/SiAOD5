#include "PBBTNode.h"

PBBTNode::PBBTNode(char key_[10], int value_, PBBTNode* parent_) : TNode(key_, value_, parent_){}

void PBBTNode::add(char key_[10], int value_) {
    if (this->left == nullptr) {
        this->setLeft(new PBBTNode(key_, value_, this));
        return;
    }

    if (this->right == nullptr) {
        this->setRight(new PBBTNode(key_, value_, this));
        return;
    }

    if (this->left->getChildren() <= this->right->getChildren()) {
        this->left->add(key_, value_);
    } else {
        this->right->add(key_, value_);
    }
}

PBBTNode* PBBTNode::find(char key_[10]) {
    if(strcmp(this->key, key) == 0){
        return this;
    }

    PBBTNode* answerLeft = nullptr;
    if(this->left != nullptr){
        answerLeft = (PBBTNode*)this->left->find(key_);
    }

    PBBTNode* answerRight = nullptr;
    if(this->left != nullptr){
        answerRight = (PBBTNode*)this->right->find(key_);
    }

    return max(answerLeft, answerRight);
}

PBBTNode* PBBTNode::del(char key_[10]) {
    return nullptr;
}

