#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;

long double f(long double u){
    return floor(pow(2,30.403243784-u*u))/1e9;
}

int main(){
    long double u0=-1.0;
    for(ll i=0;i<1000;i++){
        long double u1=f(u0);
//        long long u11=u1;
//        cout<<i<<" "<<u11<<" "<<"\n";
        cout<<setprecision(11)<<u0+u1<<"\n";
        u0=u1;
    }
}