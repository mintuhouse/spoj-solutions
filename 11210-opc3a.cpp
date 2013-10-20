#include<iostream>
using namespace std;

int main(){
    long long G[1000001];
    G[0]=1;G[1]=2;
    for(int i=2;i<1000001;i++){
        G[i]=(G[i-1]*G[i-2])%1000000007;
    }
    int N,a;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a;
        cout<<G[a]<<endl;
    }
    return 0;
}
