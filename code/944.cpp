#include<iostream>
#include<vector>
#include<math.h>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod=1234567891;
ll pow2[100005][2],sq;
void init() {
    sq=sqrt(mod);
    pow2[0][0]=pow2[0][1]=1;
    for (ll i=1;i<=sq;++i) pow2[i][0]=pow2[i-1][0]*2%mod;
    ll base=pow2[sq][0];
    for (ll i=1;i<=sq;++i) pow2[i][1]=pow2[i-1][1]*base%mod;
}
ll power2(ll b) {
    b%=mod-1;
    return pow2[b%sq][0]*pow2[b/sq][1]%mod;
}
ll calc(ll l,ll r){
    if((l+r)%2ll==0) return((l+r)/2ll%mod)*((r-l+1)%mod)%mod;
    else return((l+r)%mod)*((r-l+1)/2ll%mod)%mod;
}
int main(){
    init();
    ll n=100000000000000ll;
    ll sum=calc(1,n)*power2(n-1)%mod;
    for(ll l=1,r,k;l<=n;l=r+1){
        k=n/l,r=n/k;
        sum-=calc(l,r)*power2(n-k)%mod;
    }
    cout<<(sum%mod+mod)%mod<<"\n";
}