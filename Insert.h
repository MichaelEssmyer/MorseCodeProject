#pragma once
#include "Binary_Tree.h"

using namespace std;
class Insert {
public:
	Insert(BTNode<char>*root, char letter) 
	{
		if (root->left == NULL) 
		{
			BTNode<char>* theTree = new BTNode<char>(letter);
			root->left = theTree;
		}
		else if (root->right == NULL)
		{
			BTNode<char>* theTree = new BTNode<char>(letter);
			root->right == theTree;
		}
		else if(root->data > letter)
		{
			Insert(root->right, letter);
		}
		else if(root-> data <letter)
		{
			Insert(root->left, letter);
		}
	}

	void treedelete(BTNode<char>* root)
	{
		if (root->left == NULL && root->right == NULL) { delete[] root; }
		else if (root->left != NULL) { treedelete(root->left); }
		else if (root->right != NULL) { treedelete(root->right); }
	}
private:
	bool find(BTNode<char>* root, char letter) {}
	void insert(BTNode<char>* root, char letter) {}

	string valuesCode;
	Binary_Tree <char> memory;
};