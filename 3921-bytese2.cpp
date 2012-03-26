#include<iostream>
#include<set>
using namespace std;

int t[10000000];

int main(){
    int T,N;
    long long E,L;
    set<long long> el;
    int es,ls;
    cin>>T;
    for(int i=0;i<10000000;i++){
        t[i]=0;
    }
    for(int i=0;i<T;i++){
        cin>>N;
        for(int j=0;j<N;j++){
            cin>>E>>L;
            el.insert(E);
            el.insert(L);
            t[E]=1;
            t[L]=-1;
        }
        int max=0,sum=0;
        set<long long>::iterator it;
        for(it=el.begin();it!=el.end();it++){
            sum+=t[*it];
            if(sum>max) max=sum;
            t[*it]=0;
        }
        cout<<max<<endl;
        el.clear();
    }
    return 0;
}
