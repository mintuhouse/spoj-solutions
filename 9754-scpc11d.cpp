#include<iostream>
using namespace std;

int main(){
    long long a,b,c;
    cin>>a>>b>>c;
    while(a!=0&&b!=0&&c!=0){
        int f=0;
        if(c>=a&&c>=b){
            if(c*c==a*a+b*b) f=1;
        }else if(b>=a&&b>=c){
            if(b*b==a*a+c*c) f=1;
        }else{
            if(a*a==b*b+c*c) f=1;
        }
        if(f)cout<<"right"<<endl;
        else cout<<"wrong"<<endl;
        cin>>a>>b>>c;
    }
    return 0;
}
