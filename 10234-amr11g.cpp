#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;

int main(){
    int T;
    char S[51];
    cin>>T;
    for(int t=0;t<T;t++){
        scanf("%s",S);
        int flag=0,j=0;
        while(S[j]!='\0'){
            if(S[j]=='D'){ flag=1; break;}
            j++;
        }
        if(flag) printf("You shall not pass!\n");
        else printf("Possible\n");
    }
    return 0;
}
