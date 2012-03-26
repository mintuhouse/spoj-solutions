#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    int a[9];
    a[0]=0;
    a[1]=3;
    a[2]=8;
    a[3]=15;
    a[4]=24;
    a[5]=35;
    a[6]=48;
    a[7]=63;
    a[8]=80;
    long long n;
    while(cin>>n){
        cout<< ((n-1)/9)*81+a[(n-1)%9]+1 <<endl;
    }
}
