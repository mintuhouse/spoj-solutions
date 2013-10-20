#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){map<char,int> P;for(int i=0,j=0;i<26;i++,j++){if(i==9)j--;P[(char)(i+65)]=((j/5)+1)*10+((j%5+1));}string s;int t;cin>>t;getline(cin,s);for(int i=0;i<t;i++){getline(cin,s);int sz=s.size();for(int j=0;j<sz;j++){if(s[j]!=' '){cout<<P[s[j]]<<" ";}}cout<<endl;}}
