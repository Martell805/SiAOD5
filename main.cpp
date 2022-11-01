#include <iostream>

#include "PBBTNode.h"
#include "DTNode.h"

using namespace std;

void test() {
    auto* root = new PBBTNode("1000000005", 0, nullptr);
    root->add("1000000003", 1);
    root->add("1000000004", 2);
    root->add("1000000002", 3);
    root->add("1000000006", 4);

    root->print();

    cout << "--------------" << endl;

    auto* rootD = new DTNode("1000000005", 0, nullptr);
    rootD->add("1000000003", 1);
    rootD->add("1000000004", 2);
    rootD->add("1000000002", 3);
    rootD->add("1000000006", 4);

    rootD->print();
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
    cout << "Choose 0 for test or 1 for task1:" << endl;
    cin >> n;

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