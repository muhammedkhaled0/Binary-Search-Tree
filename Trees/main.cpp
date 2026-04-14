#include <iostream>
#include "BST.cpp"

using namespace std;

int main() {
    BST<int> tree;

    // ===== Insert =====
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Tree built successfully!\n\n";

    // ===== Contains =====
    cout << "Contains 40? " << (tree.contains(40) ? "Yes" : "No") << endl;
    cout << "Contains 100? " << (tree.contains(100) ? "Yes" : "No") << endl;

    // ===== Find Node =====
    Node<int>* found = tree.findNode(70);
    if (found)
        cout << "Found node: " << found->data << endl;
    else
        cout << "Node not found\n";

    cout << "\n===== InOrder =====\n";
    tree.traverse(1);

    cout << "\n\n===== PreOrder =====\n";
    tree.traverse(2);

    cout << "\n\n===== PostOrder =====\n";
    tree.traverse(3);

    cout << endl;

    return 0;
}