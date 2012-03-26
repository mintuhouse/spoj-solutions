#include<iostream>
using namespace std;

int main(){
    int N,Q,x,y,max1,max2,temp;
    char X;
    cin>>N;
    int A[N+1];
    for(int i=1;i<=N;i++){
        cin>>A[i];
    }
    cin>>Q;
    for(int i=0;i<Q;i++){
        cin>>X>>x>>y;
        if(X=='U'){
            A[x]=y;
        }else{
            max1=0;max2=0;
            for(int j=x;j<=y;j++){
                if(A[j]>max2){
                    max2=A[j];
                    if(max2>max1){
                        temp=max1;
                        max1=max2;
                        max2=temp;
                    }
                }
            }
            cout<<max1+max2<<endl;
        }
    }
}
