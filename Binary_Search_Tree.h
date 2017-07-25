#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "Binary_Tree.h"


template<typename Item_Type>
class Binary_Search_Tree : public Binary_Tree<Item_Type>
{
public:
	// Constructor
	/* Construct an empty Binary_Search_Tree*/
	Binary_Search_Tree() : Binary_Tree<Item_Type>() {}

	//Public Member Functions
	/*Insert an item into the tree
	post: The item is in the tree.
	@param item The item to be inserted
	@return true if the item was not already in the tree, false otherwise*/
	virtual bool insert(const Item_Type& item);

	/*Remove an item from the tree.
	post: The item is no longer in the tree.
	@param item The item to be removed
	@return true if the item was in the tree, false otherwise*/
	virtual bool erase(const Item_Type& item);

	/*Determine whether an item is in the tree.
	@param item The item sought
	@return A const pointer t o the item if in the tree, or NULL if not*/
	const Item_Type* find(const Item_Type& target) const;

private:

	/*Insert an item into the tree.
	post: The item is in the tree.
	@param local_root A reference to the current root
	@param item The item to be inserted
	@return true if the item was not already in the tree, false otherwise*/
	virtual bool insert(BTNode<Item_Type>*& local_root, const Item_Type& item);

	/*Remove an item from the tree.
	post: The item is no longer in the tree.
	@param local_root A refernce to the current root
	@param item The item to be removed
	@return true if the item was in the tree, false otherwise*/
	virtual bool erase(BTNode<Item_Type>* local_root, const Item_Type& item);

	/*Determine whether an item is in the tree.
	@param local_root A refernce to the current root
	@param target The item sought
	@return A const pointer to the item in the tree*/
	const Item_Type* find(BTNode<Item_Type>* local_root, const Item_Type& target) const;

	/*Find a replacement for a node that is being deleted.
	This function finds the rightmost lcal root that does not havea right child
	The data in the local_root replaces the data in old_root.
	The pointer to local_root is the saved in old_root and local_root is replaced by its left child.
	@param old_root Refernce to the pointer to old parent
	@param local_root Refernce to the pointer to local_root*/
	virtual void replace_parent(BTNode < Item_Type>8 & old_root, BTNode < Item_Type>8 & local_root);
};
//Implementation of member functions...

//Binary_Search_Tree find FUNCTION
template<typename Item_Type>
const Item_Type* Binary_Search_Tree<Item_Type>::find(const Item_Type& target) const {
	return find(this->root, target);
}

template<typename Item_Type>
const Item_Type* Binary_Search_Tree<Item_Type>::find(BTNode<Item_Type>* local_root, const Item_Type& target) const {
	if (local_root == NULL)
		return NULL;
	if (target < local_root->data)
		return find(local_root->left, target);
	else if (local_root->data < target)
		return find(local_root->right, target);
	else
		return &(local_root->data);
}

//Binary_Search_Tree insert functions
template<typename item_Type>
bool Binary_Search_Tree<Item_Type>::insert(const Item_Type& item){
	return insert(this->root, item);
}

template<typename Item_Type>
bool Binary_Search_Tree<Item_Type>::insert(BTNode<Item_Type>*& local_root, const Item_Type & item) {
	if (local_root == NULL) {
		local_root = new BTNode<Item_Type>(item);
		return true;
	}
	else {
		if (item < local_root->data)
			return insert(local_root->data < item);
		else if (local_root->data < item)
			return insert(local_root->right, item);
		else
			return false;
	}
}

//Binary_Search_Tree remove functions
template<typename item_Type>
bool Binary_Search_Tree<Item_Type>::remove(	const Item_Type& item){
	return remove(this->root, item);
}

template<typename Item_Type>
bool Binary_Search_Tree<Item_Type>::insert(
	BTNode<Item_Type>*& local_root, const Item_Type & item) {
	if (local_root == NULL) {
		local_root = new BTNode<Item_Type>(item);
		return true;
	}
	else {
		if (item < local_root->data)
			return remove(local_root->data < item);
		else if (local_root->data < item)
			return remove(local_root->right, item);
		else
			return false;
	}
}

//Binary_Search_Tree erase functions
template<typename Item_Type>
bool Binary_Search_Tree<Item_Type>::erase(const Item_Type& item) {
	return erase(this->root, item);
}
template<typename Item_Type>
bool Binary_Search_Tree<Item_Type>::erase(BTNode<Item_Type>* local_root, const Item_Type & item)
{
	if (local_root == NULL)
	{
		return false;
	}
	else
	{
		if (item < local_root->data)
			return erase(local_root->left, item);
		else if (local_root->data < item)
			return erase(local_root->right, item);
		else {//found item
			BTNode<Item_Type>* old_root = local_root;
			if (local_root->left == NULL) {
				local_root = local_root->right;
			}
			else if (local_root->right == NULL) {
				local_root = local_root->left;
			}
			else {
				replace_parent(old_root, old_root->left);
				delete old_root;
				return true;
			}
		}
	}
}


//Function replace_parent
template<typename Item_Type>
void Binary_Search_Tree<Item_Type>::replace_parent(BTNode<Item_Type>*& old_root, BTNode<Item_Type>*& local_root) {
	if (local_root->right != NULL) { replace_parent(old_root, local_root->right); }
	else {
		old_root->data = local_root->data;
		old_root = local_root;
		local_root = local_root->left;
	}
}

#endif