/*
	closedLab07_1.cpp
	Author: Alec Daling
	Date: 4/17/17


// BufferOverflow - this program demonstrates how a
//                  program that reads data into a fixed
//                  length buffer without checking can be
//                  hacked

/*
	results with smallfile.txt:
		Reading input from a file into a buffer of 64 bytes
		file was read into the buffer

		We successfully read in the following content:
		This file is a small file 
		(size < 64 bytes).Bye
		
	results with largefile.txt
		Reading input from a file into a buffer of 64 bytes
		file was read into the buffer

		We successfully read in the following content:
		This file is a small file 
		(size < 64 bytes).Bye
*/

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <iterator>


using namespace std;

/*
	function getString2 - new implementation of getString that prevents
	seg fault from overflow, returns vector of chars
*/
vector<char> getString(istream& cin){
	cout << endl << "Reading input..." << endl;
	vector<char> buff;
	char idx;
	
	while(cin.get(idx)){
		buff.push_back(idx);
	}
	
	if(cin.eof()){
		cout << "end of file reached" << endl;
	} else{
		cout << "error reading file" << endl;
	}
	
	return(buff);
}

void print_vector(vector<char> buff){
	for(vector<char>::iterator it = buff.begin(); it != buff.end(); it++){
		cout << *it;
	}
}


int main()
{
  // get the name of the file to read
  cout <<"This program reads input from an input file\n"
           "Enter the name of the file:   ";
  string fileName;
  cin >> fileName;

  // open the file
  ifstream c(fileName.c_str());
  if (!c)
    {
       cout << "\nError opening input file" << endl;
       exit(-1);
    }

  // Now the program reads the file's content into a string
  //char* pB = getString(c);
  vector<char> pB = getString(c);

  // output the content that we got in from  that file 
  cout << "\nWe successfully read in the following content:\n";
  print_vector(pB);
  cout << endl;

  cout << "Press Enter to continue..." << endl;
  cin.ignore(10, '\n');
  cin.get();
  printf("Done, without any problems!");
  exit(0);
  return 0;
}
