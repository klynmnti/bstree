#include "BSTree.h"
/* Default Constructor */
// sets root to null
BSTree::BSTree() {
    root = nullptr;
}
/* Destructor */
// deletes root + right and left subtrees 
BSTree::~BSTree() {
    if (root) {
        delete root->left;
        delete root->right;
        delete root;
    }
}
/* Empty function */
// returns true if root is null and false otherwise
bool BSTree::empty() const {
    if (root == nullptr) { return true; }
    return false;
}
/* PreOrder, InOrder, and PostOrder functions */
// calls the respective recursive order function
void BSTree::preOrder() const {
    preOrder(root); 
}
void BSTree::inOrder() const {
    inOrder(root); 
}
void BSTree::postOrder() const {
    postOrder(root); 
}
/* PreOrder Recursive function */
// prints the tree recursively, in the order root, left subtree, right subtree
void BSTree::preOrder(Node* n) const {
    if (n == nullptr) { return; }
    n->printNode();
    preOrder(n->left);
    preOrder(n->right);
}
/* InOrder Recursive function */
// prints the tree recursively, in the order left subtree, root, right subtree
void BSTree::inOrder(Node* n) const {
    if (n == nullptr) { return; }
    inOrder(n->left);
    n->printNode();
    inOrder(n->right);
}
/* PostOrder Recursive function */
// prints the tree recursively, in the order left subtree, right subtree, root
void BSTree::postOrder(Node* n) const {
    if (n == nullptr) { return; }
    postOrder(n->left);
    postOrder(n->right);
    n->printNode();
}
/* FindNode Recursive helper function */
// used in insert, height, getParent, and remove
// recursively traverses through the tree and returns the node with key userstr, else returns null
Node* BSTree::findNode(Node* n, const string &userstr) {
    if (n == nullptr) { return nullptr; }
    else if (userstr < n->nodestr) { return findNode(n->left, userstr); }
    else if (userstr > n->nodestr) { return findNode(n->right, userstr); }
    else { return n; }
    return nullptr;
}
/* Search function */
// returns the recursive private function
bool BSTree::search(const string &userstr) const { 
    return search(userstr, root);
}
/* Search Recursive function */
// recursively traverses through the tree and returns true if node with key userstr is found, else returns false
bool BSTree::search(const string &userstr, Node* n) const {
    if (n == nullptr) { return false; }
    if (n->nodestr == userstr) { return true; }
    if (userstr < n->nodestr) { return search(userstr, n->left); }
    if (userstr > n->nodestr) { return search(userstr, n->right); }
    return false;
}
/* Insert function (iterative) */
// if a node with key already exists within the tree, the node's count is increased by one
// else create a new node and traverse through tree to a node where the node can be inserted
void BSTree::insert(const string &userstr) {
    if (search(userstr) == true) {
        Node* n = findNode(root, userstr);
        n->increaseCount();
        return;
    }
    Node *n = new Node(userstr, 1);
    // if tree is empty, set the root equal to the new node
    if (root == nullptr) {
        root = n;
        n = nullptr;
    }
    else {
        Node* curr = root;
        while (n != nullptr) {
            // if current node is in the right location, 
            // determine if current node has an empty space for the new node
            // if space is empty, insert, otherwise go to the next node
            if (userstr < curr->nodestr) {
                if (curr->left == nullptr) {
                    curr->left = n;
                    n = nullptr;
                }
                else { curr = curr->left; }
            }
            else {
                if (curr->right == nullptr) {
                    curr->right = n;
                    n = nullptr;
                }
                else { curr = curr->right; }
            }
        }
    }
}
/* Largest function */
// recursively traverses right subtree until largest leaf node is reached & returns node's string value
string BSTree::largest() const { 
    Node* curr = root;
    if (curr == nullptr) { return ""; }
    while (curr->right != nullptr) { curr = curr->right; }
    return curr->nodestr;
}
/* Smallest function */
// recursively traverses left subtree until smallest leaf node is reached & returns node's string value
string BSTree::smallest() const { 
    Node* curr = root;
    if (curr == nullptr) { return ""; }
    while (curr->left != nullptr) { curr = curr->left; }
    return curr->nodestr;
}
/* Height function */
// returns private recursive height function
int BSTree::height(const string &userstr) {
    Node* n = findNode(root, userstr);
    return height(n);
}
/* Height Recursive function */
// recursively traverses through left and right subtree and incremements left and right heights
// returns largest of right and left subtree heights
int BSTree::height(Node* n) const {
    if (n == nullptr) { return -1; }
    int lheight = height(n->left);
    int rheight = height(n->right);
    if (lheight > rheight) { return lheight + 1; }
    else { return rheight + 1; }
}
/* GetParent Recursive function */
// private helper function used in remove function
// traverses through tree until a node that points to node with key userstr is found
Node* BSTree::getParent(const string &userstr, Node* n) {
    Node* child = findNode(root, userstr);
    if (n == nullptr) { return nullptr; }
    if ((n->left == child) || (n->right == child)) { return n; }
    if (child->nodestr < n->nodestr) { return getParent(userstr, n->left); }
    if (child->nodestr > n->nodestr) { return getParent(userstr, n->right); }
    return nullptr;
}
/* Remove function */
// finds the node with key userstr and decrements count if count is greater than 1
// otherwise, calls the private helper function below
void BSTree::remove(const string &userstr) {
    if (search(userstr)) {
        Node* n = findNode(root, userstr);
        if (n->count > 1) { n->decreaseCount(); }
        else { remove(root, userstr); }
    }
}
/* Remove private helper function (iterative) */
// determines how many children the node to be deleted has, and proceeds through loop
void BSTree::remove(Node* n, const string& userstr) {
    Node* parent = nullptr;
    Node* curr = n;
    while (curr != nullptr) {
        // if the key of the curr node matches userstr
        if (curr->nodestr == userstr) {
            /* Case 1: Node has no children */
            // if parent is null, curr is the root and root is deleted
            // otherwise, find node's parent and set parent's left/right pointer to null (whichever points to curr)
            if (curr->left == nullptr && curr->right == nullptr) {
                parent = getParent(userstr, root);
                if (parent == nullptr) {
                    delete root;
                    root = nullptr;
                }
                else if (parent->left == curr) { parent->left = nullptr; }
                else { parent->right = nullptr; }
            }
            /* Case 2: Node has a left child only */
            // if the parent is null, set the node's left child as the root
            // otherwise, set the parent's left/right pointer to curr's left child and delete curr
            else if (curr->right == nullptr) {
                if (parent == nullptr) { root = curr->left; }
                else if (parent->left == curr) { parent->left = curr->left; }
                else { parent->right = curr->left; }
                delete curr;
            }
            /* Case 3: Node has a right child only */
            // find the successor node (the leftmost node in the right subtree) and swap data
            // recursively call remove on the successor node
            else if (curr->left == nullptr) {
                Node* suc = curr->right;
                while (suc->left != nullptr) { suc = suc->left; }
                string tempstr = suc->nodestr;
                int tempcount = suc->count;
                remove(root, tempstr);
                curr->nodestr = tempstr;
                curr->count = tempcount;
            }
            /* Case 4: Node has two children */
            // find the successor node (rightmost node in left subtree) and swap data
            // recursively call remove on the successor node
            else {
                Node* suc = curr->left;
                while (suc->right != nullptr) { suc = suc->right; }
                string tempstr = suc->nodestr;
                int tempcount = suc->count;
                remove(root, tempstr);
                curr->nodestr = tempstr;
                curr->count = tempcount;
            }
            return;
        }
        // otherwise if the key does not match and userstr is less than curr's key, iterate through left
        else if (userstr < curr->nodestr) {
            parent = curr;
            curr = curr->left;
        }
        // if the key does not match and userstr is greater than curr's key iterate through right
        else {
            parent = curr;
            curr = curr->right;
        }
    }
    return;
}