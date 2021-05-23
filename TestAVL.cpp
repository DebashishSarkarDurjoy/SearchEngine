#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include <string>
#include <map>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

struct DATA
{
	string key;
	int frequency;
	set<pair<string, int> > info;;
};

void print(DATA ss) {
	cout << ss.key <<  ", " << ss.frequency <<  ", " << endl;
	for (auto e: ss.info) {
		cout << "(" << e.first << ", ";
		cout << e.second <<  ")" << endl;
	}
  cout << endl;
}

#include "AVL_ADT.h"
#include "ReadNBuild.h"

int menu(void);
void deleteLowF(AvlTree<DATA, string>* tree);

int main(void) {
	int input;
	AvlTree<DATA, string> tree;
	while( 1 ) {
		input = menu();
		switch(input) {
			case 1: readNBuild(&tree); break;
			case 2: tree.AVL_Traverse(print); break;
			case 3: tree.AVL_Print(); break;
			case 4: cout << "in progress...."; break;
			case 5: cout << "in progress...."; break;
			case 6: cout << "in progress...."; break;
			case 7: cout << "in progress...."; break;
			case 8: cout << "in progress...."; break;
			case 9: deleteLowF(&tree); break;
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

void deleteLowF(AvlTree<DATA, string>* tree) {
	vector<string> toDelete;
	double threshold;

	cout << "Enter threshold: ";
	cin >> threshold;

	tree->AVL_Traverse(&toDelete, threshold);

	cout << "Deleted: " << endl;
	for (auto e: toDelete) {
		cout << e << endl;
		tree->AVL_Delete(e);
	}

}
