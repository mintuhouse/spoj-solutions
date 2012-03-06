#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

vector<int> primes;
bool div[1000001];
vector<int> property;
    
bool isprime(int n){
    int r=sqrt(n);
    for(int i=2;i<=r;i++){
        if(n%i==0) return false;
    }
    return true;
}


bool issatisy(int n){
    if(div[n]!=0) return div[n];
    int N=n;
    vector<int>::iterator it;
    for (it=primes.begin(); it<primes.end(); it++){
        int i=*it,j=0;
        while(n%i==0){
            n=n/i;
            j++;
        }
        if(j==1){
            div[N]=issatisy(n);
            return div[N];
        }else if (j>1){
            div[N]=0;
            return 0;
        }
    }
    div[N]=0;
    return 0;
}

int main(){
    int C,K,Ot;
    long long high,low;
    float rt;
    int s1,s2;
    bool p[1000001];
    for(int i=0;i<=1000000;i++) p[i]=1;
    for(int i=2;i<=1000000;i++){
        if(p[i]==0) continue;
        if(isprime(i)){
            primes.push_back(i);
            for(int j=2*i;j<=1000000;j+=i){
                p[j]=0;
            }
        }
    }
    for(int i=1;i<=100000;i++) { div[i]=0;}
    for(int i=100000;i>=1;i--) { div[i]=numdivisors(i);}
    return 0;
    cin>>C;
    for(int i=0;i<C;i++){
        Ot=0;
        cin>>K>>low>>high;
        rt=sqrt(low); s1=rt;
        if((float)s1!=rt) s1++;
        s2=sqrt(high);
        for(int j=s1;j<=s2;j++){
            if(div[j]==K)Ot++;
        }
        cout<<Ot<<endl;
    }
    return 0;
}


