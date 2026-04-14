#pragma once
template<class T>
class Node {
public:
	Node<T>* left, * right;
	T data;
	Node();
	Node(T);
};



template<class T>
class BST
{
public:
	Node<T>* root;
	BST();
	void insert(T);
	bool contains(T val);
	Node<T>* findNode(T val);
	void traverse(int order);
	void inOrder(Node<T>* start);
	void preOrder(Node<T>* start);
	void postOrder(Node<T>* start);
};

