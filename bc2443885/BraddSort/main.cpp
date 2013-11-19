/* Bradd Carey
 * 19 Nov 2013
 * Sorting
 */

//Libraries
#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;
//No Global Constants

//F(x)Prototypes
void swap1(int&, int&);
void swap2(int&, int&);
void swap3(int[], int, int);
void fillArray(int[], int);
void printArray(int[], int, int);
void copyArray(int[], int[]);
void sortPos(int[],int, int);
void masterSort(int[], int);

int main(int argc, char** argv) {
    srand(static_cast<int>(time(0)));
    const int SIZE = 100;
    int array[SIZE];
    
    fillArray(array, SIZE);
    printArray(array, SIZE, 10);
    
    cout<<endl;
    masterSort(array, SIZE);
    printArray(array, SIZE, 10);
    
    return 0;
}
void fillArray(int a[], int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%900+100;
    }
}
void printArray(int a[], int n, int length){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%length==length-1){
            cout<<endl;
        }
    }
}
void swap1(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}
void swap2(int &a, int &b){
    a=a^b;
    b=a^b;
    a=a^b;  
}
void swap3(int a[], int p1, int p2){
    int temp=a[p1];
    a[p1]=a[p2];
    a[p2]=temp;      
}
void copyArray(int a[], int b[], int n){
    for(int i=0;i<n;i++){
        b[i]=a[i];
    }
}
void sortPos(int a[], int n, int pos){
    if(pos>n-1)return;
    for(int i=pos+1;i<n;i++){
        if(a[pos]>a[i]){
            swap1(a[pos],a[i]);
        }
    }
}
void masterSort(int a[], int n){
    for(int i=0;i<n;i++){
        sortPos(a,n,i);
    }
}