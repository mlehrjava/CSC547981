/* 
 * File:   main.cpp
 * Author: Abel Castillon Jr.
 * Date: November 19, 2013, 8:23 AM
 * 
*/

//Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//Global Variables and Constants

//Function Prototypes
void fillArray(int [],int);
void printArray(int [],int,int);
void swap1(int &, int&);
void swap2(int &, int&);
void swap3(int [],int,int);
void copy (int[],int [], int);
void sortPos(int[],int,int);
void markSort(int [],int);

//Execution Begins Here
int main(int argc, char** argv){
    
    //Declare variables and initialize the random number seed
    const int SIZE=100;
    
    //declare array
    int array[SIZE],acopy[SIZE];
    srand(static_cast<unsigned int>(time(0)));
    
    //Fill array
    fillArray(array,SIZE);
    
    //Cop the array
    copy(array,acopy,SIZE);
    
    //Print array
    printArray(array, SIZE,10);
    
    //Sort the array
    markSort(acopy,SIZE);
    
    //Print the sorted array
    printArray(acopy,SIZE,10);
    
    //Copy the array
    copy(array,acopy,SIZE);
    
    //Print the copy
    printArray(array,SIZE,10);
    
    //Exit Stage Right
    return 0;
}
void markSort(int a[],int n){
    for (int i=0;i<n-1;i++){
        sortPos(a,n,i);
    }
}

void swap1(int &a, int&b){
    int temp=a;
    a=b;
    b=temp;
}

void swap2(int &a, int &b){
    a=a^b;
    b=a^b;
    a=a^b;
}

void swap3(int a[],int pos1,int pos2){
    int temp=a[pos1];
    a[pos1]=a[pos2];
    a[pos2]=temp;
}
void copy (int a[],int b[], int n){
    for (int i=0; i<n; i++){
        b[i]=a[i];
    }
}

void sortPos(int a[],int n,int pos){
    if (pos>n-1)return;
    for (int i=pos+1; i<n; i++){
        //if(a[pos]>a[i])swap1(a[pos],a[i]);
        //if(a[pos]>a[i])swap2(a[pos],a[i]);
        if(a[pos]>a[i])swap3(a,pos,i);
    }
}

void printArray(int a[],int n,int perLine){
    cout<<endl;
    for (int i=0; i<n; i++){
        cout<<a[i]<<" ";
        if (i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void fillArray(int a[],int n){
    for (int i=0; i<n; i++){
        a[i]=rand()% 900+100;
    }
}

