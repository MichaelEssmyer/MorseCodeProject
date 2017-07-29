//CS 303
//Dr. Mohammed Kuhail
//Project 2: Morse Code
//Michael Essmyer
//Alandric Jones
//Jason Pucilowski

#pragma once

#include <map>	//data structure
#include <string>	//keys and items
#include <iostream> //cin and cout
#include <fstream> //fin and fout
#include <sstream> //fin to string to fout

using namespace std;

template < string key,             // map::key_type
	string item>                       // map::mapped_type
class Encode{

private:
	vector<string> Keys;
	string Morse;
	string Letter;
	static map<string, string> EncodePair;

public:
	//Contructors
	// Basic constructor made by hard coding aka has numbers!!
	template < string key, string item>
	Encode() //basic contructor for the Encode map:map<letter, morse>
	{ //hard coded.... so that way file input could be an essay and does not have to be the actual morse code
		EncodePair["a"] = "._";
		EncodePair["b"] = "_...";
		EncodePair["c"] = "_._.";
		EncodePair["d"] = "_..";
		EncodePair["e"] = ".";
		EncodePair["f"] = ".._.";
		EncodePair["g"] = "__.";
		EncodePair["h"] = "....";
		EncodePair["i"] = "..";
		EncodePair["j"] = ".___";
		EncodePair["k"] = "_._";
		EncodePair["l"] = "._..";
		EncodePair["m"] = "__";
		EncodePair["n"] = "_.";
		EncodePair["o"] = "___";
		EncodePair["p"] = ".__.";
		EncodePair["q"] = "__._";
		EncodePair["r"] = "._.";
		EncodePair["s"] = "...";
		EncodePair["t"] = "_";
		EncodePair["u"] = ".._";
		EncodePair["v"] = "..._";
		EncodePair["w"] = ".__";
		EncodePair["x"] = "_.._";
		EncodePair["y"] = "_.__";
		EncodePair["z"] = "__..";
		EncodePair["0"] = "_____";
		EncodePair["1"] = ".____";
		EncodePair["2"] = "..___";
		EncodePair["3"] = "...__";
		EncodePair["4"] = "...._";
		EncodePair["5"] = ".....";
		EncodePair["6"] = "_....";
		EncodePair["7"] = "__...";
		EncodePair["8"] = "___..";
		EncodePair["9"] = "____.";

	}
	//Map Constructor
	template < string key, string item>
	Encode<string, string>(string Letter, string Morse) {
		pair<std::string, std::string> EncodePair;
		EncodePair[Morse] = Letter;
		Keys += Morse;
	}
	//take information from file and turn it into a usable string
	void MakeEncode(ifstream fin)
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
	DecodePair& operator [](const std::string key) {
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
		EncodeMap(letter, morse);
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
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	////read out morse code of file input
	//string encode(ifstream in)
	//{	
	//	string letters;
	//	letters = getStream(in); //convert ifstream to string of letters
	//	string morseCode;
	//	for (string::iterator<string>* it = letters.begin(); it != letters.end(); ++it)
	//	{
	//		morseCode += EMap[*it];

	//	}
	//	return morseCode; 
	//}
	//read out morse code of file input
	ofstream encode(ifstream in)
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
	//string encode(string in)
	//{
	//	string letters;
	//	letters = getStream(in); //convert ifstream to string of letters
	//	string morseCode;
	//	for (string::iterator<string>* it = letters.begin(); it != letters.end(); ++it)
	//	{
	//		morseCode += EMap[*it];

	//	}
	//	return morseCode;
	//}
	//read out morse code of string input
	ofstream encode(string in)
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

	//convert stream to string and output individual letters
	string getStream(ifstream instream) {
		return instream.to_string(); //convert fstream into string: from stack overflow
	}
	//convert string of morse code to ofstream
	//Overloading to_string() so that string is converted to ostream to the screen
	//ofstream to_string(string thestring) const {
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



}; //end of map

   ////Overloading to_string(): cplusplus.com
   //string to_string(fstream instream) const {
   //	ostringstream os;
   //	os << instream;
   //	return os.str();
   //}

   ////Overloading the ostream insertion operator
   //template<typename Item_Type>
   //ostream& operator<<(ostream& out,
   //	const EncodedMap<Item_Type>& node) {
   //	return out << node.to_string();
   //}

   ////convert strings into individual letters
   //string searchLetter(string instring) {
   //	for (string::iterator istr = instring.begin(); istr != instring.end(); ++istr)//iterate through string of characters
   //		{
   //			char searchchar = *istr;
   //			find morse code for each letter
   //				outputstring += EncodeMap.find(searchchar);
   //			search map for string char and add string of morse code to the output string
   //				outputstring += " "; //add space delimiter
   //		}
   //	return outputstring; //output string of morse code
   //}





//   //made by the input file
//static map<const string, const string> EncodedMap(ifstream emorse) //basic contructor for the Encode map:map<letter, morse>
//{//reads the morse input file and creates a map where key:letter<char> and item:morse<string> 
//	string morsecode, inputline; //morsecode = dot/dash, inputline <= fstream
//	char key; //breakup string into characters either letter or number
//	while (emorse.good()) //while there is data in the file
//	{
//		getline(emorse, inputline); //get the first line a.-
//		for (int i = 0; i <= inputline.size(); ++i)
//		{
//			if (isletter(tolower(initr[i]))) //check to see if letter or number and not morse code
//			{
//				key = initr[i];
//			}
//			if (ismorse(initr[i]))//check to see if morse code and not a letter or a number
//			{
//				morsecode += initr[i];
//			}
//
//		}
//		EncodedMap.insertCode(key, morsecode); //insert this piece of code into the map
//		morsecode = ""; //reset the morse code 
//	}//end of file
//	fin.close();//close the file
//}
//bool isletter(string character)
//{
//	if (character == find("abcdefghijklmnopqrstuvwxyz1234567890")) return true;
//	else
//		return false;
//}
//bool ismorse(string character)
//{
//	if (character == find(".*.-_")) return true;
//	else
//		return false;
//}
////make encoding map
//EncodedMap insertCode(string key, string morse)
//{
//	EMap[key] = morse;
//}

   /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
