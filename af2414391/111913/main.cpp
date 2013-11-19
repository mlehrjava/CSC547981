/*
 *Alec Farfan
 *November 19th, 2013
 *Purpose:Mark Sort
 */

//Include Libraries 
#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//No Global Variables or Constants

//Function Prototypes
void marksort(int [],int);
void sort(int [],int,int);
void copy(int[],int[],int);
void swap3(int [],int,int);
void swap2(int &,int&);
void swap1(int &,int&);
void print(int [],int,int);
void fill(int [],int);
//Execution Begins here
int main(int argc, char *argv[]){
    //Declare Variables and Initialize Random Number Sequence
    const int SIZE = 100;
    int array[SIZE],acopy[SIZE];
    srand(static_cast<unsigned int>(time(0)));
    
    //Fill the Array
    fill(array,SIZE);
    print(array,SIZE,10);//Print the Array
    
    //Copy the Array
     copy(array,acopy,SIZE);
   // print(acopy,SIZE,10);//Print the Copy
   
   //Sort the Array
   marksort(acopy,SIZE);
  //sort(array,SIZE,0);
   print(acopy,SIZE,10);
    
    //End of Program
    system("PAUSE");
    return EXIT_SUCCESS;
}
void fill(int a[],int n){
     for (int i=0;i<n;i++){
         a[i]=rand()%900+100;}
     
}
void print(int a[],int n,int perLine){
     cout<<endl;
     for (int i=0;i<n;i++){
         cout<<a[i]<<" ";
         if (i%perLine==(perLine-1)){
         cout<<endl;}}
}
void swap1(int &a,int&b){
     int temp=a;
     a=b;
     b=temp;
}
void swap2(int &a,int&b){
     a=a^b;
     b=a^b;
     a=a^b;
}     
void swap3(int a[],int pos1,int pos2){
     int temp=a[pos1];
     a[pos1]=a[pos2];
     a[pos2]=temp;
}    
void copy(int a[],int b[],int n){
      for (int i=0;i<n;i++){
         b[i]=a[i];}
}
void sort(int a[],int n,int pos){
     if (pos>n-1){return;}
     for (int i=pos+1;i<n;i++){
         if (a[pos]>a[i]){
         swap2(a[pos],a[i]);}}
        //swap3(a,pos,a[i]);}}
}
     
void marksort(int a[],int n){
      for (int i=0;i<n-1;i++){
         sort(a,n,i);}
}
