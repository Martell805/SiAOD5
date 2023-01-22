#ifndef SIAOD5_PHONEBOOK_H
#define SIAOD5_PHONEBOOK_H

#include "string"
#include "fstream"
#include "iostream"
#include "vector"
#include "PhoneUser.hpp"

using namespace std;

void assertFileOpened(const ifstream &file);
void assertFileOpened(const ofstream &file);
void assertFileOpened(const fstream &file);
void assertFileErrors(const ifstream &file);
void assertFileErrors(const ofstream &file);
void assertFileErrors(const fstream &file);
void convertTextToBinary(const string& textFilename, const string& binFilename);
void convertBinaryToText(const string& binFilename, const string& textFilename);

class PhoneBook {
protected:
    string filename;
    int recordCount = 0;
public:
    explicit PhoneBook(const string &filename_);
    void print();
    PhoneUser getRecord(int n);
    void deleteRecord(int n);
    void appendRecord(const PhoneUser &phoneUser);
    void rewriteRecord(const PhoneUser &phoneUser, int n);
    void createFile();
    int getRecordCount();
    void increaseRecordCount();
};


#endif //SIAOD5_PHONEBOOK_H
