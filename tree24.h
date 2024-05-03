#ifndef TREE24_H
#define TREE24_H

#endif //TREE24_H


#include <iostream>
#include "node.h"

using namespace std;

class Tree24 {
    Node* root;
    int size;

    Node* search(Node* node, int num) {
        int index = node->getSize();
        for (int i = 0; i < node->getSize(); i++) {
            if (num == node->getData(i)) {
                return node;
            }

            if (num < node->getData(i)) {
                index = i;
                break;
            }
        }

        if (!node->getChild(index)) {
            return node;
        }
        return search(node->getChild(index), num);
    }

public:
    Tree24() {
        root = nullptr;
        size = 0;
    }

    Node* search (const int num) {
     return search(root, num);
    }


    void insert(const int num) {
        if (!root) {
            root = new Node(num, nullptr);
        } else {
            Node* w = search(num);
            bool ok = w->addKey(num);

            while (!ok) {
                Node* u;
                int position;
                if (w == root) {
                    root = u = new Node(w->getData(2), nullptr);
                    position = 0;
                    ok = true;
                } else {
                    u = w->getParent();
                    ok = u->addKey(w->getData(2));
                    position = u->indexOf(w->getData(2));
                }

                auto* wp = new Node(w->getData(0), u);
                wp->addKey(w->getData(1));

                auto* wpp = new Node(w->getData(3), u);

                u->insertChildren(wp, wpp, position);
                w = u;
            }
        }


        size++;
    }

    void print() {
        cout << "Size of tree: " << this->size << endl;
        root->print();
    }
};