/*
  Joseph Reimbold
  Dec 3, 2013
*/

//Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;

//No Globals

//Function Prototypes
void fillAry(vector<int> &);
void prntAry(vector<int> &,int);
int find(vector<int> &,int,int,int);
void shift(vector<int> &,int,int,int);
int szOf(vector<int> &,int,int);
int delVal(vector<int> &,int,int,int);
void replace(vector<int> &,int,int,int);
void reSize(vector<int> &,int);

//Execution begins here
int main(int argc, char *argv[])
{
    //Declare and Initialize Variables
    srand(static_cast<unsigned int>(time(0)));
    const int SIZE=200;
    vector<int> array(SIZE);
    
    //Fill the array
    fillAry(array);
    
    //Print the array
    prntAry(array,10);
    
    //Find and replace set value
    int fndVal=25, repVal=30;
    replace(array,SIZE,fndVal,repVal);
    
    //Find and delete
    int sizeOf=delVal(array,SIZE,50,-1);
    cout<<"Size of the array = "<<sizeOf<<endl;
    sizeOf=delVal(array,sizeOf,60,-1);
    cout<<"Size of the array = "<<sizeOf<<endl;
    
    //Print the array
    prntAry(array,10);
    
    //Resize array
    reSize(array,sizeOf);
    
    //Print resized array
    prntAry(array,10);
    
    //Exit stage right
    system("PAUSE");
    return EXIT_SUCCESS;
}

//Resize the array to not include -1s
void reSize(vector<int> &a,int size){
     a.resize(size);
}

//Find and replace a specified value
void replace(vector<int> &a,int n,int val,int rep){
     int count=0;
    for(int i=0;i<n;i++)
             if(a[i]==val){
                 a[i]=rep;
                 count++;
             }
    cout<<"Found "<<val<<" and replaced with "
        <<rep<<" "<<count<<" times."<<endl;
}

int delVal(vector<int> &a,int n,int value, int vInsrt){
    //Find and delete
    int posFnd=0;
    do{
       posFnd=find(a,posFnd,n-1,value);
       if(posFnd>0)shift(a,posFnd,n,vInsrt);
    }while(posFnd>0);
    //Size of the array
    return szOf(a,n,vInsrt);
}

int szOf(vector<int> &a,int n,int value){
    int s=a.size();
    for(int i=0;i<n;i++){
            if(a[i]==value)return i;
    }
    return n;
}

void shift(vector<int> &a,int pos,int end,int value){
     //Delete the position
     for(int i=pos;i<end-1;i++){
             a[i]=a[i+1];
     }
     //Replace last position with empty value
     a[end-1]=value;
}

int find(vector<int> &a,int strt,int end,int value){  
    //Try to find the value
    for(int i=strt;i<=end;i++){
             if(a[i]==value) return i;
    }
    //Return if not found
    return -1;
}

void prntAry(vector<int> &a,int perLine){
     int s=a.size();
     cout<<endl;
     for(int i=0;i<s;i++){
             cout<<a[i]<<" ";
             if(i%perLine==(perLine-1))cout<<endl;
     }
     cout<<endl;
}

//Randomly fill an aray with 2 digit numbers
void fillAry(vector<int> &a){
     int s=a.size();
     //Loop and fill the array
     for(int i=0;i<s;i++){
             a[i]=rand()%90+10;
     }
}
