#include<iostream>
#include<vector>
using namespace std;

int main(){
    int T,n;
    int num[3000],lucky[3000];
    for(int i=0;i<3000;i++) num[i]=0;
    for(int i=2;i<3000;i++){
        if(num[i]==0){
            for(int j=2*i;j<3000;j+=i){
                num[j]=1;
            }
        }
    }
    vector<long long> p;
    for(int i=2;i<3000;i++){
        if(num[i]==0)p.push_back(i);
    }
    int s=p.size();
    int z=0;
    for(int i=0;i<s;i++){
        for(int j=i+1;j<s;j++){
            for(int k=j+1;k<s;k++){ z++; //cout<<z<<endl;
                long long n=p[i]*p[j]*p[k]; //cout<<n<<"a"<<endl;
                if(n<3000){
                    if(num[n]==1)
                    for(long long l=n;l<3000;l+=n){
                            num[l]=3; //cout<<l<<endl;
                    }
                }else{
                    break;
                }
            }
        }
    }
    int r=1;
    for(int i=2;i<3000;i++){
        if(num[i]==3){
            lucky[r]=i;
            r++;
        }
    }
    for(int i=0;i<3000;i++){
        //cout<<i<<" "<<num[i]<<endl;
    }
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>n;
        cout<<lucky[n]<<endl;;
    }
    return 0;
}
