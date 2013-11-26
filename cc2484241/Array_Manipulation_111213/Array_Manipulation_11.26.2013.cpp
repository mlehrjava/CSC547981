/*
  Christian Conable 
  11/12/2013
  Array Manipulation
*/

//Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//No Global Constants

//Function Prototypes
void fillAry(int *, int); 
void prntAry(int *, int, int); 
int find(int *, int, int, int); 
void shift(int *, int, int, int); 
int szOf(int *, int, int); 
int delVal(int *, int, int, int); 

typedef int* intptr; 

int main(int argc, char *argv[]){
    //Declare and Initialize Variables
    srand(static_cast<unsigned int> (time(0))); 
    const int SIZE = 50; 
    int array[SIZE]; 
    
    //Fill the Array
    fillAry(array, SIZE); 
    
    //Print the Array 
    prntAry(array, SIZE, 10); 
    
    //Find and Delete
    int sizeOf = delVal(array, SIZE, 50, -1);
    cout << "Size of the array = " 
         << sizeOf << endl; 
    
    //Print the Array 
    prntAry(array, SIZE, 10); 
    
    //Exit Stage Right
    system("PAUSE");
    return EXIT_SUCCESS;
}
//Randomly fill an array with
//2 digit numbers
void fillAry(int *a, int n){
     intptr p;  
     int i; 
     //loop and fill the array
     for (int i = 0; i < n; i++){
         p = a; 
         p[i] = rand()%90 + 10;
         
     }
}

void prntAry(int *a, int n, int perLine){
     cout << endl; 
     intptr p1; 
     int i; 
     for (int i = 0; i < n; i++){
        p1 = a; 
        cout << p1[i] << " "; 
        if(i%perLine == (perLine - 1)) cout << endl; //this only puts 10 per line (from 0 - 9)
     }
     cout << endl; 
}

int find(int *a,int strt, int end, int value){
    //Initialize position if not found
    int found = -1; 
    
    //Try to find the value
    for (int i = strt; i <= end; i++){
         if (a[i] == value) return i;
    }
    
    //Return if not found
    return -1; 
}

void shift(int *a, int pos, int end, int value){
     //Delete the position
     for (int i = pos; i < end; i++){
         a[i] = a[i + 1];          
     }
     
     //Replace last position with empty value
     a[end - 1] = value; 
}

int szOf(int *a, int n, int value){
    for (int i = 0; i < n; i++){
        if(a[i] == value) return i - 1; 
     }
    return n;    
}

int delVal(int *a, int n, int value, int vInsrt) {
    //Find and Delete 
    int posFnd = 0;
    do {
       int posFnd = find(a, 0, n - 1, value); 
       if (posFnd > 0) shift(a, posFnd, n, vInsrt);
    }while (posFnd > 0); 
    //Size of the array
    return szOf(a, n, vInsrt); 
       
}
