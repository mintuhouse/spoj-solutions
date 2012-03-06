#include<iostream>
using namespace std;

long long ** ANK;

long long linPerm(int N, int K){
    if(N==0) return 0;
    if(K==0) return 1;
    if(N==1&& K==1) return 1;
    if(K>(N+1)/2){ ANK[N][K]=0; return 0;}
    if(K==1){ ANK[N][K]=N; return N;}
    long long n;
    if(ANK[N][K]!=-1) return ANK[N][K];
    n=(linPerm(N-2,K-1)+linPerm(N-1,K))%1000000003;
    ANK[N][K]=n;
    return n;
}

int main(){
    int N,K;
    long long n;
    cin>>N>>K;
    ANK=new long long *[N+1];
    for(int i=0;i<N+1;i++){
        ANK[i]=new long long[K+1];
        for(int j=0;j<K+1;j++){
            ANK[i][j]=-1;
        }
    }
    n=(linPerm(N-3,K-1)+linPerm(N-1,K))%1000000003;
    cout<<n<<endl;
    return 0;
}
