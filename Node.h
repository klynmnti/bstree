#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
#pragma once

class Node {
    // BSTree is established as a friend class to access Node's private data members
    friend class BSTree;
    public:
        Node(const string& userstr, int usercnt);
        ~Node();
        Node(const Node &cpy) {};
        void printNode() const;
        void increaseCount();
        void decreaseCount();
    private:
        Node* left;
        Node* right;
        string nodestr;
        int count;
};

#endif