//CS 303
//Dr. Mohammed Kuhail
//Project 2: Morse Code
//Michael Essmyer
//Alandric Jones
//Jason Pucilowski

#include<map>
#include<fstream>
#include<iostream>
#include <string>
#include "Decode.h"
#include "Encode.h"

using namespace std;

int main()
{
	string input; //input code into
	bool run = true; //control the while loop

	ifstream fin("morse.txt"); //morse.txt input to create tree
	template < string key, string item>
	Encode<string, string> eMap.MakeEncode(fin); //create the encoder map: key = letter & item = morse
	template < string key, string item>
	Decode<string, string> dMap.MakeDecode(fin); //create the decoder  map: key = morse & item = letter 


	string tofile;
	ofstream fout; //output.txt output of the endoded or decoded string
	string toscreen;

	string inputString; //input from user
	

	cout << "Welcome to the morse code project. \n";

	while (run)//while exit is not selected
		{
		//cout << "Do you wish to outnput to a file [y] or to the screen[n]?";
		//cin >> tofile;
		cout << "Please input the number for the respected program. \n";
		cout << "1: Decode a message from a file. \n";
		cout << "2: Encode a message from a file. \n";
		cout << "3:  Exit. \n";
		//cout << "4: Encode a message from the user. \n";
		//cout << "5:
		int option = 0; //input selection of switch case
		cin >> option;
		if (option >= 1 && option <= 5)
		{
			string Userfile1;
			string Userfile2;
			ifstream finUser1;
			ifstream finUser2;
			if (option == 1) { //sentence or word of morse code to string format from file
				cout << "Please enter the file you want to decode. \n";
				cin >> Userfile1;
				ifstream finUser1(Userfile1);
				fin.ignore();//read the first space
				getline(finUser1, input);
				fout = dMap.decode(input);
				fout << "The decoded message is: " << fout << endl;
				break;
			}
			if(option == 2) {//sentence or word of string format to morse code from file
				cout << "Please enter the file you want to encode. \n";
				cin >> Userfile2;
				ifstream finUser1(Userfile2);
				fin.ignore();//read the first space
				getline(finUser2, input);
				fout << "The encoded message is: " << eMap.encode(input) << endl;
				break;
				}
			if (option == 3) {
				cout << "Goodbye now!";
				run = false;
				break;
			}
		else cout << "Invalid file selection: make sure it is lower case y or n" << endl;

		}
		
		else
			cout << "Invalid numerical selection..." << endl;
	}
	//outside while
	return 0;
}
//outside main