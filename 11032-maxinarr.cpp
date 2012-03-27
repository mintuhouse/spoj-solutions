#include<iostream>
using namespace std;

int main(){
    long long N,max;
    long long * A;
    cin>>N;
    while(N!=0){
        A=new long long[N];
        max=-1000000000;
        for(int i=0;i<N;i++){
            cin>>A[i];
            if(A[i]>max)max=A[i];
        }
        cout<<max<<endl;
        delete[] A;
        cin>>N;
    }
    return 0;
}
