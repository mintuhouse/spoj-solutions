#include<iostream>
#include<math.h>
#include<vector>
#include <algorithm>
#include<map>
using namespace std;

vector<int> primes;
int divs[100001];
int ans[100001];
map< int, vector<int> > maplist;

/* bool isprime(int n){
    int r=sqrt(n);
    for(int i=2;i<=r;i++){
        if(n%i==0) return false;
    }
    return true;
}*/

int numdivisors(int n,int ih){
    if(divs[n]!=0) return divs[n];
    int N=n;
    int num=1;
    int it;
    for (it=ih; it<primes.size() && primes[it]<=n; it++){
        int i=primes[it],j=0;
        while(n%i==0){
            n=n/i;
            j++;
        }
        num=num*(2*j+1);
        if(N!=n){
            num=numdivisors(n,it+1)*num;
            divs[N]=num;
            return num;
        }
    }
    divs[N]=num;
    return num;
}

int findpos(vector<int> v, int s, int min, int max, bool minmax){
    int mid=(min+max)/2;
    if((minmax && v[mid-1]<s && s<=v[mid]) || (!minmax && v[mid+1]>s && s>=v[mid])){
        return mid;
    } else if(v[mid-1]<s && s<=v[mid]){
        return mid-1;
    } else if(v[mid+1]>s && s>=v[mid]){
        return mid+1;
    } else if(v[mid-1]>=s){
        return findpos(v,s,min,mid-1,minmax); 
    } else if(v[mid+1]<=s){
        return findpos(v,s,mid+1,max,minmax);
    }else{
        cout<<"ERROR"<<endl;
        exit(1);
    }
}

int main(){
    int C,K,Ot;
    long long high,low;
    float rt;
    int s1,s2;
    bool p[100001];
    for(int i=0;i<=100000;i++) p[i]=1;
    for(int i=2;i<=100000;i++){
        if(p[i]==0) continue;
        if(p[i]){
            primes.push_back(i);
            for(int j=2*i;j<=100000;j+=i){
                p[j]=0;
            }
        }
    }
    for(int i=1;i<=100000;i++) { divs[i]=0;}
    for(int i=1;i<=100000;i++) { 
        divs[i]=numdivisors(i,0);
        maplist[divs[i]].push_back(i);
    }
    /*map<int, vector<int> >::iterator itr;
    for(itr=maplist.begin();itr!=maplist.end();++itr){
        sort((*itr).second.begin(),(*itr).second.end());
    }*/
    cin>>C;
    for(int i=0;i<C;i++){
        Ot=0;
        cin>>K>>low>>high;
        rt=sqrt(low); s1=rt;
        if(s1*s1!=rt*rt) s1++;
        s2=sqrt(high);
        /*for(int j=s1;j<=s2;j++){
            if(divs[j]==K)Ot++;
        }*/
        if(s2<s1){Ot=0;}
        else{
            s1=findpos(maplist[K],s1,0,maplist[K].size(),1);
            s2=findpos(maplist[K],s2,0,maplist[K].size(),0);
            if(s2>=s1) Ot=s2-s1+1; else Ot=0;
        }
        cout<<Ot<<endl;
    }
    return 0;
}


