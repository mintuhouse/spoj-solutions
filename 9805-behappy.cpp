#include<iostream>
using namespace std;

int min(int a1, int a2){
    if(a1<a2) return a1;
    else return a2;
}

int max(int a1, int a2){
    if(a1>a2) return a1;
    else return a2;
}

int main(){
    int M,N,n,k; 
    int A[21],B[21],a[21];
    int S[101][21];

    cin>>M>>N;   
    n=M; k=N;
    for(int i=1;i<=M;i++){
        cin>>A[i]>>B[i];  
        a[i]=B[i]-A[i]; 
        k-=A[i]; 
    }
    // Formulating the problem as x1 +x2 +x3 + ... + xn =k 
    // where 0 <= xi <= a[i] , where a[i]=B[i]-A[i]
    // where n=M, k = N- sigma(xi)    
    
    int p;
    for(p=0;p<=min(a[1],n);p++) S[1][p]=1;
    for(;p<=n;p++) S[1][p]=0;
    for(int i=2;i<=n;i++){
        for(int j=0;j<=k;j++){
            int s=0;
            for(int r=max(0,j-a[i]);r<=j;r++){
                s+=S[i-1][r];
            }
            S[i][j]=s;
        }
    }
    
/*
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++)
            cout<<S[i][j]<<" ";
        cout<<endl;
    }
*/

    cout<<S[n][k]<<endl;
    return 0;
}
