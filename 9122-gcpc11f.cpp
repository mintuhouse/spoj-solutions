#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main(){
    int c;
    string s;
    char S[1001];
    int n[26];
    cin>>c;
    getline(cin,s);
    for(int i=0;i<c;i++){
        for(int j=0;j<26;j++) n[j]=0;
        getline(cin,s);
        strcpy(S,s.c_str());
        int sz=strlen(S);
        for(int j=0;j<sz;j++){
            if(S[j]!=' '){
                n[(int)(S[j]-'A')]++;
            }
        }
        //for(int j=0;j<26;j++) cout<<(char)(j+'A')<<" "<<n[j]<<endl;
        int max=n[0], maxj=0;
        for(int j=1;j<26;j++){
            if(n[j]>max){
                max=n[j];
                maxj=j;
            }else if(n[j]==max){
                maxj=-1;
            }
        }
        if(maxj==-1){
            cout<<"NOT POSSIBLE"<<endl;
        }else{
            if(maxj-4<0)cout<<(maxj+22)<<" ";
            else cout<<maxj-4<<" ";
            for(int j=0;j<sz;j++){
                if(S[j]==' ') cout<<' ';
                else cout<<(char)((((unsigned int)(S[j]+(int)'A'-maxj+4))%26)+(int)'A');
            }
            cout<<endl;
        }
    }
    return 0;
}
