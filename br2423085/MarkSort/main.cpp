/*
  Brandon Richards
  November 19th, 2013
  Sorting Functions
*/

//Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//Global Constants None

//Function Prototypes
void filArry(int [],int);
void prntAry(int [],int,int);
void swap1(int &,int &);
void swap2(int &,int &);
void swap3(int [],int,int);
void copy(int [],int [],int);
void sortPos(int [],int,int);
void markSort(int [],int);

//Execution Begins Here
int main(int argc, char *argv[]){
    //Declare Variables and initialize the random number seed
    const int SIZE=100;
    int array[SIZE],acopy[SIZE];
    srand(static_cast<unsigned int>(time(0)));
    //Fill the array
    filArry(array,SIZE);
    //Copy the array
    copy(array,acopy,SIZE);
    //Print the Array
    prntAry(array,SIZE,10);
    //sort a position
    markSort(acopy,SIZE);
    //print the copy
    prntAry(acopy,SIZE,10);
    //Exit Stage Right
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
          if(a[pos]>a[i])swap1(a[pos],a[i]);
          //if(a[pos]>a[i])swap2(a[pos],a[i]);
          //if(a[pos]>a[i])swap3(a,pos,a[i]);
      }
}

void copy(int a[],int b[],int n){
         for(int i=0;i<n;i++){
          b[i]=a[i];
      }
}

void swap3(int a[],int pos1,int pos2){
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
          a[i]=rand()%900+100;
     }
}
