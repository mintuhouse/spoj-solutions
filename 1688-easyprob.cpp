#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

void power(int n){
    //cout<<n<<endl;
    int N=n;
    if(n<=3){
        if(n==3) printf("2+2(0)");
        else if(n==2) printf("2");
        else if(n==1) printf("2(0)");
        else printf("ERROR");
        return;
    }
    int j=0;
    while(n>0){
        j++;
        n=n/2;
    }
    int a=pow(2,j-1);
    printf("2(");
    power(j-1);
    printf(")");
    if(N-a!=0) {printf("+");power(N-a);}
}

int main(){
    int n;int i=0;
    while(i++<7){
    cin>>n;
    printf("%d=",n);
    power(n); cout<<endl;
    }
    return 0;
}
