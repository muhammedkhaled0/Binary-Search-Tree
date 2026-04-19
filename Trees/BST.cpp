#include "BST.h"
#include<cassert>
#include<iostream>
using namespace std;
template<class T>
Node<T>::Node() {
	left = right = nullptr;
}
template<class T>
Node<T>::Node(T value) {
	data = value;
	left = right = nullptr;
}
template <class T>
BST<T>::BST() {
	root = nullptr;
}
template <class T>
Node<T>* BST<T>::findNode(T value) {
	if (root == nullptr) return nullptr;
	Node<T>* temp = root;
	while (temp != nullptr && temp->data != value) {
		if (value < temp->data) temp = temp->left;
		else temp = temp->right;
	}
	return temp;
}
template <class T>
bool BST<T>::contains(T value) {
	Node<T>* temp = root;
	while (temp != nullptr) {
		if (temp->data == value) {
			return true;
		}
		if (value < temp->data) temp = temp->left;
		else temp = temp->right;
	}
	return false;
}
template <class T>
void BST<T>::insert(T value) {
	Node<T>* temp = root;
	Node<T>* newNode=new Node<T>(value);
	if (root == nullptr) {
		root = newNode;
		return;
	}
	else {
		while (true) {
			if (value < temp->data) {
				if (temp->left == nullptr) {
					temp->left = newNode;
					break;
				}
				else {
					temp = temp->left;
				}
			}
			else {
				if (temp->right == nullptr) {
					temp->right = newNode;
					break;
				}
				else {
					temp = temp->right;
				}
			}
			}
		}
	}
template <class T>
void BST<T>::traverse(int order)
{
	if (order == 1)
		inOrder(root);
	else if (order == 2)
		preOrder(root);
	else
		postOrder(root);
}
template <class T>
void BST<T>::preOrder(Node<T>* start) {
	if (start == nullptr) return;
	cout << start->data<<" ";
	preOrder(start->left);
	preOrder(start->right);
}
template <class T>
void BST<T>::inOrder(Node<T>* start) {
	if (start == nullptr) return;
	inOrder(start->left);
	cout << start->data<<" ";
	inOrder(start->right);
}

template <class T>
void BST<T>::postOrder(Node<T>* start) {
	if (start == nullptr) return;
	postOrder(start->left);
	postOrder(start->right);
	cout << start->data << " ";
}
template <class T>
void BST<T>::remove(T value) {
	assert(root != nullptr);
	Node<T>* n=findNode(value);
	if (n->left == nullptr && n->right == nullptr) {
		if (n == root) {
			root = nullptr;
		}
		else {
			Node<T>*parent = findParent(value);
			if (value > parent->data) parent->right = nullptr;
			else parent->left = nullptr;
		}
	}
	else if (n->left == nullptr && n->right != nullptr) {
		if (n == root)
		{
			root = n->right;
		}
		else {
			Node<T>*parent = findParent(value);
			if (value > parent->data) {
				parent->right = n->right;
			}
			else {
				parent->left = n->right;
			}
		}
	}
	else if (n->left != nullptr && n->right == nullptr) {
		if (n == root)
		{
			root = n->left;
		}
		else {
			Node<T>*parent = findParent(value);
			if (value > parent->data) {
				parent->right = n->left;
			}
			else {
				parent->left = n->left;
			}

		}

	}
	else {
		Node<T>* minNode = findMin(n->right);
		Node<T>* parentOfMinNode=findParent(minNode->value);
		n->data = minNode->data;
		if (parentOfMinNode == n) {
			n->right=minNode->right;
		}
		else {
			parentOfMinNode->left = minNode->right;
		}

	}
}
template <class T>
Node<T>* BST<T>::findMin(Node<T>* start)
{
	Node<T>* minNode = start;
	while (minNode->left != NULL)
	{
		minNode = minNode->left;
	}

	return minNode;
}
template <class T>
Node<T>* BST<T>::findParent(T value) {
	Node<T>* parent = nullptr;
	Node<T>* myNode = root;
	while (myNode!=nullptr) {
		if (myNode->data == value)
		{
			break;
		}
		parent = myNode;
		if (value > myNode->data)myNode = myNode->right;
		else myNode = myNode->left;
	}
	return parent;
}
template <class T>
void BST<T>::deleteBST(Node<T>* node)
{
	if (node == NULL)
		return;

	Node<T>* currentTreeNode = node;
	Node<T>* leftTreeNode = node->left;
	Node<T>* rightTreeNode = node->right;
	delete(currentTreeNode);
	deleteBST(leftTreeNode);
	deleteBST(rightTreeNode);
}
template <class T>
BST<T>::~BST()
{
	deleteBST(root);
}
