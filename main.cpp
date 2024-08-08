#include "BSTree.h"
/* printMenu function */
void printMenu() {
    cout << "Enter menu choice: " << endl;
    cout << "1. Insert" << endl;
    cout << "2. Remove" << endl;
    cout << "3. Print" << endl;
    cout << "4. Search" << endl;
    cout << "5. Smallest" << endl;
    cout << "6. Largest" << endl;
    cout << "7. Height" << endl;
    cout << "8. Quit" << endl;
}
int main() {
    BSTree testTree = BSTree();
    char userch;
    string userstr;

    cout << endl;
    printMenu();

    while (cin >> userch) {
        /* testing for silent failure */
        if (cin.good()) {
            if (userch == '1') {
                cout << "Enter string to insert: ";
                cin.ignore();
                getline(cin, userstr);
                cout << endl << endl;
                testTree.insert(userstr);
                printMenu();
            }
            else if (userch == '2') {
                cout << "Enter string to remove: ";
                cin.ignore();
                getline(cin, userstr);
                cout << endl << endl;
                testTree.remove(userstr);
                printMenu();
            }
            else if (userch == '3') {
                cout << "Preorder = ";
                testTree.preOrder();
                cout << endl;
                cout << "Inorder = ";
                testTree.inOrder();
                cout << endl;
                cout << "Postorder = ";
                testTree.postOrder();
                cout << endl << endl;
                printMenu();
            }
            else if (userch == '4') {
                cout << "Enter string to search for: ";
                cin.ignore();
                getline(cin, userstr);
                cout << endl;
                if (testTree.search(userstr) == false) {
                    cout << "Not Found" << endl << endl;
                } 
                else {
                    cout << "Found" << endl << endl;
                }
                printMenu();
            }
            else if (userch == '5') {
                cout << "Smallest: " << testTree.smallest() << endl << endl;
                printMenu();
            }
            else if (userch == '6') {
                cout << "Largest: " << testTree.largest() << endl << endl;
                printMenu();
            }
            else if (userch == '7') {
                cout << "Enter string: ";
                cin.ignore();
                getline(cin, userstr);
                cout << endl;
                cout << "Height of subtree rooted at " << userstr << ": " << testTree.height(userstr) << endl << endl;
                printMenu();
            }
            /* if input does not match the expectation, exit */
            else { return 0; }
            cin.clear();
        }
    }   
    return 0;
}
