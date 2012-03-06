#include<iostream>
#include<stdio.h>
#include<stack>
#include<stdlib.h>
using namespace std;

void err(){
    printf("COMPILE ERROR\n");
    exit(1);
}

int main(){
    char input[128000];
    int ob[128000],cb[128000],B[12800];
    char prog[32767];
    stack <int> os;
    //for(int i=0;i<32767;i++) prog[i]=0;
    //char * ptr = prog;
    int c,n=0,b=0,bc=0,p=0;
    bool m;
    while((c=getchar())!=EOF){
        if(c=='%') m=1;
        if(m&&c=='\n') m=0;
        if(!m&&c!=' '&&c!='\n'){
            if(c=='['){ bc++; os.push(b); ob[b]=n; B[n]=b; b++; }
            if(c==']'){ bc--; if(bc<0) err(); B[n]=os.top(); cb[os.top()]=n; os.pop();}
            input[n++]=c;
        }
    }
    if(bc!=0 || !os.empty()) err();
    int l=0;b=0;
    while(l<n){
        //cout<<prog[p]<<" "<<l+1<<endl;
        switch(input[l]){
            case '<':
                --p; break;
            case '>':
                ++p; break;
            case '+':
                ++prog[p]; break;
            case '-':
                --prog[p]; break;
            case '.':
                putchar(prog[p]);
                break;
            case '[':
                if(prog[p]==0){
                    l=cb[B[l]]+1;
                }
                break;
            case ']':
                if(prog[p]!=0){
                    l=ob[B[l]]+1;
                }
                break;
            default:
                printf("ERROR\n");
        }
        l++;
    }
    //for(int i=0;i<128000;i++) cout<<input[i]<<endl;
    for(int i=0;i<10;i++) cout<<endl<<ob[i];
    for(int i=0;i<10;i++) cout<<endl<<cb[i];
    for(int i=0;i<32767;i++) cout<<endl<<prog[i];
    return 0;
}
