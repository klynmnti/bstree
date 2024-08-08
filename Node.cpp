#include "Node.h"
/* Parameterized Constructor assigns the node's string and count with the given arguments */
Node::Node(const string& userstr, int usercnt) :
    nodestr(userstr), count(usercnt)
{}
/* Destructor sets the Node's pointers to null */
Node::~Node() {
    left = nullptr;
    right = nullptr;
}
/* PrintNode function is used in preOrder, inOrder, and postOrder functions in BSTree */
void Node::printNode() const { cout << nodestr << "(" << count << "), "; }
/* IncreaseCount function is used in BSTree insert, and increases Node's count by one */
void Node::increaseCount() { count++; }
/* DecreaseCount function is used in BSTree remove, and decreases Node's count by one */
void Node::decreaseCount() { count--; }
