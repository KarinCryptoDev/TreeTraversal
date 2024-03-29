#pragma once
//c076290 이은지

//Levelorder구현을 위해 

#ifndef BT_H
#define BT_H
#include <iostream>
#include <queue>
using namespace std;
template <class T> class Tree; //전방선언
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
private: // helper 함수들
	void Visit(TreeNode<T>*);
	void Insert(TreeNode<T>*&, T&);
	void Preorder(TreeNode<T>*);
	void Inorder(TreeNode<T>*);
	void Postorder(TreeNode<T>*);

	TreeNode<T>* root; //root부터 전체적으로 쓸 수 있는 함수가 있다. recursive
};
template <class T>
void Tree<T>::Visit(TreeNode<T>* ptr) { cout << ptr->data << " "; }template <class T>
void Tree<T>::Insert(TreeNode<T>*& ptr, T& value) { //Insert helper의 함수
	//ptr root 은
	if (ptr == 0) ptr = new TreeNode<T>(value);
	else if (value < ptr->data) Insert(ptr->leftChild, value); //값이 직으면 왼쪽 차일드
	else if (value > ptr->data) Insert(ptr->rightChild, value); //값이 크면 오른쪽차일드
	else cout << endl << "Duplicate value " << value << " ignored\n";
}


template <class T>
void Tree<T>::Preorder(TreeNode<T>* currentNode) { 
	//Preorder helper 의 함수
	if (currentNode) {
		Visit(currentNode);
		Preorder(currentNode->leftChild);
		Preorder(currentNode->rightChild);
	}
}
//..... Inorder, Postorder helper . 의 함수를구현하시오
template <class T>
void Tree<T>::Inorder(TreeNode<T>* currentNode) {
	if (currentNode) {
		Inorder(currentNode->leftChild);
		Visit(currentNode);
		Inorder(currentNode->rightChild);
	}
}
//Postorder helper의 함수
template <class T>
void Tree<T>::Postorder(TreeNode<T>* currentNode) {
	if (currentNode) {
		Postorder(currentNode->leftChild);
		Postorder(currentNode->rightChild);
		Visit(currentNode);
	}
}

//..... Levelorder( p266 STL ) . 교재 참조하되 큐를이용 를구현하시오
template <class T>
void Tree<T>::Levelorder()
{//이진 트리의 레벨 순서 순회
	queue<TreeNode<T>*> q; // 큐를 사용하자
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