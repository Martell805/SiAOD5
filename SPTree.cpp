#include "SPTree.h"

SPTree::SPTree(const string& filename_, bool createNew) {
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
            this->root = new SPNode(phoneUser.phone, this->phoneBook->getRecordCount());
        } else {
            this->root->add(phoneUser.phone, this->phoneBook->getRecordCount());
        }

        this->phoneBook->increaseRecordCount();
    }

    assertFileErrors(infile);
    infile.close();
}

void SPTree::add(PhoneUser phoneUser) {
    if(this->root == nullptr) {
        this->root = new SPNode(phoneUser.phone, this->phoneBook->getRecordCount());
    } else {
        this->root->add(phoneUser.phone, this->phoneBook->getRecordCount());
    }

    this->phoneBook->appendRecord(phoneUser);
}

PhoneUser SPTree::find(char key_[10]) {
    if(this->root == nullptr) {
        return PhoneUser{"null", "null", "null"};
    }

    DTNode* result = this->root->find(key_);

    if(result == nullptr) {
        return PhoneUser{"null", "null", "null"};
    }

    return this->phoneBook->getRecord(result->getValue());
}

void SPTree::del(char key_[10]) {
    if(this->root == nullptr) {
        return;
    }

    cout << 456264767 << endl;

    cout << key_ << endl;

    DTNode* result = this->root->del(key_);

    cout << result->getKey() << " " << result->getValue();

    if(result == nullptr) {
        return;
    }

    PhoneUser lastUser = this->phoneBook->getRecord(this->phoneBook->getRecordCount() - 1);
    this->phoneBook->deleteRecord(result->getValue());

    this->root->find(lastUser.phone)->setValue(result->getValue());
}

void SPTree::print() const {
    if(this->root == nullptr) {
        return;
    }

    this->root->print();
}
