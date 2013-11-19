/*
  Jeffrey Hu
  November 19, 2013
  Purpose: Sorting Functions
*/
//Libraries
#include <cstdlib>
#include <iostream>
using namespace std;

// Global Constants

//Function prototypes
void filArry(int [],int);//Fill array
void prntAry(int [],int,int);//print array
void swap1(int &,int &);//swap function, pass int by reference because void
void swap2(int &,int &);
void swap3(int [],int,int);//pass in array and 2 positions
void copy(int [],int [],int);//copy array to sort that not original
void sortPos(int [],int,int);//pass in array, size and position
void markSort(int [],int);

//Begin Execution
int main(int argc, char *argv[]){
    //Declare Variables and Initialize Rand Num Seed
    const int SIZE=100;//declare array size
    int array[SIZE],acopy[SIZE];//declare array
    srand(static_cast<unsigned int>(time(0)));
    //Fill the array
    filArry(array,SIZE);
    //Copy the array
    copy(array,acopy,SIZE);
    //Print the array
    prntAry(array,SIZE,10);
    //sort array
    markSort(acopy,SIZE);
    //print the sorted array
    prntAry(acopy,SIZE,10);
    system("PAUSE");
    return EXIT_SUCCESS;
}

void markSort(int a[],int n){
     for(int i=0;i<n-1;i++){
             sortPos(a,n,i);
     }
             
}

void sortPos(int a[],int n,int pos){
      if(pos>n-1)return;
      for(int i=pos+1;i<n;i++){
             //if(a[pos]>a[i])swap1(a[pos],a[i]);
             //if(a[pos]>a[i])swap2(a[pos],a[i]);
             if(a[pos]>a[i])swap3(a,pos,i);
     }
}

void copy(int a[],int b[],int n){
     for(int i=0;i<n;i++){
             b[i]=a[i];
     }
}

void swap3(int a[],int n,int pos1,int pos2){
     int temp=a[pos1];
     a[pos1]=a[pos2];
     a[pos2]=temp;
}

void swap2(int &a,int &b){
     a=a^b;
     b=a^b;
     a=a^b;
}

void swap1(int &a,int &b){
     int temp=a;
     a=b;
     b=temp;
}

void prntAry(int a[],int n,int perLine){
     cout<<endl;
     for(int i=0;i<n;i++){
             cout<<a[i]<<" ";
             if(i%perLine==(perLine-1))cout<<endl;
     }
     cout<<endl;
}

void filArry(int a[],int n){
     for(int i=0;i<n;i++){
             a[i]=rand()%900+100;//3 digit numbers, 0-899,0-99
     }
}
     
