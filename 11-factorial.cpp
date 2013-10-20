#include<iostream>
#include<cmath>
using namespace std;

long long Z(long long n){
    long long N=n,i=1,zeros=0;
    while(n/5!=0){
        zeros+=n/5;
        n=n/5;
    }
    return zeros;
}

int main(){
    long long T,N;
    cin>>T;
    for(long long i=0; i<T;i++){
        cin>>N;
        cout<<Z(N)<<endl;
    }
    return 0;
}
