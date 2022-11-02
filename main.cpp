#include <iostream>

#include "DTNode.h"
#include "SPNode.h"

using namespace std;

void test() {
//    cout << "D Tree test" << endl;
//
//    auto* root = new DTNode("1000000005", 0, nullptr);
//    root->add("1000000003", 1);
//    root->add("1000000004", 2);
//    root->add("1000000002", 3);
//    root->add("1000000006", 4);
//
//    root->print();
//
//    cout << root->find("1000000004")->getValue() << ", should be 2" << endl;
//
//    cout << "--------------" << endl;

    cout << "SP Tree test" << endl;

    auto* rootSP = new SPNode("1000000005", 0, nullptr);
    rootSP->add("1000000003", 1);
    rootSP->add("1000000004", 2);
    rootSP->add("1000000002", 3);
    rootSP->add("1000000006", 4);

    rootSP->print();

    cout << rootSP->find("1000000004")->getValue() << ", should be 2" << endl;

    rootSP = (SPNode*)rootSP->getRoot();
    rootSP->print();
}

void task1() {
//    PerfectlyBalancedBinaryTree pBBTree;

    int command;
    char value;

    while(true){
        cout << "Choose operation:" << endl;
        cout << "0 - exit" << endl;
        cout << "1 - add key" << endl;
        cout << "2 - get size of tree" << endl;
        cout << "3 - get leftmost key" << endl;
        cout << "4 - get depth of key" << endl;
        cout << "5 - get max leaf" << endl;
        cout << "6 - print tree" << endl;
        cin >> command;

        switch (command) {
            case 0:
                return;
            case 1:
                cout << "Enter key to add:" << endl;
                cin >> value;
//                pBBTree.add(value);
                break;
            case 2:
//                cout << "Size of tree is " << pBBTree.getSize() << endl;
                break;
            case 3:
//                cout << "Leftmost key of tree is " << pBBTree.getLeftmost() << endl;
                break;
            case 4:
                cout << "Enter key:" << endl;
                cin >> value;
//                cout << "Depth of '" << value << "' is " << pBBTree.getDepth(value) << endl;
                break;
            case 5:
//                cout << "Maximum key of leaf is " << pBBTree.getMaxLeaf() << endl;
                break;
            case 6:
                cout << "Tree: " << endl;
//                pBBTree.print();
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
//    cout << "Choose 0 for test or 1 for task1:" << endl;
//    cin >> n;
    n = 0;

    switch(n){
        case 0:
            test();
            break;
        case 1:
            task1();
            break;
        default:
            cout << "There is no such a task" << endl;
            break;
    }

    return 0;
}
