#include<iostream>
#include<cstring>
#include<stdio.h>
#include<cstring>
#include<set>
using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    getchar(); //EOL
    for(int i=0;i<T;i++){
        set<int> frnd[50];
        set<int> fof[50];
        char s[51][51];
        int n=0;
        while( (s[0][n]=getchar())!='\n'){
            if(s[0][n]=='Y'){
                frnd[0].insert(n);
                frnd[n].insert(0);
            }
            n++;
        }
        printf("%d   %d\n",i,n);
        for(int j=1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if((s[j][k]=getchar())=='Y'){
                    frnd[j].insert(k);
                    frnd[k].insert(j);
                }
            }
            getchar(); //EOL
        }
        int max=0,temp=0,p=-1;
        for(int j=0;j<n;j++){
            set<int>::iterator it,jt;
            for(it=frnd[j].begin();it!=frnd[j].end();++it){
                int f=*it;
                for(jt=frnd[f].begin();jt!=frnd[f].end();++jt){
                    if(frnd[j].end()==frnd[j].find(*jt)) fof[j].insert(*jt);
                }
            }
            printf("%d %d\n",j,fof[j].size());
        }
        for(int j=0;j<50;j++){
            frnd[j].clear();
            fof[j].clear();
        }

        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                cout<<"."<<s[j][k];
            }
        }
    }
    return 0;
}
