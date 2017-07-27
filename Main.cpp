#include "Morse.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	string input;
	int option;
	bool run = true;
	Morse theMorseTree;
	ifstream fin;
	ofstream fout;

	while(run)
	{
		cout << "Welcome to the morse code project. \n";
		cout << "Please input the number for the respected program. \n";
		cout << "1: Decode a message. \n";
		cout << "2: Encode a message. \n";
		cout << "3: Exit. \n";
		cin >> option;
		switch (option) {
			case 1:
				fin.ignore();//read the first space
				cout << "Please enter the message to decode. \n";
				getline(fin, input);
				fout << "The decoded message is: " << theMorseTree.decode(input) << endl;
				break;
			case 2:
				fin.ignore();//read the first space
				cout << "Please enter the message you wish to encode. \n";
				getline(fin, input);
				fout << "The encoded message is: " << theMorseTree.encode(input, getRoot(theMorseTree)) << endl;
				break;
			case 3:
				cout << "Goodbye now!";
				run = false;
				break;

		}
	}
}
