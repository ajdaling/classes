#include <iostream>
using namespace std;

/*
Alec Daling
2-15-17
CLosed Lab 3 Exercise 1
*/

const int NUM_ELEMENTS = 10;
int main()
{

    int array1[NUM_ELEMENTS]; //array1 is pointer to &array1[0]
    int *pntr1 = array1; //*pntr = &array1[0] = array1
    //Fill in array1 using pointers [0,1,2,...,,9]
    for(int i = 0; i < NUM_ELEMENTS; i++){
        *(pntr1+i) = i;
    }

    int array2[NUM_ELEMENTS/2];
    int *pntr2 = array2;
    for(int i = 0; i < NUM_ELEMENTS/2; i++){
        *(pntr2+i) = *(pntr1+2*i+1);
    }


    //print arrays for testing
    for(int i = 0; i < NUM_ELEMENTS; i++){
        cout << array1[i];
    }
    cout << "\n";
    for(int i = 0; i < NUM_ELEMENTS/2; i++){
        cout << array2[i];
    }
		cout << "\n";
}
