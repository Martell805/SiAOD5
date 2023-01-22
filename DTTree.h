#ifndef SIAOD5_DTTREE_H
#define SIAOD5_DTTREE_H

#include "DTNode.h"
#include "PhoneBook.h"

using namespace std;

class DTTree {
protected:
    DTNode* root = nullptr;
    PhoneBook *phoneBook;
public:
    explicit DTTree(const string& filename_, bool createNew = false);
public:
    void add(PhoneUser phoneUser);
    PhoneUser find(char key_[10]);
    void del(char key_[10]);
    void print() const;
};


#endif //SIAOD5_DTTREE_H
