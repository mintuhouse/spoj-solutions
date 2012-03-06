#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sstream>
using namespace std;

int rev(int n){
/*    char N[10];
    //itoa(n,N,10);
    string s;
    stringstream out;
    out<<n;
    s=out.str();
    strcpy(N,s.c_str());
    int k=atoi(N);*/
    int N[10];
    int t=n;
    int i=0;
    int flag=0;
    do{
        int p=t%10;
        t/=10;
        if(p==0 && flag==0) continue;
        else{
            N[i]=p;
            i++;
            flag=1;
        }
    }while(t>0);
    int k=0;
    for(int j=0;j<i;j++){
        k=k*10+N[j];
    }
    return k;
}

int main(){
    int i,N,a,b;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d",&a);
        scanf("%d",&b);
        //printf("%d %d\n",rev(a),rev(b));
        printf("%d\n",rev(rev(a)+rev(b)));
    }
    return 0;
}
