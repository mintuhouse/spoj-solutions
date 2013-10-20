#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

vector<int> primes;

int main(){
    bool p[31623];
    for(int i=0;i<=31623;i++) p[i]=1;
    for(int i=2;i<=31623;i++){
        if(p[i]==0) continue;
        if(p[i]){
            primes.push_back(i);
            for(int j=2*i;j<=31623;j+=i){
                p[j]=0;
            }
        }
    }
    int t;
    long long m,n;
    cin>>t;
    int A[100001];
    for(int i=0; i<t;i++){
        cin>>m>>n;
        for(int j=0; j<=n-m;j++) A[j]=1;
        for(int k=0; primes[k]<=sqrt(n) && k<primes.size() ; k++){
            long long J;
            if(m<=primes[k]) J=2*primes[k];
            else{
                if(m%primes[k]==0) J=m;
                else J = (m/primes[k]+1)*primes[k];
            } 
            for(int j=J-m;j<=n-m;j+=primes[k]){
                A[j]=0;
            }
        }
        for(int j=0; j<=n-m; j++){
            if(A[j]==1 && m+j!=1) {
                cout<<m+j<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}
