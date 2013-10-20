#include<iostream>
#include<algorithm>
using namespace std;

int gcd(int a,int b){
    //cout<<a<<" "<<b<<endl;
    if(a>b){
        return gcd(b,a);
    }else{
        int c=b%a;
        if(c==0) return a;
        else return(gcd(b%a,a));
    }
}


int main(){
    int N , n1, n2,X[100000],g,s=0;
    cin>>N;
    cin>>n1;
    for(int i=0;i<N-1;i++){
        cin>>n2;
        X[i]=n2-n1;
        n1=n2;
    }
    g=gcd(X[0],X[1]);
    for(int i=2;i<N-1;i++){
        g=gcd(g,X[i]);
    }
    for(int i=0;i<N-1;i++){
        s+=((X[i]/g)-1);
    }
    cout<<s<<endl;
    return 0;
}
