/* This program implements two swapping functions, to show how the passing 
of reference variable between functions and function scope  

*/


/*

Alec Daling
2-15-17
CLosed Lab 3
Answers to Questions:

p_swap:

 What does p_swap receive as parameters?
	p_swap receives as parameters the memory locations of the two int values. 
	
 what is the result of this implementation of swapping two values? 
	This implementation reads in two memory addresses as pointers and uses the * operator to dereference them when performing the swap.

 Does it return the correct swapped values?
	Yes.
	
r_swap:

What does r_swap receive as parameters?
	r_swap receives the two variables v and x.
	
What is the result?
	r_swap creates references to each of the input parameters using the & operator and then employs these reference in the swap.
	
Does it return correct values?
	Yes. 
	
*/

#include <iostream>
using namespace std;

// Function prototypes

void p_swap(int *, int *);
void r_swap(int&, int&);

int main (void){
 int v = 5, x = 10;
 cout << "Initial variable values: " << endl;
 cout << "int v = " << v << " int x = " << x << endl << endl;
 
 cout << "The memory location of v before the call is: " << &v << endl;
 cout << "The memory location of x before the call is: " << &x << endl;
 cout << "These memory addresses are passed as parameters to p_swap()." << endl << endl;
 p_swap(&v,&x);
 cout << "Values after swapping using p_swap(&v,&x): " << endl;
 cout << "value of v= " << v << " value of x= " << x << endl << endl;
 
 	cout << "After the first swap, the memory location of v is: " << &v << endl;
	cout << "After the first swap, the memory location of x is: " << &x << endl;
 
 v = 5;
 x = 10;
 cout << "Initial variable values: " << endl;
 cout << "int v = " << v << " int x = " << x << endl;
 
 cout << "These values are passed in as parameters to r_swap directly." << endl << endl;
 r_swap(v,x);
 cout << "Values after swapping using r_swap(v,x): " << endl;
 cout << "value of v= " << v << " value of x= " << x << endl;
 
  cout << "After the second swap, the memory location of v is: " << &v << endl;
	cout << "After the second swap, the memory location of x is: " << &x << endl;
 
 return 0;
}

void p_swap(int *a, int *b)
{
	cout << "Inside p_swap, the memory addresses passed in as parameters are used to dereference v and x in order to perform the swap" << endl;
 	int temp;
	cout << " Inside the function. value of *v: " << *a << " value of *x:  " << *b << endl;  
	temp = *a;   //	(2)
  	*a = *b;     //	(3)
  	*b = temp;
}  

void r_swap(int &a, int &b)
{
	cout << "Inside r_swap, references to v and x are obtained using the address_of operator (&)" << endl;
	cout << "Inside the second function before the swap, the memory location of v is: " << &a << endl;
	cout << "Inside the second function before the swap, the memory location of x is: " << &b << endl;
	int temp;
	cout << "Inside second function. value of &v: " << &a << " value of &x: " << &b << endl;
	temp = a;	//	(2)
	a = b;		//  	(3)
	b = temp;
}


