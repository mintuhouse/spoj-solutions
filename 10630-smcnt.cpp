#include<iostream>
#include<stdio.h>
using namespace std;

struct numsmall{
    int n;   // number
    int s; // No. of smaller elements to right of it
};

typedef struct numsmall ns;

void findsmallmerge(ns A[],int p, int m, int q);

void findsmallsort(ns A[],int p, int q){
    //for(int i=p;i<=q;i++) cout<<A[i].n<<" "; cout<<endl;
    if(q-p<1) return;
    else{
        int m=(p+q)/2;
        findsmallsort(A,p,m);
        findsmallsort(A,m+1,q);
        findsmallmerge(A,p,m,q);
    }
}

void findsmallmerge(ns A[],int p, int m, int q){
    ns B[q-p+1];
    int i=p, j=m+1, k=0;
    while(i<=m && j<=q){
        if(A[i].n<A[j].n){
            B[k++].n=A[i++].n;
            B[k++].s=A[i++].s;
        }else{
            B[k++].n=A[j++].n;
            B[k++].s=A[j++].s;
        }
    }
    while(i<=m){
        B[k++].n=A[i++].n;
        B[k++].s=A[i++].s;
    }
    while(j<=q){
        B[k++].n=A[j++].n
        B[k++].s=A[j++].s;
    //cout<<"c :"<<q-p+1<<" "<<k<<endl;
    for(k--;k>=0;k--){
        A[p+k].n=B[k].n;
        A[p+k].s=B[k].s;
    }
}

int main(){
    ns A[1000001];
    int N=0;
    while(scanf("%d",&A[N++].n)!=EOF);
    for(int i=0;i<N-1;i++) A[i].s=0;
    //for(int i=0; i<N-1;i++) cout<<A[i].n<<" "; cout<<endl;
    findsmallsort(A,0,N-2);
    //for(int i=0; i<N-1;i++) cout<<A[i].n<<" "; cout<<endl;
    return 0;
}
