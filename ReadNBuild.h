#ifndef READ_N_BUILD
#define READ_N_BUILD

void print2(DATA ss) {
	//double perThousand = ( ss.frequency / total ) * 1000;
	cout << ss.key <<  ", " << "perThousand" <<  ", " << endl;
  cout << endl;
}

void readNBuild(AvlTree<DATA, int> *tree) {

	if(tree->AVL_Empty()) cout << "Empty tree."<< endl;

    string fileName;
    cout << "Enter file name: " << endl;
    cin >> fileName;


  	ifstream inFile;
  //------open the file---------
  	inFile.open(fileName);
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
  //----------------------------


  	string x;
    int location = 0;

  	while (inFile >> x) {
      location++;
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

  		DATA newData;
  		newData.key = x;
  		newData.frequency = 1;
      newData.info += "( " + fileName + ", " + to_string(location) + " )\n";

  		tree->AVL_Insert(newData);

  	}


  	tree->AVL_Traverse(print2);

    inFile.close();

}


#endif
