#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef long double ld;
/*
ld ff(ld x1,ld x3,ll sm){
    if(sm==0){
        return (2.0-pow(x1,4.0)-pow(x3,4.0))*(x3-x1);
    }
    ld x2=pow((pow(x3,4.0)-pow(x1,4.0))/(4.0*(x3-x1)),1.0/3.0);
    //cout<<x1<<" "<<x2<<" "<<x3<<" "<<(x2-x1)/(x3-x1)<<"\n";
    return ff(x1,x2,sm-1)+ff(x2,x3,sm-1);
}
*/
ld ff(ll l,ll r,ld x1,ld x3){
    //cout<<l<<" "<<r<<" "<<x1<<" "<<x3<<"\n";
    if(l+1==r){
        return (x3-x1)*(2.0-pow(x1,4.0)-pow(x3,4.0));
    }
    if(l+2==r){
        ld x2=pow((pow(x3,4.0)-pow(x1,4.0))/(4.0*(x3-x1)),1.0/3.0);
        return ff(l,l+1,x1,x2)+ff(l+1,r,x2,x3);
    }
    ld low=x1,up=x3;
    ld m1,m2;  
    ll m=(l+r)/2;
    ld ret=0;
    while(up-low>=1e-9)  
    {  
        m1=low+(up-low)/3;  
        m2=up-(up-low)/3;
        ld cl=ff(l,m,x1,m1)+ff(m,r,m1,x3),cr=ff(l,m,x1,m2)+ff(m,r,m2,x3);
        if(cl<=cr)  
            low=m1;
        else  
            up=m2;  
        ret=max(cl,cr);
    }  
    return ret;
}
int main(){
    cout<<setprecision(15)<<ff(0,49,0,1.0)<<"\n";
    cout<<setprecision(15)<<ff(0,50,0.0,1.0)<<"\n";
    for(ll i=1;i<=49;i++){
        cout<<i<<" "<<setprecision(15)<<ff(0,i,0,1.0)<<"\n";
    }
    ff(0,50,0,1.0);
}
/*
1.4724703937105774187
1.5705460631769843083
1.5928907349219958434
1.5982487528663076315
1.5995648278582705881
1.5998914721833861208
1.5999728945672846425
*/