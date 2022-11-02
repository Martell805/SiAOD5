#include "SPNode.h"

SPNode::SPNode(char key_[10], int value_, SPNode* parent_) : DTNode(key_, value_, parent_){}

SPNode* SPNode::find(char key_[10]) {
    long long reqKey = SPNode::KeyToInt(key_);
    long long curKey = SPNode::KeyToInt(this->key);

    if(curKey == reqKey){
        return this;
    }

    if(curKey > reqKey) {
        auto* leftChild = (SPNode*)this->left;

        if(leftChild == nullptr) {
            return nullptr;
        }

        if (SPNode::KeyToInt(leftChild->getKey()) == reqKey) {
            auto *result = leftChild;
            this->rightRotate();
            return result;
        }

        if (leftChild->getLeft() != nullptr and SPNode::KeyToInt(leftChild->getLeft()->getKey()) == reqKey) {
            auto *result = (SPNode *) leftChild->getLeft();

            this->rightRotate();
            leftChild->rightRotate();
            return result;
        }

        if (leftChild->getRight() != nullptr and SPNode::KeyToInt(leftChild->getRight()->getKey()) == reqKey) {
            auto *result = (SPNode *) leftChild->getRight();

            leftChild->leftRotate();
            this->rightRotate();
            return result;
        }

        return leftChild->find(key);
    }

    if(curKey < reqKey) {
        auto* rightChild = (SPNode*)this->right;

        if(rightChild == nullptr) {
            return nullptr;
        }

        if (SPNode::KeyToInt(rightChild->getKey()) == reqKey) {
            auto *result = rightChild;
            this->leftRotate();
            return result;
        }

        if (rightChild->getLeft() != nullptr and SPNode::KeyToInt(rightChild->getLeft()->getKey()) == reqKey) {
            auto *result = (SPNode *) rightChild->getLeft();

            rightChild->rightRotate();
            this->leftRotate();

            return result;
        }

        if (rightChild->getRight() != nullptr and SPNode::KeyToInt(rightChild->getRight()->getKey()) == reqKey) {
            auto *result = (SPNode *) rightChild->getLeft();

            this->leftRotate();
            rightChild->leftRotate();
            return result;
        }

        return rightChild->find(key);
    }

    return nullptr;
}

void SPNode::rightRotate() {
    if(this->left == nullptr) {
        return;
    }

    auto *leftChild = (SPNode*)this->left;

    if(this->parent != nullptr) {
        if(this->parent->getLeft() == this) {
            this->parent->setLeft(leftChild);
        } else {
            this->parent->setRight(leftChild);
        }
    } else {
        leftChild->setParent(nullptr);
    }

    this->setLeft(leftChild->getRight());

    leftChild->setRight(this);
}

void SPNode::leftRotate() {
    if(this->right == nullptr) {
        return;
    }

    auto *rightChild = (SPNode*)this->right;

    if(this->parent != nullptr) {
        if(this->parent->getLeft() == this) {
            this->parent->setLeft(rightChild);
        } else {
            this->parent->setRight(rightChild);
        }
    } else {
        rightChild->setParent(nullptr);
    }

    this->setRight(rightChild->getLeft());
    rightChild->setLeft(this);
}
