/* pointersReview.cpp
This program shows different ways to reference and de-reference variables and handle array indexes
and array element access.

Alec Daling
2-15-17
Closed Lab 3


*/

#include <iostream>
using namespace std;

int main()
{

	string days[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

// Try one statement at a time, removing the comment slashes from that line and then executing. Type your
// answers or explanations in the following line (as a comment)

// Print in the screen the address of each position of the array and the content in that position
    cout << "Printing addresses and content of each array element \n";
    //get pointer to first element in days array
    string *days_ref = days;
    //get length of days array
    int length = sizeof(days)/sizeof(days[0]);
    for(int i = 0; i < length; i++){
        cout << "Position " << i << ": " << *(days_ref + i) << "\n";
    }

    //p is pointing to the memory location of the first index of the third element of days, namely ->"Wed"
	string *p = &days[2];				// where is p pointing to?
    //The value of p is some large hex value indication the memory location of days[2]. On my machine, this is 0x7ffcb70bb2c0
    //The memory address of p, on my machine, is 0x7ffcb70bb270
							// What is the value of p, what is the address where p is stored?

    //This line is equivalent to string *p2 = &days[0], creating a pointer to the first index of days
	string *p2 = days;				// What's the result of this line?
	cout << "*p2 is: " << *p2 << ", days[0] is: " << days[0] << ", *days is: " << *days << "\n";

//pRef is an alias of days
//&pRef is the memory location of pRef, which is the same as the memory location for days
	string (&pRef)[6] =days;			// what is pRef?, What is &pRef?
    cout << "pRef[0] is: " << pRef[0] << ", &pRef is: " << &pRef << "\n";
//This line generates a compiler error because it is assigning an int value to an array of string
// 	days= 2000;					//  What's the result of this line?. Is it valid?


//after incrementing p, it now points to "Thu", the third element in days
	cout << "*p before incrementing is: " << *p << "\n";
	++p;						// where is p pointing to?
	cout << "*p after incrementing is: " << *p << "\n";
//q points to the location on the stack after the end of the days array
//trying to dereference q gives a seg fault
	string *q = &days[6];				// where is q pointing to?


//p3 also points to an invalid memory location
	//string *p3 = p + 5;				// where is p3 pointing to?

//newp tries to access an invalid memory location
	//string newp = *(p +4);				// what is the value of newp?

//bestday also tries to access an invalid memory location
	//string bestday = p2[-2];			// what is the value of bestday?
}

