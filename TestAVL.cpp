#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include <string>
#include <map>
#include <fstream>

using namespace std;

struct DATA
{
	string key;
	int frequency;
	map<string, int> info;
};

#include "AVL_ADT.h"
#include "ReadNBuild.h"

int menu(void);

int main(void) {
	int input;
	AvlTree<DATA, int> tree;
	while( 1 ) {
		input = menu();
		switch(input) {
			case 1: readNBuild(&tree); break;
			case 2: cout << "in progress...."; break;
			case 3: cout << "in progress...."; break;
			case 4: cout << "in progress...."; break;
			case 5: cout << "in progress...."; break;
			case 6: cout << "in progress...."; break;
			case 7: cout << "in progress...."; break;
			case 8: cout << "in progress...."; break;
			case 9: cout << "in progress...."; break;
			case 0: return 0;
		}
	}

	return 0;
}

int menu(void) {
	cout << "\n\n--------------------------------------\n";
	cout << "Choose one of the following functions: " << endl;
	cout << "1. Learn an index dictionary from a file (without phrases)." << endl;
	cout << "2. Print the index dictionary. " << endl;
	cout << "3. Print the AVL tree of the dictionary." << endl;
	cout << "4. Output the dictionary to a text file." << endl;
	cout << "5. Load dictionary from a file." << endl;
	cout << "6. Learn an index dictionary from a set of files (without phrases)." << endl;
	cout << "7. Input a word with input suggestions." << endl;
	cout << "8. Learn an index dictionary from a file (with phrases)." << endl;
	cout << "9. Delete low frequency words from the dictionary." << endl;
	cout << "0. Quit." << endl;
	cout << "--------------------------------------\n\n";
	cout << ">>";

	int n;
	cin >> n;
	return n;

}
