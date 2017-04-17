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
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

// getString - read a string of input from the user prompt
//             and return it to the caller

char* getString(istream& cin)
{
  char buffer[64];

  // now input a string from the file
  cout << endl << "Reading input from a file into a buffer of 64 bytes"<< endl;
  char* pB;
  for(pB = buffer;*pB = cin.get(); pB++)
    {
       if (cin.eof())
         {
            break;
        }
    }
  *pB = '\0';
  cout << "file was read into the buffer"<< endl;  
  // return a copy of the string to the caller
  pB = new char[strlen(buffer) + 1];
  strcpy(pB, buffer);
  return pB;
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
  char* pB = getString(c);

  // output the content that we got in from  that file 
  cout << "\nWe successfully read in the following content:\n" << pB << endl;

  cout << "Press Enter to continue..." << endl;
  cin.ignore(10, '\n');
  cin.get();
  printf("Done, without any problems!");
  exit(0);
  return 0;
}
