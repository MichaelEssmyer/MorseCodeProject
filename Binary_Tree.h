#ifndef BINARY_TREE_H
#define BINARY_TREE_H

//Class for a binary tree
#include <cstddef>
#include <sstream>
#include <stdexcept>
#include <string>
#include "BTNode.h"

template<typename Item_Type>
class Binary_Tree
{
public:
	// Constructors and Functions
	/** Construct an empty Binary_Tree. */
	Binary_Tree() : root(NULL) {}

	/** Construct a Binary_Tree with two subtrees.
	@param the_data The data at the root
	@param left_child The left subtree
	@param right_child The right subtree
	*/
	Binary_Tree(const Item_Type& the_data,
		const Binary_Tree<Item_Type>& left_child
		= Binary_Tree(),
		const Binary_Tree<Item_Type>& right_child
		= Binary_Tree()) :
		root(new BTNode<Item_Type>(the_data, left_child.root,
			right_child.root)) {}

	/** Virtual destructor to avoid warnings */
	virtual ~Binary_Tree() {} // Do nothing.


	Binary_Tree<BTNode> getRoot() { return root; }

	/** Return the left subtree. */
	Binary_Tree<BTNode> get_left_subtree() const{
	if (root == NULL){throw std::invalid_argument("get_left_subtree on empty tree");}
	return Binary_Tree<BTNode>(root->left);}


	/** Return the right subtree. */
	Binary_Tree<BTNode> get_right_subtree() const{
	if (root == NULL){throw std::invalid_argument("get_right_subtree on empty tree");}
	return Binary_Tree<BTNode>(root->right);}

	/** Indicate that this is the empty tree. */
	bool is_null() const
	{
		if (Data == NULL) return true;
		else
			return false
	}

	/** Indicate that this tree is a leaf. */
	bool is_leaf() const
		template<typename Item_Type> bool Binary_Tree<BTNode>::is_leaf() const
	{
		if (root != NULL) return std::invalid_argument;
		else if (root->left == NULL && root->right == NULL) { return true; }
		else return false;
	}

	/** Return a string representation of this tree. */
	virtual template<typename Item_Type>
	std::string Binary_Tree<Item_Type>::to_string() const{
	std::ostringstream os;
	if(is_null())
		os << "NULL \n";
	else
		{os << *root << '\n';
		os << get_left_subtree().to_string();
		os << get_right_subtree().to_string();}

	return os.str();
	}

	/** Read a binary tree */
	static template<typename Item_Type>
	Binary_Tree<Item_Type>:: read_tree(std::istream& in){
	std::string next_line;
	getline(in, next_line);
	if(next_line == "NULL"){return Binary_Tree<Item_Type>();}
	else
		{
		Item_Type the_data;
		std::istringstream ins(next_line);
		ins >> the_data;
		if(the_data->left != NULL) Binary_Tree<Item_Type> left = read_tree(in);
		else if(the_data->right != NULL) Binary_Tree<Item_Type> right = read_tree(in);
		return Binary_Tree<Item_Type>(the_data, left, right);}
	}

	//Overloading the ostream insertion operator
	template<typename Item_Type>
	std::ostream& operator <<(std::ostream& out, const Binary_Tree < Item_Type& Tree) {return out << tree.to_string}

	//Overloading the istream extraction operator
	template<typename Item_Type>
	std::istream& operator >> (std::istream& in, Binary_Tree<Item_Type>& tree) { tree = Binary_Tree<Item_Type>::read_tree(in); return in; }

	//set the root
	template<typename Item_Type>
	void Binary_Tree <Item_Type>::setRoot(BTNode<Item_Type>* newRoot) { root = newRoot; }

	//get the root
	template<typename Item_Type>
	void BTNode<Item_Type>* Binary_Tree<Item_Type>:: getRoot() { return root; }

	//reads out the binary tree
	template<typename Item_Type>
	void Binary_Tree<Item_Type>::read_binary_tree(std::vector<std::string>& text) {
		int in = 0;
		Binary_Tree<Item_Type> newTree = read_tree(text, in);
		setRoot(newTree.getRoot());
	}

	//reads tree if tree has data
	template<typename Item_Type>
	void Binary_Tree<Item_Type>::read_tree(std::vector<std::string>& text, int& i){
		if (in > text.size() - 1 || text[i] == "NULL") {
			return Binary_Tree<Item_Type>();
		}
		else {
			std::string txt = text[in];
			Binary_Tree < Item_Type> left = read_tree(text, ++i);
			Binary_Tree<Item_Type> right = read_tree(text, ++i);
			return Binary_Tree<Item_Type>(text, left, right);
		}
	}

	//reads tree if tree needs data
	template<typename Item_Type>
	void Binary_Tree<Item_Type>::read_tree(std::istream& in){
		std::string next_line;
		getline(in, next_line);
		if (next_line == "NULL") {
			return Binary_Tree<Item_Type>();
		}
		else {
			Item_Type the_data;
			std::istringstream ins(next_line);
			ins >> the_data;
			Binary_Tree<Item_Type> left = read_tree(in);
			Binary_Tree<Item_Type> right = read_tree(in);
			return Binary_Tree<Item_Type>(the_data, left, right);
		}
	}


	/** Return a string representation of the root */
	std::string root_to_string() const {
		return root->to_string();
	}

	/** Return a pre-order traversal of the tree */
	std::string pre_order() const {
		return pre_order(root);
	}

	/** Return a post-order traversal of the tree */
	std::string post_order() const {
		return post_order(root);
	}

	std::string in_order() const {
		return in_order(root);
	}

	//greatest height
	int getHeight() const {
		if (is_null()) return 0;
		return 1 + std::max(get_left_subtree().getHeight(), get_right_subtree().getHeight());
	}

	//number of nodes
	int number_of_nodes() const {
		if (is_null()) return 0;
		return 1 + get_left_subtree().number_of_nodes()
			+ get_right_subtree().number_of_nodes();
	}
protected:

	// Protected constructor
	/** Construct a Binary_Tree with a given node as the root */
	Binary_Tree(BTNode<Item_Type>* new_root) : root(new_root) {}

	// Data Field
	BTNode<Item_Type>* root;

private:

	std::string pre_order(const BTNode<Item_Type>* local_root) const
	{
		std::string result;
		if (local_root != NULL) {
			result += local_root->to_string();
			if (local_root->left != NULL) {
				results += " ";
				results += pre_order(local_root->left);
			}
			if (local_root->right != NULL) {
				results += " ";
				results += pre_order(local_root->right);
			}
		}
		return result;
	}

	std::string post_order(const BTNode<Item_Type>* local_root) const
	{
		std::string result;
		if (local_root != NULL) {
			result += local_root->to_string();
			if (local_root->left != NULL) {
				results += post_order(local_root->left);
				results += " ";
			}
			if (local_root->right != NULL) {
				result += post_order(local_root->right);
				results += " ";
			}
		}
		return result;
	}

	std::string in_order(const BTNode<Item_Type>* local_root) const
	{
		std::string result;
		if (local_root != NULL) {
			result += "(";
			if (local_root->left != NULL) {
				results += in_order(local_root->left);
				results += " ";
			}
			if (local_root->right != NULL) {
				result += in_order(local_root->right);
				result += " ";
			}
			result += ") ";
		}
		return result;
	}

};  // End Binary_Tree

#endif
