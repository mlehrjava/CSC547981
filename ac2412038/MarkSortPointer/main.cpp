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
void filArry(int [],int);
void prntAry(int [],int,int);
void swap(int *,int *);
void copy(int *,int *,int);
void sortPos(int *,int,int);
void markSort(int *,int);

int main(int argc, char **argv){
    //Declare variables and initialize the
    //random number seed
    const int SIZE=100;
    int array[SIZE],acopy[SIZE];
    srand(static_cast<unsigned int>(time(0)));
    //Fill the array
    filArry(array,SIZE);
    //Copy the array
    copy(array,acopy,SIZE);
    //Print the array
    prntAry(array,SIZE,10);
    //Sort the array
    markSort(acopy,SIZE);
    //Print the sorted array
    prntAry(acopy,SIZE,10);
    //Exit stage right
    system("PAUSE");
    return EXIT_SUCCESS;
}

void markSort(int *a,int n){
     for(int i=0;i<n-1;i++){
          sortPos(a,n,i);
     }
}

void sortPos(int *a,int n,int pos){
     if(pos>n-1)return;
     for(int i=pos+1;i<n;i++){
          //if(a[pos]>a[i])swap(&a[pos],&a[i]);
          //if(a[pos]>a[i])swap(&*(a+pos),&*(a+i));
          if(a[pos]>a[i])swap((a+pos),(a+i));
     }
}


void swap(int *a,int *b){
     int temp=*a;
     *a=*b;
     *b=temp;
}

void copy(int *a,int *c,int n){
     for(int i=0;i<n;i++){
             *(c+i)=a[i];
     }
}

void prntAry(int *a,int n,int perLine){
     cout<<endl;
     for(int i=0;i<n;i++){
          cout<<*(a+i)<<" ";
          if(i%perLine==(perLine-1))cout<<endl;
     }
     cout<<endl;
}

void filArry(int *a,int n){
     for(int i=0;i<n;i++){
          //a[i]=rand()%900+100;
          *(a+i)=rand()%900+100;
     }
}
