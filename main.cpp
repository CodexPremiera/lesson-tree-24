#include <iostream>
#include "tree24.h"

int main() {
    auto* tree = new Tree24();

    tree->insert(13);
    constexpr int target = 4;
    cout << "Searching for " << target << ": ";
    tree->search(target)->print();
    cout << endl;

    tree->insert(4);
    tree->insert(17);
    tree->insert(5);
    tree->insert(26);
    tree->print();

    delete tree;
    return 0;
}
