#include<iostream>
#include<stdio.h>
using namespace std;

/* // Lagrange Polynomial Interpolation
for(float i=S;i<S+C;i++){
    s=0;
    for(int j=0;j<S;j++){
        double p=1;
        for(float k=0;k<S;k++) if(j!=k) p*=(i-k)/(j-k);
        //for(int k=0;k<S;k++) if(j!=k) p/=(j-k);
        s+=(A[j]*p);
    }
    cout<<s<<" ";
}
*/

int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int S,C;
        cin>>S>>C;
        int A[S],B[S];
        double s;
        for(int i=0;i<S;i++) scanf("%d",&A[i]);
        bool flag=1;
        int size=S,j=0;
        for(int i=0;i<S;i++) B[i]=A[i];
        while(flag){
            flag=0;
            for(int i=0;i<size;i++) if(B[0]!=B[i]) flag=1;
            if(flag==0) break;
            for(int i=0;i<size-1;i++) B[0]=B[1]-B[0];
            size--;j++;
        }
        cout<<j<<endl;
        cout<<endl;
    }
    return 0;
}
