#include "DTTree.h"

DTTree::DTTree(const string& filename_, bool createNew) {
    this->phoneBook = new PhoneBook(filename_);

    if(createNew) {
        this->phoneBook->createFile();
        return;
    }

    ifstream infile(filename_, ios::binary);
    assertFileOpened(infile);

    PhoneUser phoneUser{};

    while(infile.read((char*)&phoneUser, sizeof(char) * 110)){
        if(this->root == nullptr) {
            this->root = new DTNode(phoneUser.phone, this->phoneBook->getRecordCount());
        } else {
            this->root->add(phoneUser.phone, this->phoneBook->getRecordCount());
        }

        this->phoneBook->increaseRecordCount();
    }

    assertFileErrors(infile);
    infile.close();
}

void DTTree::add(PhoneUser phoneUser) {
    if(this->root == nullptr) {
        this->root = new DTNode(phoneUser.phone, this->phoneBook->getRecordCount());
    } else {
        this->root->add(phoneUser.phone, this->phoneBook->getRecordCount());
    }

    this->phoneBook->appendRecord(phoneUser);
}

PhoneUser DTTree::find(char key_[10]) {
    if(this->root == nullptr) {
        return PhoneUser{"null", "null", "null"};
    }

    DTNode* result = this->root->find(key_);

    if(result == nullptr) {
        return PhoneUser{"null", "null", "null"};
    }

    return this->phoneBook->getRecord(result->getValue());
}

void DTTree::del(char key_[10]) {
    if(this->root == nullptr) {
        return;
    }

    DTNode* result = this->root->del(key_);

    if(result == nullptr) {
        return;
    }

    PhoneUser lastUser = this->phoneBook->getRecord(this->phoneBook->getRecordCount() - 1);
    this->phoneBook->deleteRecord(result->getValue());

    this->root->find(lastUser.phone)->setValue(result->getValue());
}

void DTTree::print() const {
    if(this->root == nullptr) {
        return;
    }

    this->root->print();
}
