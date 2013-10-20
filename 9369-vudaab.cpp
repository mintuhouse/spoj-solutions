#include<iostream>
using namespace std;

int main(){
    int t,a,b,c;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>b>>c;
        if(b-a==c-b) cout<<2*c-b<<endl;
        else cout<<c*c/b<<endl;
    }
}
