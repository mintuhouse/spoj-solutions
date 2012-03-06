#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

const int nmax=1000001;

unsigned long long primes[nmax/10];
bool fl[nmax];
int test, m;
unsigned long long n;

int main()
{
    for (int i=2; i<nmax; i++)
    if (!fl[i]) {
        primes[m] = i;
        m++;
        int j=i;
        while (j+i<nmax) {
        fl[j+i]=1;
        j+=i;
    }
    }

scanf("%i",&test);
while (test--) {
scanf("%lld",&n);

if (n==0) {
printf("Yes\n");
continue;
}

bool mt=0;
for (int i=0; i<m; i++) {
int k=0;
while (n%primes[i]==0) {
if (primes[i]%4==3) k++;
n/=primes[i];
}
if (k%2!=0) {
printf("No\n");
mt=1;
break;
}
}
if (!mt && n%4!=3) printf("Yes\n");
else if (!mt) printf("No\n");
}
return 0;
}
/*
#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main(){
    vector<int> primes;
    //vector<int> p3;
    bool p[1000000];
    for(int i=0;i<=1000000;i++) p[i]=1;
    for(int i=2;i<=1000000;i++){
        if(p[i]==0) continue;
        if(p[i]){
            primes.push_back(i);
            //if(i%4==3) p3.push_back(i);
            for(int j=2*i;j<=1000000;j+=i){
                p[j]=0;
            }
        }
    }
    cout<<"done"<<endl;
    int c;
    long long n;
    cin>>c;

    for(int i=0;i<c;i++){
        cin>>n;
        long long N=n;
        int k=0,flag=0;
        while(N>1){
            if(N%primes[k]==0){
                if(primes[k]%4==3){
                    flag=1;
                    break;
                }
                n/=primes[k];
            }else{
                k++;
            }
        }
        if(flag==1) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;
}

*/
