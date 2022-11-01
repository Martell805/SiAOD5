#include "PhoneBook.h"

void assertFileOpened(const ifstream &file){
    if(file.is_open()) return;
    throw -1;
}

void assertFileOpened(const ofstream &file){
    if(file.is_open()) return;
    throw -1;
}

void assertFileOpened(const fstream &file){
    if(file.is_open()) return;
    throw -1;
}

void assertFileErrors(const ifstream &file){
    if(file.good() or file.eof()) return;
    throw -2;
}

void assertFileErrors(const ofstream &file){
    if(file.good() or file.eof()) return;
    throw -2;
}

void assertFileErrors(const fstream &file){
    if(file.good() or file.eof()) return;
    throw -2;
}

void convertTextToBinary(const string& textFilename, const string& binFilename){
    ifstream infile(textFilename);
    assertFileOpened(infile);

    ofstream outfile(binFilename, ios::binary);
    assertFileOpened(outfile);

    PhoneUser phoneUser{};

    while(infile >> phoneUser.phone){
        infile >> phoneUser.address;
        infile >> phoneUser.name;

        outfile.write((char*)&phoneUser, sizeof(PhoneUser));
    }

    assertFileErrors(infile);
    infile.close();

    assertFileErrors(outfile);
    outfile.close();
}

void convertBinaryToText(const string& binFilename, const string& textFilename){
    ifstream infile(binFilename, ios::binary);
    assertFileOpened(infile);

    ofstream outfile(textFilename);
    assertFileOpened(outfile);

    PhoneUser phoneUser{};

    while(infile.read((char*)&phoneUser, sizeof(PhoneUser))){
        outfile << phoneUser.phone << " " << phoneUser.address << " " << phoneUser.name << endl;
    }

    assertFileErrors(infile);
    infile.close();

    assertFileErrors(outfile);
    outfile.close();
}

PhoneBook::PhoneBook(string filename_): filename(std::move(filename_)) {
    ofstream file(this->filename);
    assertFileOpened(file);

    assertFileErrors(file);
    file.close();
}

void PhoneBook::print(){
    ifstream infile(this->filename, ios::binary);
    assertFileOpened(infile);

    PhoneUser phoneUser{};

    while(infile.read((char*)&phoneUser, sizeof(PhoneUser))){
        cout << phoneUser.phone << " " << phoneUser.address << " " << phoneUser.name << endl;
    }

    assertFileErrors(infile);
    infile.close();
}

PhoneUser PhoneBook::getRecord(int n){
    ifstream infile(this->filename, ios::binary);
    assertFileOpened(infile);

    PhoneUser phoneUser{};

    infile.seekg(n * sizeof(PhoneUser));

    infile.read((char*)&phoneUser, sizeof(PhoneUser));

    assertFileErrors(infile);
    infile.close();

    return phoneUser;
}

void PhoneBook::deleteRecord(int n){
    fstream file(this->filename, ios::binary | ios::in);
    assertFileOpened(file);

    vector<PhoneUser> users;

    PhoneUser record{};

    while(file.read((char*)&record, sizeof(PhoneUser))) {
        users.push_back(record);
    }

    users[n] = record;

    assertFileErrors(file);
    file.close();

    file.open(this->filename, ios::binary | ios::out);
    assertFileOpened(file);

    for(int q = 0; q < users.size() - 1; q++)
        file.write((char*)&users[q], sizeof(PhoneUser));

    assertFileErrors(file);
    file.close();
}

void PhoneBook::appendRecord(const PhoneUser &phoneUser){
    fstream file(this->filename, ios::binary | ios::in | ios::out);
    assertFileOpened(file);

    file.seekg(0, ios::end);
    file.write((char*)&phoneUser, sizeof(PhoneUser));

    assertFileErrors(file);
    file.close();
}

void PhoneBook::rewriteRecord(const PhoneUser &phoneUser, int n){
    fstream file(this->filename, ios::binary | ios::in | ios::out);
    assertFileOpened(file);

    file.seekg(n * sizeof(PhoneUser));
    file.write((char*)&phoneUser, sizeof(PhoneUser));

    assertFileErrors(file);
    file.close();
}
