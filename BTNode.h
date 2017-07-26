#ifndef BTNODE_H_
#define BTNODE_H_
#include <sstream>
using namespace std; 

/** A node for Binary_Tree. */
template<typename Item_Type>
struct BTNode //each node
{
	// Data Fields
	Item_Type data; //char letter/number
	BTNode<Item_Type>* left; //Dots
	BTNode<Item_Type>* right; //Dash

	// Constructor
	BTNode(const Item_Type& the_data, //const char 
		BTNode<Item_Type>* left_val = NULL, //dot
		BTNode<Item_Type>* right_val = NULL) : //dash
		data(the_data), left(left_val), right(right_val) {} //BTNode(data): dot, dash

	// Destructor (to avoid warning message)
	virtual ~BTNode() {} //destroys node

	// to_string: sets code to to output
	/*string str() const;
	void str (const string& s);
		Get/set content
		The first form (1) returns a string object with a copy of the current contents of the stream. *the one we used

		The second form (2) sets s as the contents of the stream, discarding any previous contents. The object preserves its open mode: if this includes ios_base::ate, the writing position is moved to the end of the new sequence.

		Internally, the function calls the str member of its internal string buffer object.
		http://www.cplusplus.com/reference/sstream/stringstream/str/*/
	virtual string to_string() const { //reads data to ostream
		ostringstream os; //define ostream variable
		os << data; // read data from node int ostream 
		return os.str(); //returns ostream as string
	}
}; // End BTNode

   // Overloading the ostream insertion operator
   // node data as string
   // ostream out equals node data
template<typename Item_Type>
ostream& operator<<(ostream& out, const BTNode<Item_Type>& node) {
	return out << node.to_string();
}

#endif
