#include<iostream>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include <iomanip>
using namespace std;

int main(){
    int n;
    long double a,b,c,ga,gb,gc,S,R,HG,s;
    cin>>n;
    cout<<fixed;
    for(int i=0;i<n;i++){
        cout<<setprecision(11);
        cin>>a>>ga>>gb>>gc;
        //S=3*a*ga/2;
        b=a*ga/gb;
        c=a*ga/gc;
        s=(a+b+c)/2;
        S=sqrt(s*(s-a)*(s-b)*(s-c));
        R=a*b*c/4/S;
        //R=a*a*ga/6/gb/gc;
        HG=2*(sqrt(9*R*R-a*a-b*b-c*c))/3;
        //cout<<9*R*R<<" "<<(a*a+b*b+c*c)<<endl;
        //HG=2/3*(sqrt((9*a*a*b*b*c*c-16*S*S*(a*a+b*b+c*c))/16/S/S));
        //HG=2*(sqrt(((a*a*a*a*ga*ga)-(4*a*a*gb*gb*gc*gc)-(4*a*a*ga*ga*gc*gc)-(4*a*a*ga*ga*gb*gb))/(4*gb*gb*gc*gc)))/3;
        //cout<<(a*a*a*a*ga*ga)<<" "<<(4*a*a*gb*gb*gc*gc)+(4*a*a*ga*ga*gc*gc)+(4*a*a*ga*ga*gb*gb)<<endl;
        //cout<<a<<" "<<b<<" "<<c<<" "<<ga<<" "<<gb<<" "<<gc<<" "<<S<<" "<<R<<" "<<HG<<endl;

        cout<<setprecision(3);
        cout<<S<<" "<<HG<<endl;
    }
    return 0;
}
