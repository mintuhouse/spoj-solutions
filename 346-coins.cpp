#include<iostream>
#include<stdio.h>
using namespace std;

long long A[1000000];

long long maxval(long long n){
    if(n<1000000){
        if(A[n]!=0) return A[n];
    }
    if(n<n/2+n/3+n/4){
        return(maxval(n/2)+maxval(n/3)+maxval(n/4));
    }else{
        if(n<1000000){
            A[n]=n;
        }
        return n;
    }
}

int main(){
    long long n;
    for(int i=0;i<1000000;i++) A[i]=maxval(i);
    while(cin>>n){
        cout<<maxval(n)<<endl;
    }
    return 0;

}
