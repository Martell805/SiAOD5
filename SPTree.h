#ifndef SIAOD5_SPTREE_H
#define SIAOD5_SPTREE_H


#include "SPNode.h"
#include "PhoneBook.h"

using namespace std;

class SPTree {
protected:
    SPNode* root = nullptr;
    PhoneBook *phoneBook;
public:
    explicit SPTree(const string& filename_, bool createNew = false);
public:
    void add(PhoneUser phoneUser);
    PhoneUser find(char key_[10]);
    void del(char key_[10]);
    void print() const;
};

#endif //SIAOD5_SPTREE_H
