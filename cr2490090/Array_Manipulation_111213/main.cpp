/*
Caleb Rosenquist
November 12th, 2013
Purpose: To locate a specific element in an array and delete it shit
TESTESTESTESTESTEST
*/

//Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//Global Constants

//Function Prototypes
void fillAry(int [], int);
void printAry(int [], int, int);
int find(int [], int, int, int);
void shift(int [], int, int, int);
int sizeOf(int [], int, int);
int delVal(int [], int, int, int);
int replace(int [], int, int, int);


//Execution Begins Here
int main(int argc, char *argv[]){
    //Declare and initialize variables
    srand(static_cast<unsigned int>(time(0)));
    const int SIZE = 100;
    int array[SIZE];
    
    //Fill the array
    fillAry(array, SIZE);
    
    //Print the array
    printAry(array, SIZE, 10);
    
    //Exercise the find function and the shift function
    int vToFnd = 50;
    int posFnd=find(array, 0, SIZE-1, vToFnd);
    if(posFnd>0)shift(array, posFnd, SIZE, -1);
    int size_of = delVal(array, SIZE, vToFnd, -1);
    cout << "The size of the array = " << sizeOf(array, SIZE, -1) << endl;
    size_of = delVal(array, SIZE, 60, -1);
        cout << "The size of the array = " << size_of << endl;
    
    replace(array, SIZE, 30, 60);
    
    //Print the Array
    cout << endl;
    printAry(array, SIZE, 10);
    
    //Exit Stage Right
    system("PAUSE");
    return EXIT_SUCCESS;
}

//Randomly fill an array with two digit numbers
void fillAry(int a[], int n){
    //Loop and fill the array
    for(int i=0; i<n;i++){
            a[i]=rand()%90+10;
    }
}

void printAry(int a[], int n, int perLine){
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
        if(i%perLine==(perLine-1))cout << endl;
    }
}

int find(int a[], int start, int end, int value){
    //Try to find the value
    for(int i=start; i<=end; i++){
        if(a[i]==value)return i;
    }
    
    //Return if not found
    return -1;
}

void shift(int a[], int pos, int end, int value){
    //Delete the position 
    for(int i=pos; i<end-1; i++){
        a[i]=a[i+1];
    }
    //Replace last element with the empty value
    a[end-1]=value;
}

int sizeOf(int a[], int length, int value){
    for(int i=0; i<length; i++){
            if(a[i]==value)return i;
    }
    return length;
}

int delVal(int a[], int n, int value, int vInsrt){
    //Find and Delete
    int posFnd = 0;
    do{
        posFnd=find(a, posFnd, n-1, value);
        if(posFnd>0)shift(a, posFnd, n, vInsrt);
    }while(posFnd>0);
    
    
    //The size of the array = " 
    return sizeOf(a, n, vInsrt);
}

int replace(int a[], int n, int value, int rep){
    //Find and Delete
    int posFnd = 0;
    do{
        posFnd=find(a, posFnd, n-1, value);
        for(int i=posFnd; i<n-1; i++){
            if(a[i]==value){
            a[i]=rep;
            cout << "A Number has been replaced." << endl;
            }
        }
    }while(posFnd>0);
    
    
    //The size of the array = " 
    return rep;
}
