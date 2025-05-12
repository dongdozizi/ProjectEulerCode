#include<iostream>
#include<vector>
#include<math.h>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod=1234567891;
ll tw[10000007];
ll qpow(ll a,ll b){
    if(b==0) return 1;
    ll c=qpow(a,b/2);
    c=(c*c)%mod;
    if(b%2==1) c=(c*a)%mod;
    return c;
}
ll calc(ll l,ll r){
    if((l+r)%2ll==0) return((l+r)/2ll%mod)*((r-l+1)%mod)%mod;
    else return((l+r)%mod)*((r-l+1)/2ll%mod)%mod;
}
int main(){
    ll sum=0;
    ll n=100000000000000ll;
    // for(int i=1;i*i<=n;i++){
    //     ll p1=n/i-1;
    //     ll p2=n-p1-1;
    //     sum+=i*(qpow(2,p1)-1)*(qpow(2,p2));
    // }
    sum=0;
    //n=10;
    ll cnt=0;
    for(ll l=1;l<=n;){
        ll k=n/l;
        ll r=n/k;
        ll p1=k-1;
        ll p2=n-p1-1;
        // if(cnt%1000000==0)
        // printf("%lld - %lld %lld %lld %lld %lld\n",cnt,l,r,k,p1,p2);
        sum+=calc(l,r)*(qpow(2,p1)-1ll)%mod*qpow(2,p2)%mod;
        l=r+1;
        cnt++;
    }
    sum=sum%mod;
    cout<<sum<<"\n";
}