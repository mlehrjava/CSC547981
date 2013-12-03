/*
  Brandon Richards
  December 3rd, 2013
*/

//Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

//No Global Constants

//Function Prototypes
void fillAry (vector<int> &);
void prntAry(vector<int> &,int);
int  find(int [],int,int,int);
void shift(int [],int,int,int);
int  szOf(int [],int,int);
int  delVal(int [],int,int,int);
int  replce(int [],int,int,int);

int main(int argc, char *argv[]){
    //Declare and initialize variables
    srand(static_cast<unsigned int>(time(0)));
    const int SIZE=200;
    vector<int> array(SIZE);
    //Fill the Array
    fillAry(array);
    //Print the Array
    prntAry(array,10);
    //Find and delete and replace
    //int sizeOf=delVal(array,50,-1);
    //cout<<"Size of the array = "
    //    <<sizeOf<<endl;
    //sizeOf=delVal(array,60,-1); 
    //cout<<"Size of the array = "
     //   <<sizeOf<<endl;
    //cout<<"Found 25 "
     //   <<replce(array,25,30)
     //   <<" times and replace it with 30"<<endl;
    //Print the Array
    prntAry(array,10);
    //Exit stage Right
    system("PAUSE");
    return EXIT_SUCCESS;
}

int  replce(int a[],int n,int vf,int vr){
     //Count how many replaced
     int cnt=0;
     for(int i=0;i<n;i++){
          if(a[i]==vf){
               a[i]=vr;
               cnt++;
          }
     }
     return cnt;
}

int  delVal(int a[],int n,int value,int vInsrt){
    //Find and delete
    int posFnd=0;
    do{ 
        posFnd=find(a,posFnd,n-1,value);
        if(posFnd>0)shift(a,posFnd,n,vInsrt);
    }while(posFnd>0);
    
    //Size of the array
    return szOf(a,n,vInsrt);
}

int  szOf(int a[],int n,int value){
     for(int i=0;i<n;i++){
          if(a[i]==value)return i;
     }
     return n;
}

void shift(int a[],int pos,int end,int value){
     //Delete the position
     for(int i=pos;i<end-1;i++){
             a[i]=a[i+1];
     }
     //Replace last position with empty value 
     a[end-1]=value;
}

int  find(int a[],int strt,int end,int value){
     //Try to find the value
     for(int i=strt;i<=end;i++){
             if(a[i]==value) return i;
     }
     //Return if not found
     return -1;
}

void prntAry(vector<int> &a,int perline){
     cout<<endl;
     for(int i=0;i<perline;i++){
          cout<<a[i]<<" ";
          if(i%perline==(perline-1))cout<<endl;
     }
     cout<<endl;
}

//Randomly fill an array with 2
//digit numbers
void fillAry(int &a){
     //Loop and fill the array
     for(int i=0;i<n;i++){
             a[i]=rand()%90+10;
     }
}     







