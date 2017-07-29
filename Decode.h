//CS 303
//Dr. Mohammed Kuhail
//Project 2: Morse Code
//Michael Essmyer
//Alandric Jones
//Jason Pucilowski

#pragma once

#include <map>
#include <vector>
#include <iostream>
#include <string>
#include <sstream> //fin to string to fout

using namespace std;

//stack overflow
template < string key,             // map::key_type
	string item>                       // map::mapped_type
class Decode{
private:
	vector<std::string> Keys;
	string Morse;
	string Letter;
	static map<string, string> DecodePair; //map<morse, letter>
public:
	template < class Key, class T>
	Decode() //basic contructor for the Encode map
	{
		DecodePair["._"] = "a";
		DecodePair["_..."] = "b";
		DecodePair["_._."] = "c";
		DecodePair["_.."] = "d";
		DecodePair["."] = "e";
		DecodePair[".._."] = "f";
		DecodePair["__."] = "g";
		DecodePair["...."] = "h";
		DecodePair[".."] = "i";
		DecodePair[".___"] = "j";
		DecodePair["_._"] = "k";
		DecodePair["._.."] = "l";
		DecodePair["__"] = "m";
		DecodePair["_."] = "n";
		DecodePair["___"] = "o";
		DecodePair[".__."] = "p";
		DecodePair["__._"] = "q";
		DecodePair["._."] = "r";
		DecodePair["..."] = "s";
		DecodePair["_"] = "t";
		DecodePair[".._"] = "u";
		DecodePair["..._"] = "v";
		DecodePair[".__"] = "w";
		DecodePair["_.._"] = "x";
		DecodePair["_.__"] = "y";
		DecodePair["__.."] = "z";
		DecodePair["_____"] = "0";
		DecodePair[".____"] = "1";
		DecodePair["..___"] = "2";
		DecodePair["...__"] = "3";
		DecodePair["...._"] = "4";
		DecodePair["....."] = "5";
		DecodePair["_...."] = "6";
		DecodePair["__..."] = "7";
		DecodePair["___.."] = "8";
		DecodePair["____."] = "9";
	}
	//Map Constructor
	template < class Key, class T>
	Decode(string Morse, string Letter) {
		pair<string, string> DecodePair;
		DecodePair[Morse] = Letter;
		Keys += Morse;
	}
	//take information from file and turn it into a usable string
	void MakeDecode(ifstream fin)
	{	//Input File
		string info, line;
		while (fin.good()) {
			fin >> line;
			//info = getStream(line);
			cout << line << endl;
			insertCode(line);
		}
	}
	//overload []
	DecodePair& operator [](const string key) {
		pair<iterator, bool>ret = the_set.insert
	}

	//make decoding map
	void insertCode(string info)
	{
		string morse, letter, temp;
		for (string::iterator it = info.begin(); it != info.end(); ++it) {
			temp = *it;
			if (isletter(temp)) letter = temp;
			if (ismorse(temp)) morse += temp;
		}
		DecodeMap(morse, letter);
		morse = "";
	}

	//convert stream to string and output individual letters
	string getStream(ifstream instream) {
		return instream.to_string(); //convert fstream into string: from stack overflow
	}
	//Overloading to_string() so that string is converted to ostream to the screen
	ostream to_string(string thestring) const {
		ostringstream os;
		os << thestring;
		return os;
	}
	//Overloading to_string() convert string of morse code to ofstream to a file
	string to_string(ifstream thestring) const {
		ostringstream os;
		os << instring;
		return os.str();
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	bool isletter(string character)
	{
		if (character.find("abcdefghijklmnopqrstuvwxyz1234567890")) return true;
		else
			return false;
	}
	bool ismorse(string character)
	{
		if (character.find(".*.-_")) return true;
		else
			return false;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	////read out morse code of file input
	//string decode(ifstream in)
	//{
	//	string letters;
	//	letters = getStream(in); //convert ifstream to string of letters
	//	string morseCode;
	//	for (string::iterator<string>* it = letters.begin(); it != letters.end(); ++it)
	//	{
	//		morseCode += DMap[*it];

	//	}
	//	return morseCode;
	//}
	//read out morse code of file input
	ostream decode(ifstream in)
	{
		string letters;
		letters = getStream(in); //convert ifstream to string of letters
		string morseCode;
		for (string::iterator<string>* it = letters.begin(); it != letters.end(); ++it)
		{
			morseCode += EMap[*it];

		}
		return to_string(morseCode);
	}
	////read out morse code of string input
	//string decode(string in)
	//{
	//	string letters;
	//	letters = in; //convert ifstream to string of letters
	//	string morseCode;
	//	for (string::iterator<string>* it = letters.begin(); it != letters.end(); ++it)
	//	{
	//		morseCode += DMap[*it];

	//	}
	//	return morseCode;
	//}
	//read out morse code of file input
	ostream decode(string in)
	{
		string letters;
		letters = in; //convert ifstream to string of letters
		string morseCode;
		for (string::iterator<string>* it = letters.begin(); it != letters.end(); ++it)
		{
			morseCode += EMap[*it];

		}
		return to_string(morseCode);
	}

	//convert stream to string and output individual letters
	string getStream(ifstream instream) {
		return instream.to_string(); //convert fstream into string: from stack overflow
	}
	//convert string of morse code to ostream
	//Overloading to_string() so that string is converted to ostream to the screen
	//ostream to_string(string thestring) const {
	//	ostringstream os;
	//	os << thestring;
	//	return os;
	//}
	//Overloading to_string() convert string of morse code to ofstream to a file
	ostream to_string(string thestring) const {
		ostringstream os;
		os << instring;
		return os.str();
	}



};
//template <class InputIterator>
//map Encode(InputIterator first, InputIterator last,
//	const key_campare& comp = key_compare(),
//	const allocator_type& alloc = allocator_type());

//Decode::Decode(ifstream fin) //basic contructor for the Encode map
//{//reads the morse input file and creates a map where key:letter<char> and item:morse<string> 
//	string morsecode, inputline, temp; //morsecode = dot/dash, inputline <= fstream
//	string key; //breakup string into characters either letter or number
//	while (fin.good()) //while there is data in the file
//	{
//		getline(fin, inputline); //get the first line a.-
//		for (int i = 0; i <= inputline.size(); ++i)
//		{
//			temp = inputline[i];
//			if (isletter(temp)) //check to see if letter or number and not morse code
//			{
//				key = temp;
//			}
//			if (ismorse(temp))//check to see if morse code and not a letter or a number
//			{
//				morsecode += temp;
//			}
//
//		}
//		DecodedMap.insertCode(morsecode, key); //insert this piece of code into the map
//		morsecode = ""; //reset the morse code 
//	}//end of file
//	fin.close();//close the file
//}