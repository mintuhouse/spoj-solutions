#include<iostream>
using namespace std;

int main(){
    int n,N,K,T,F;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>N>>K>>T>>F;
        cout<<(N+(F-N)*K/(K-1))<<endl;
    }
    return 0;
}
