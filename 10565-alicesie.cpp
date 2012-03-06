#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
using namespace std;

int sieve[1000001];
bool mark[1000001];

int highestunmark(int n){
    for(int i=n-1;i>1;i--) if(!mark[i]) return i;
}

void calc(int n){
    if(n<=3) return;
    for(int i=2;i<=sqrt(n)+1;i++){
        if(n%i==0){
            mark[i]=true;
            i=n/i;
            mark[i]=true;
        }
    }
}

int s(int N){
    if(sieve[N]==0){
        int n=N;
        for(int i=2;i<=N;i++) mark[i]=false;
        do{
            calc(n);
            n=highestunmark(n);
        }while(n>2);
        int c=0;
        for(int i=2;i<=N;i++){
            if(!mark[i]) c++;
        }
        sieve[N]=c;
    }
    return sieve[N];
}


int main(){
    for(int i=2;i<=1000001;i++) sieve[i]=0;
    for(int i=2;i<=1000001;i++) s(i);
    int T,N;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N;
        cout<<s(N)<<endl;
    }
    return 0;
}
