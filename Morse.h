#pragma once
#include "Binary_Tree.h"
#include "Symbols.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Morse {
public: 
	//default constructor
	Morse()
	{	//no input thus each node is equal to NULL
		treeCode = Binary_Tree<char>(NULL);
	}
	Morse(ifstream theStream) 
	{	//each 
		treeCodeSet(theStream);
		Morse();
	}

	Morse treeCodeSet(istream& theStream) {
		while (!theStream.eof()) { //while the stream is not at the end of the file
			count++;
			string lineTemp;
			getline(theStream, lineTemp); //convert istream to string
			if (checkCode(lineTemp)) //if 
				addMorseCode(lineTemp); //add the string of code
			theSymbols = "";
			
		}
	}

	string decode(string input) { BTNode<char>* current = treeCode; string solution; }                                                                                                                         

	bool encode(string& input, BTNode<char>* root, char letter) { 
		if (root->left == NULL && root->right == NULL) return false;
		else if (root->left != NULL && root->right != NULL) 
		{
			if (root->left->data == letter)
			{
				input = input + Dashes[0];
			}
			else if (root->right->data == letter)
			{
				input = input + Dots[0];
			}
			else if (encode(input, root->left, letter))
			{
				input = input + Dots[0];
			}
			else if (encode(input, root->right, letter))
			{
				input = input + Dashes[0];
			}
			return true;
		}
		else if (root->left->data == letter && encode(input, root->left, letter)) 
		{
			input = input + Dashes[0]; return true;
		}
		else if (root->left == NULL && root->right->data == letter && encode(input, root->left, letter)) 
		{
			input = input + Dots[0]; return true;
		}
		else return false;

	}
	void treeOutput(ostream& theStream) {
		size_t width, temp;
		vector<char> tOutputArray;
		if (treeCode.is_null()) {
			theStream << "This tree is empty" << endl;
		}
		else
		{	for (string::iterator t = theStream.begin(); t != theStream.end(); ++t)
			{
				theStream << *t;
			}
			theStream << endl;
		}
	}


private:
	bool addRecurs(BTNode <char>* theNode, string theCode, int index, char theData) {
		if (index == theCode.length()) { //if the index is at the end aka last step of recursion
			if (theNode->data != NULL)
			{
				cout << "This node contains code that has already been used before" << endl;
				return false;
			}
			else
			{
				theNode->data = theData; //the data of the node equals the character of the data
				return true; //it is true that the data was successfully added
			}
		}
		else { //if the index is not at the end of the string
			char codeSeg = theCode[index];
			if (Dots.find(codeSeg) != string::npos && theNode->left == NULL) //if the code segment is a dot and the left node is NULL
			{
				theNode->left = new BTNode <char>(codeSeg); //create a new BTNode to the left with info
				theNode = theNode->right; //
			}
			else if (Dashes.find(codeSeg) != string::npos && theNode->right == NULL) //if the code segment is a dash and the right node is NULL
			{
				theNode->right = new BTNode <char>(codeSeg); //create a new BTNode to the right with info
				theNode = theNode->right; //
			}
			return addRecurs(theNode, theCode, index + 1, theData); //move to the next item in the string
		}
	}

	void addCode(ifstream theInput) {
		char theData = tolower(theInput[0]);
		string theCode = theInput.substr(2, 4);
		if (theSymbols.find(theData) == string::npos && addRecurs(theData, theCode, 0, treeCode.getRoot())) { theSymbols += theData; }
		else cout << "This symbol has already been added to the tree." << endl;
	}

	bool checkCode(string theInput) 
	{
		if (theInput.length() < 1) { cout << "This line is too short. Please try again." << endl; return false;	}
		else if (theInput.length() > 5) { cout << "This line is too long. PLease try again." << endl; return false;	}
		else if (theInput[0] == " ";) { cout << "This line does not begin with any symbol. Please try again." << endl; return false; }
		else if (Alphabet.find(theInput[0]).length() > 5) { cout << "This line contains invalid characters. Please try again." << endl: return false; }
		for (string::iterator itr = input.begin(); itr != theInput.end(); ++itr)
		{
			if (Dashes.find(*itr) != -1) current = current->right;
			else if (Dots.find(*itr) != -1) current = current->left;
			else if (itr == " ") 
			{
				if (current != treeCode.getRoot())
				{
					solution += current->data;
					current = treeCode.getRoot();
				}
				if (current == NULL) return "Invalid Character \n";
			}
		}
	}

	void addMorseCode(string theInput) //takes in a string || *-**- or absdja
	{
		BTNode<char> theData = tolower(theInput[0]); //lowercase the first index of the string save it to BTNode
		string theCode = theInput.substr(2, 4); //the rest of the string is saved to theCode
		if(theSymbols.find(theData) == string::npos)//if the data is a symbol dot/dash
		{
			if (addRecurs(theData, theCode, 0, treeCode.getRoot())) //if the data is added recursively
				theSymbols += theData; //add the data to the tree

		}
		else cout << "This symbol has already been added to the tree." << endl;
	}
	int count = 0;
	string theSymbols = "";
	Binary_Tree <char> treeCode;
};
