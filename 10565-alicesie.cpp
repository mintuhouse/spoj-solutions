#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

int c[1000001];
bool p[1000001];
int main(){
    for(int i=0;i<1000001;i++){ c[i]=0; p[i]=1;}
    for(int i=2;i<1000001;i++){
        if(p[i]==0){
            c[i]=c[i-1];
        }else{
            for(int j=2*i;j<1000001;j+=i){
                p[j]=0;
            }
            c[i]=c[i-1]+1;
        }
    }
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        int N;
        scanf("%d",&N);
        cout<<c[N]+!p[N]<<endl;
    }
    return 0;
}
