#include<iostream>
using namespace std;

int main(){
    long long T,N;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>N;
        long long i=N/2,s,S;
        if(N%2==0) s=i*(i+1)*(4*i-1)/6;
        else s=i*(i+1)*(4*i+5)/6;
        S=s+N*(N+1)*(N+2)/6;
        cout<<S<<endl;
    }
    return 0;
}
