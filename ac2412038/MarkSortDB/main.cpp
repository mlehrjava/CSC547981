/*
  Dr. Mark E. Lehr
  November 25th, 2013
  Sorting Functions
*/

//Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//Global Constants

//Function Prototypes
void filArry(int [],int [],int);
void prntAry(int [],int,int);
void prntAry(int [],int [],int,int);
void swap(int &,int &);
void sortPos(int [],int [],int,int);
void markSort(int [],int [],int);

int main(int argc, char *argv[]){
    //Declare variables and initialize the
    //random number seed
    const int SIZE=100;
    int array[SIZE],indx[SIZE];
    srand(static_cast<unsigned int>(time(0)));
    //Fill the array
    filArry(array,indx,SIZE);
    //Print the array
    prntAry(array,SIZE,10);
    prntAry(indx,SIZE,10);
    prntAry(array,indx,SIZE,10);
    //Sort the array
    markSort(array,indx,SIZE);
    //Print the sorted array
    prntAry(array,SIZE,10);
    prntAry(indx,SIZE,10);
    prntAry(array,indx,SIZE,10);
    //Exit stage right
    system("PAUSE");
    return EXIT_SUCCESS;
}

void markSort(int a[],int indx[],int n){
     for(int i=0;i<n-1;i++){
          sortPos(a,indx,n,i);
     }
}

void sortPos(int a[],int indx[],int n,int pos){
     if(pos>n-1)return;
     for(int i=pos+1;i<n;i++){
          if(a[indx[pos]]>a[indx[i]])swap(indx[pos],indx[i]);
     }
}

void swap(int &a,int &b){
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

void prntAry(int a[],int indx[],int n,int perLine){
     cout<<endl;
     for(int i=0;i<n;i++){
          cout<<a[indx[i]]<<" ";
          if(i%perLine==(perLine-1))cout<<endl;
     }
     cout<<endl;
}

void filArry(int a[],int indx[],int n){
     for(int i=0;i<n;i++){
          a[i]=rand()%900+100;
          indx[i]=i;
     }
}
