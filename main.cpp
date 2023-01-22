#include <iostream>

#include "DTTree.h"
#include "SPTree.h"

using namespace std;

void freeTreeTest() {
    cout << "D Tree test" << endl;

    auto* root = new DTNode("1000000005", 0, nullptr);
    root->add("1000000003", 1);
    root->add("1000000004", 2);
    root->add("1000000002", 3);
    root->add("1000000006", 4);

    root->print();

    cout << root->find("1000000004")->getValue() << ", should be 2" << endl;

    cout << root->del("1000000003")->getValue() << ", should be 1" << endl;;

    root->print();

    cout << "--------------" << endl;

    cout << "SP Tree test" << endl;

    auto* rootSP = new SPNode("1000000010", 0, nullptr);
    rootSP->add("1000000005", 1);
    rootSP->add("1000000011", 2);
    rootSP->add("1000000003", 3);
    rootSP->add("1000000007", 4);
    rootSP->add("1000000002", 5);
    rootSP->add("1000000004", 6);
    rootSP->add("1000000006", 7);
    rootSP->add("1000000008", 8);

    rootSP->print();

    cout << rootSP->find("1000000004")->getValue() << ", should be 6" << endl;

    rootSP = (SPNode*)rootSP->getRoot();
    rootSP->print();

    cout << rootSP->find("1000000011")->getValue() << ", should be 2" << endl;

    rootSP = (SPNode*)rootSP->getRoot();
    rootSP->print();
}

void binTreeTest() {
    cout << "D Tree test" << endl;

    convertTextToBinary("../testrecords.txt", "../binDTrecords.dat");

    DTTree dtTree("../binDTrecords.dat");
    dtTree.print();

    cout << dtTree.find("789798677").name << endl;
    cout << dtTree.find("000000000").name << endl;

    dtTree.del("789798677");
    dtTree.print();

    cout << "--------------" << endl;

    cout << "SP Tree test" << endl;

    convertTextToBinary("../testrecords.txt", "../binSPrecords.dat");

    SPTree spTree("../binSPrecords.dat");
    spTree.print();

    cout << spTree.find("789798677").name << endl;
    cout << spTree.find("000000000").name << endl;

    spTree.print();
}

void bigTest() {

}

void task1() {
    DTTree tree("../tree.dat", true);

    int command;
    char phone[10], address[50], name[50];
    PhoneUser phoneUser{};

    while(true){
        cout << "Choose operation:" << endl;
        cout << "0 - exit" << endl;
        cout << "1 - add record" << endl;
        cout << "2 - find record" << endl;
        cout << "3 - delete record" << endl;
        cout << "4 - print tree" << endl;
        cin >> command;

        switch (command) {
            case 0:
                return;
            case 1:
                cout << "Enter phone:" << endl;
                cin >> phone;
                strcpy(phoneUser.phone, phone);
                cout << "Enter adders:" << endl;
                cin >> address;
                strcpy(phoneUser.address, address);
                cout << "Enter name:" << endl;
                cin >> name;
                strcpy(phoneUser.name, name);

                tree.add(phoneUser);
                break;
            case 2:
                cout << "Enter phone:" << endl;
                cin >> phone;

                phoneUser = tree.find(phone);
                cout << "Record is:" << endl;
                cout << phoneUser.phone << " " << phoneUser.address << " " << phoneUser.name << endl;
                break;
            case 3:
                cout << "Enter phone:" << endl;
                cin >> phone;

                tree.del(phone);
                break;
            case 4:
                cout << "Tree is:" << endl;
                tree.print();
                break;
            default:
                cout << "There is no such a command" << endl;
                break;
        }
    cout << endl;
    }
}

void task2() {
    SPTree tree("../tree.dat", true);

    int command;
    char phone[10], address[50], name[50];
    PhoneUser phoneUser{};

    while(true){
        cout << "Choose operation:" << endl;
        cout << "0 - exit" << endl;
        cout << "1 - add record" << endl;
        cout << "2 - find record" << endl;
        cout << "3 - delete record" << endl;
        cout << "4 - print tree" << endl;
        cin >> command;

        switch (command) {
            case 0:
                return;
            case 1:
                cout << "Enter phone:" << endl;
                cin >> phone;
                strcpy(phoneUser.phone, phone);
                cout << "Enter adders:" << endl;
                cin >> address;
                strcpy(phoneUser.address, address);
                cout << "Enter name:" << endl;
                cin >> name;
                strcpy(phoneUser.name, name);

                tree.add(phoneUser);
                break;
            case 2:
                cout << "Enter phone:" << endl;
                cin >> phone;

                phoneUser = tree.find(phone);
                cout << "Record is:" << endl;
                cout << phoneUser.phone << " " << phoneUser.address << " " << phoneUser.name << endl;
                break;
            case 3:
                cout << "Enter phone:" << endl;
                cin >> phone;

                tree.del(phone);
                break;
            case 4:
                cout << "Tree is:" << endl;
                tree.print();
                break;
            default:
                cout << "There is no such a command" << endl;
                break;
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Choose 0 for trees test, 1 for trees with files test, 2 for time test and 3 for task with ordinary search tree or 4 for task with Splay tree" << endl;
    cin >> n;

    switch(n){
        case 0:
            freeTreeTest();
            break;
        case 1:
            binTreeTest();
            break;
        case 2:
            bigTest();
            break;
        case 3:
            task1();
            break;
        case 4:
            task2();
            break;
        default:
            cout << "There is no such a task" << endl;
            break;
    }

    return 0;
}
