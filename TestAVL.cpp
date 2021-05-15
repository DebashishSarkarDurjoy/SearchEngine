#include<iostream>
#include<stdlib.h>
#include<iomanip>
#include <string>
#include <map>
#include <fstream>

using namespace std;

#include "AVL_ADT.h"

struct DATA
{
	string key;
	int frequency;
	string source;
};

void print(DATA ss) {
	cout << ss.key <<  ", " << ss.frequency << endl;
}

int main() {
	AvlTree<DATA, int> tree;
	if(tree.AVL_Empty())
		cout << "Empty tree."<< endl;

	string fileName = "test.txt";

	ifstream inFile;
//------open the file---------
	inFile.open(fileName);
  if (!inFile) {
      cout << "Unable to open file";
      exit(1); // terminate with error
  }
//----------------------------


	string x;
	map<string, int> dataBook;

	pair<string, int> p;
	while (inFile >> x) {
    //https://stackoverflow.com/questions/313970/how-to-convert-stdstring-to-lower-case/24063783
    // -----------Trimming----------------
    transform(x.begin(), x.end(), x.begin(), [](unsigned char c){ return tolower(c); });

    for (int i = 0, len = x.size(); i < len; i++)
    {
        if (ispunct(x[i]))
        {
            x.erase(i--, 1);
            len = x.size();
        }
    }
		// ----------Trimming END--------------

		bool isPresent = false;
		for (auto it=dataBook.begin(); it!=dataBook.end(); it++) {
			if (it->first == x) {
				it->second++;
				if (!isPresent) isPresent = true;
			}
		}
		if (!isPresent) {
			p.first = x;
			p.second = 1;
			dataBook.insert(p);
		}

	}

	for (auto it=dataBook.begin(); it!=dataBook.end(); it++) {
		DATA newData;
		newData.key = it->first;
		newData.frequency = it->second;
    tree.AVL_Insert(newData);
  }




	// DATA newItem;
	// newItem.info = "Dongmo";
	// newItem.key = 10;
	// tree.AVL_Insert(newItem);
	//
	// newItem.info = "John";
	// newItem.key = 20;
	// tree.AVL_Insert(newItem);
	//
	// newItem.info = "Jane";
	// newItem.key = 30;
	// tree.AVL_Insert(newItem);
	//
	// tree.AVL_Print();
	//
	// cout<< "More to go ..." << endl;
	//
	// newItem.info = "Daniel";
	// newItem.key = 40;
	// tree.AVL_Insert(newItem);
	// newItem.info = "Michelle";
	// newItem.key = 50;
	// tree.AVL_Insert(newItem);

	tree.AVL_Print();

	cout<<endl;

	tree.AVL_Traverse(print);

	inFile.close();

    return 0;
}
