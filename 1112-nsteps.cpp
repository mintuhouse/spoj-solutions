#include <iostream>
using namespace std;

int main(){
    int n,x,y;
    int t1,t2,t;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        if(x==y || x-y==2){
            t1=x%4;
            t2=y%4;
            switch(t1){
                case 0:
                    if(t2==0) t=0;
                    else t=6;
                break;
                case 1:
                    if(t2==1) t=1;
                    else t=7;
                break;
                case 2:
                    if(t2==2) t=4;
                    else t=2;
                break;
                case 3:
                    if(t2==3) t=5;
                    else t=3;
                break;
                default :
                cout<<"ERROR";                
            }
            cout<<(y/4)*8+t<<endl;
        }else{
            cout<<"No Number"<<endl;
        }
    }
    return 0;
}
