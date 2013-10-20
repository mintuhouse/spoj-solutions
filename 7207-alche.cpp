#include<iostream>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    while(a!=-1 && b!=-1){
        if(a%1000==0&&b%37==0&&a/1000==b/37) cout<<"Y"<<endl;
        else cout<<"N"<<endl;
        cin>>a>>b;
    }
    return 0;
}
