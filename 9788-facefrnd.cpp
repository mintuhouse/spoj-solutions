#include<iostream>
#include<set>
using namespace std;

int main(){
    int N;
    set<int> frnd;
    set<int> fof;
    cin>>N;
    for(int i=0;i<N;i++){
        int id, M;
        cin>>id>>M;
        frnd.insert(id);
        if(fof.end()!=fof.find(id)) fof.erase(id);
        for(int j=0;j<M;j++){
            cin>>id;
            if(frnd.end()==frnd.find(id)) fof.insert(id);
        }
        //cout<<frnd.size()<<" "<<fof.size()<<endl;
    }
    cout<<fof.size()<<endl;
    return 0;
}
