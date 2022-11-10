#include "DTNode.h"

DTNode::DTNode(char key_[10], int value_, DTNode* parent_) : value(value_), parent(parent_) {
    strcpy(this->key, key_);
}

DTNode *DTNode::getLeft() const {
    return left;
}

void DTNode::setLeft(DTNode *left_) {
    this->left = left_;

    if(this->left == nullptr) {
        return;
    }

    this->left->setParent(this);
}

DTNode *DTNode::getRight() const {
    return right;
}

void DTNode::setRight(DTNode *right_) {
    this->right = right_;

    if(this->right == nullptr) {
        return;
    }

    this->right->setParent(this);
}

char *DTNode::getKey() const {
    return (char*)this->key;
}

int DTNode::getValue() const {
    return value;
}

void DTNode::setValue(int value_) {
    this->value = value_;
}

void DTNode::print(int tabLevel) const {
    for(int q = 0; q < tabLevel; q++) cout << "| ";
    cout << key << '(' << value << ')' << endl;
    if(this->left != nullptr) this->left->print(tabLevel + 1);
    if(this->right != nullptr) this->right->print(tabLevel + 1);
}

DTNode *DTNode::getRightmost() {
    if(this->right == nullptr) {
        return this;
    }

    return this->right->getRightmost();
}

DTNode *DTNode::getLeftmost() {
    if(this->left == nullptr) {
        return this;
    }

    return this->left->getLeftmost();
}

DTNode *DTNode::getParent() const {
    return this->parent;
}

void DTNode::setParent(DTNode *parent_) {
    this->parent = parent_;
}

void DTNode::add(char key_[10], int value_) {
    long long newKey = DTNode::KeyToInt(key_);
    long long curKey = DTNode::KeyToInt(this->key);

    if(newKey == curKey) {
        this->value = value_;
        return;
    }

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
    long long newKey = DTNode::KeyToInt(key_);
    long long curKey = DTNode::KeyToInt(this->key);

    if (newKey != curKey) {
        DTNode *newNode = this->find(key_);

        if(newNode == nullptr){
            return nullptr;
        }

        return newNode->del(key_);
    }

    if(this->left == nullptr and this->right == nullptr) {
        if(this->parent->getLeft() == this) {
            this->parent->setLeft(nullptr);
        } else {
            this->parent->setRight(nullptr);
        }

        this->setParent(nullptr);
        return this;
    }

    if(this->left == nullptr) {
        if(this->parent->getLeft() == this) {
            this->parent->setLeft(this->right);
        } else {
            this->parent->setRight(this->right);
        }

        this->setParent(nullptr);
        return this;
    }

    if(this->right == nullptr) {
        if(this->parent->getLeft() == this) {
            this->parent->setLeft(this->left);
        } else {
            this->parent->setRight(this->left);
        }

        this->setParent(nullptr);
        return this;
    }

    DTNode *newNode = this->left->getRightmost();
    newNode->setRight(this->right);

    if(this->parent->getLeft() == this) {
        this->parent->setLeft(newNode);
    } else {
        this->parent->setRight(newNode);
    }

    this->setParent(nullptr);
    return this;
}

long long DTNode::KeyToInt(const char key_[10]) {
    long long result = 0;

    for(int q = 0; q < 10; q++) {
        result = result * 10 + (key_[q] - '0');
    }

    return result;
}

DTNode *DTNode::getRoot() {
    if(this->parent == nullptr){
        return this;
    }

    return this->parent->getRoot();
}
