#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fact[101][200];
int size[101];

int main(){
    fact[0][0]=1;
    size[0]=1;
    for(int i=1;i<=100;i++){
        //fact[i]=fact[i-1]*i;
        int carry=0,temp,j;
        for(j=0;j<size[i-1];j++){
            temp=(fact[i-1][j])*i+carry;
            fact[i][j]=(temp%10);
            carry=temp/10;
        }
        while(carry!=0){
            fact[i][j]=carry%10;
            carry=carry/10;
            j++;
        }
        size[i]=j;
    }
    int t,n;
    scanf("%d",&t);
    for(int i=0; i<t;i++){
        scanf("%d", &n);;
        for(int j=size[n]-1;j>=0;j--){
            printf("%d",fact[n][j]);
        }
        printf("\n");
    }
    return 0;
}
