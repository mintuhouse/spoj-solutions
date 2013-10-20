#include<iostream>
using namespace std;

int main(){
    int T,N,A,D;
    cin>>T;
    for(int t=0;t<T;t++){
        cin>>N>>A>>D;
        cout<<(2*A+(N-1)*D)*N/2<<endl;
    }
    return 0;
}
