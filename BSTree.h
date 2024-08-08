#ifndef BSTREE_H
#define BSTREE_H

#include "Node.h" 

class BSTree {
    public:
        BSTree();
        ~BSTree();
        BSTree(const BSTree &cpy) {}; // Copy Constructor
        Node* findNode(Node* n, const string &userstr);
        Node* getParent(const string &userstr, Node* n);
        void insert(const string &userstr); 
        bool search(const string &userstr) const; 
        string largest() const; 
        string smallest() const; 
        int height(const string &userstr);
        void remove(const string &userstr);
        void preOrder() const;
        void inOrder() const; 
        void postOrder() const; 
        bool empty() const;

    private:
        Node* root;
        // Below are recursive helper functions for the above public functions
        void preOrder(Node* n) const;
        void inOrder(Node* n) const;
        void postOrder(Node* n) const;
        bool search(const string &userstr, Node* n) const;
        void remove(Node* n, const string& userstr);
        int height(Node* n) const;
};

#endif