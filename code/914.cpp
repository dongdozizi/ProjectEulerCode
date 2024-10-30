#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
#include<map>

#include<set>
#include<utility>
#include<algorithm>
#include<unordered_set>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main(){
    ll mx=2000000000000000000ll;
    //mx=200;
    ll ans=0;
    double pt=sqrt(2.0)+1;
    ll ns=sqrt(2e18/(1.0+pt*pt));
    ll ms=ns*pt;
    // cout<<ns<<" "<<ms<<"\n";
    // cout<<ms*ms+ns*ns<<"\n";
    for(ll n=ns-1000;n<=ns+10000;n++){
        if(n%2==1) continue;
        for(ll m=ms-1000;m<=ms+10000;m++){
            if(m%2==0) continue;
            if(gcd(m,n)!=1) continue;
            ll a=m*m-n*n;
            ll b=2ll*m*n;
            ll c=m*m+n*n;
            if(c<mx){
                ans=max(ans,a+b-c);
            }
            else{
                break;
            }
           // cout<<m*m+n*n<<" "<<1e18-m*m-n*n<<"\n";
        }
    }
    cout<<ans/2;
}
/*
m*n*n+2mn-m*m-n*n
m*m+n*n<1e18
mn-n*n=n*(m-n)
m=13 n=4
n*(m-n)
m*m+n*n
m=an
(1+a*a)*n*n<=mg
(a-1)*n*n<=mg/(1+a*a)*(a-1)
(a-1)/(1+a*a)

(1+x^2)^2
4x(1+x^2)
1=4x(x-1)
4x*x-4x-1
1=x()
(1+x^2)^2-4x(x-1)*(1+x^2)=0 (1+x^2)^4
1+x*x-4x*x+4*x
3*x*x-4*x-1
x=4+sqrt(16+12)/6
2+sqrt(7)/3
*/