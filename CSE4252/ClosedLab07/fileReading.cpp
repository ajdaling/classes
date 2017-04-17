/****************************************

This program does ............


*********************************************/
#include <iostream>
#include <fstream>	// for file operations
#include <stdlib.h> 	// for exit() functions
#include <vector>
#include <list>


using namespace std;


int main()
{

  ifstream readFile;
  ofstream writeFile;

  readFile.open("droneDatabase.txt",ios::in);
  if (!readFile.is_open()) {
    cerr << "Unable to open file "<< readFile << endl;
      exit(10);
    }

  writeFile.open("outFile.txt",ios::out);
  if (!writeFile.is_open()) {
    cerr << "Unable to open file "<< writeFile << endl;
      exit(10);
    }

  string mydata;
  while(! readFile.fail() && ! writeFile.fail()) {
    getline(readFile, mydata);
    writeFile << mydata << endl;
  }
  
  readFile.close();
  writeFile.close();
}


