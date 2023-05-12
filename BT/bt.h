#pragma once
//c076290 ������

//Levelorder������ ���� 

#ifndef BT_H
#define BT_H
#include <iostream>
#include <queue>
using namespace std;
template <class T> class Tree; //���漱��
template <class T>
class TreeNode {
	friend class Tree<T>;
	TreeNode(T d, TreeNode<T>* left = 0, TreeNode<T>* right = 0)
		: data(d), leftChild(left), rightChild(right) { }
private:
	TreeNode<T>* leftChild;
	T data;
	TreeNode<T>* rightChild;
};
template <class T>
class Tree {
public:
	Tree() { root = 0; } // empty tree
	void Insert(T & value) { Insert(root, value); }
	void Preorder() { Preorder(root); }
	void Inorder() { Inorder(root); }
	void Postorder() { Postorder(root); }
	void Levelorder();
private: // helper �Լ���
	void Visit(TreeNode<T>*);
	void Insert(TreeNode<T>*&, T&);
	void Preorder(TreeNode<T>*);
	void Inorder(TreeNode<T>*);
	void Postorder(TreeNode<T>*);

	TreeNode<T>* root; //root���� ��ü������ �� �� �ִ� �Լ��� �ִ�. recursive
};
template <class T>
void Tree<T>::Visit(TreeNode<T>* ptr) { cout << ptr->data << " "; }template <class T>
void Tree<T>::Insert(TreeNode<T>*& ptr, T& value) { //Insert helper�� �Լ�
	//ptr root ��
	if (ptr == 0) ptr = new TreeNode<T>(value);
	else if (value < ptr->data) Insert(ptr->leftChild, value); //���� ������ ���� ���ϵ�
	else if (value > ptr->data) Insert(ptr->rightChild, value); //���� ũ�� ���������ϵ�
	else cout << endl << "Duplicate value " << value << " ignored\n";
}


template <class T>
void Tree<T>::Preorder(TreeNode<T>* currentNode) { 
	//Preorder helper �� �Լ�
	if (currentNode) {
		Visit(currentNode);
		Preorder(currentNode->leftChild);
		Preorder(currentNode->rightChild);
	}
}
//..... Inorder, Postorder helper . �� �Լ��������Ͻÿ�
template <class T>
void Tree<T>::Inorder(TreeNode<T>* currentNode) {
	if (currentNode) {
		Inorder(currentNode->leftChild);
		Visit(currentNode);
		Inorder(currentNode->rightChild);
	}
}
//Postorder helper�� �Լ�
template <class T>
void Tree<T>::Postorder(TreeNode<T>* currentNode) {
	if (currentNode) {
		Postorder(currentNode->leftChild);
		Postorder(currentNode->rightChild);
		Visit(currentNode);
	}
}

//..... Levelorder( p266 STL ) . ���� �����ϵ� ť���̿� �������Ͻÿ�
template <class T>
void Tree<T>::Levelorder()
{//���� Ʈ���� ���� ���� ��ȸ
	queue<TreeNode<T>*> q; // ť�� �������
	TreeNode<T>* currentNode = root;
	while (currentNode)
	{
		Visit(currentNode);
		if (currentNode->leftChild)
			q.push(currentNode->leftChild);
		if (currentNode->rightChild)
			q.push(currentNode->rightChild);
		if (q.empty())
			return;
		currentNode = q.front();
		
		q.pop();
	}
}
#endif