/*
  Dr. Mark E. Lehr
  November 11th, 2013
*/

//Libraries
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

//No Global Constants

//Function Prototypes
void fillAry(vector<int>&);
void prntAry(vector<int>&,int);
int  find(vector<int>&,int,int,int);
void delVal(vector<int>&,int);
int  replce(vector<int>&,int,int);

int main(int argc, char *argv[]){
    //Declare and initialize variables
    srand(static_cast<unsigned int>(time(0)));
    vector<int> myVector(100);
    
    
    //Fill the Array
    fillAry(myVector);
    //Print the Array
    prntAry(myVector,10);
    
    //Find and delete 50s and 60s
    delVal(myVector,50);
    delVal(myVector,60);
    prntAry(myVector,10);
    
    //Replace 25s with 30s
    int count = replce(myVector,25,30);
    prntAry(myVector,10);
    
    //Output Count
    cout<<endl<<"Value 25 was replaced with 30, "<<count<<" times.\n";
    
    //Exit Stage Right
    return 0;
}

int replce(vector<int> &a,int vf,int vr){
     //Count how many replaced
     int cnt=0;
     for(int i=0;i<a.size();i++){
          if(a[i]==vf){
               a[i]=vr;
               cnt++;
          }
     }
     return cnt;
}
void delVal(vector<int> &a,int value){
    //Find and delete
    int posFnd=0;
    do{ 
        posFnd=find(a,posFnd,a.size(),value);
        if(posFnd>0)a.erase(a.begin()+posFnd);
    }while(posFnd>0);
}
int  find(vector<int> &a,int strt,int end,int value){
     //Try to find the value
     for(int i=strt;i<=end;i++){
             if(a[i]==value) return i;
     }
     //Return if not found
     return -1;
}
void prntAry(vector<int> &a,int perLine){
     cout<<endl;
     for(int i=0;i<a.size();i++){
          cout<<a[i]<<" ";
          if(i%perLine==(perLine-1))cout<<endl;
     }
     cout<<endl;
}
void fillAry(vector<int> &a){
     //Loop and fill the array
     for(int i=0;i<a.size();i++){
             a[i]=rand()%90+10;
     }
}     







