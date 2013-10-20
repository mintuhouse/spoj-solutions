#include<iostream>
#include<cmath>
using namespace std;

long long sum(long long N){
    if(N/10==0) return N*(N+1)/2;
    int i=0;
    long long n=N;
    while(n/10!=0){
        i++;
        n/=10;
    }
    int p=pow(10,i);
    return ((n*45*i*p/10)+ n*(n-1)*p/2+ n*(N%p+1) + sum(N%p));
}

int main(){
    long long a,b;
    cin>>a>>b;
    while(a!=-1 || b!=-1){
        cout<<sum(b)-sum(a-1)<<endl;
        cin>>a>>b;
    }
    return 0;
}
