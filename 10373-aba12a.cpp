#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    const int nmax=1000001;
    bool p[nmax];
    int num_primes=0;
    int primes[nmax/10];
    long long A, B;
    int d[100000];
    int C;
    for(int i=0;i<=nmax;i++) p[i]=1;
    for(int i=2;i<=nmax;i++){
        if(p[i]==0) continue;
        if(p[i]){
            primes[num_primes]=i;
            num_primes++;
            int j=i;
            while (j+i<nmax) {
                p[j+i]=0;
                j+=i;
            }
        }
    }
    cin>>C;
    for(int i=0;i<C;i++){
        cin>>A>>B;
        for(int j=0;j<=B-A;j++) d[j]=1;
        for(int k=0;k<num_primes && primes[k]<sqrt(B);k++){
            long long J;
            if(A<=primes[k]) J=2*primes[k];
            else{
                if(A%primes[k]==0) J=A;
                else J = (A/primes[k]+1)*primes[k];
            }
            for(int j=J-A;j<=B-A;j+=primes[k]){
                d[j]=0;
            }
        }
        for(int j=B-A;j>=0;j++){
            if(d[j]==1){
                cout<<j+A<<endl;
                break;
            }
        }
    }
    return 0;
}
