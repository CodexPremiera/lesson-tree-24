#ifndef NODE_H
#define NODE_H

#endif //NODE_H

#include <iostream>
#include <cstdlib>

using namespace std;


class Node {
    /* CONSTS */
    const int MAX_KEY = 4;
    const int MAX_CHILDREN = 5;

    /* FIELDS */
    Node* parent;
    Node** children;
    int* data;
    int size;

public:
    Node(int num, Node* parent) {
        this->parent = parent;
        this->children = (Node**) calloc(MAX_CHILDREN, sizeof(Node*));
        this->data = (int*) malloc(MAX_KEY * sizeof(int)) ;
        this->data[0] = num;
        this->size = 1;
    }

    int getSize() {
        return this->size;
    }

    int getData(const int index) {
        return data[index];
    }

    Node* getChild(const int index) {
        return children[index];
    }

    Node* getParent() {
        return parent;
    }

    int indexOf(const int num) {
        for (int i = 0; i < size; i++) {
            if (num == data[i])
                return i;
        }
        return -1;
    }

    void insertChildren(Node* wp, Node* wpp, int position) {
        for(int i = size - 1; i > position; i--) {
            children[i+1] = children[i];
        }
        children[position] = wp;
        children[position + 1] = wpp;
    }

    bool addKey(const int num) {
        int i;
        for (i = size; i > 0; i--) {
            if (num >= data[i - 1])
                break;
            data[i] = data[i - 1];
        }

        data[i] = num;
        return ++size != MAX_KEY;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }

        cout << endl;
        for (int i = 0; i < 5; i++) {
            if (children[i] != nullptr) {
                children[i]->print();
            }
        }
    }
};

