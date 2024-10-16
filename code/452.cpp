#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;
//bool pri[];
ll mod=1234567891;
ll m=1000000;
ll n=1000000000;
ll pri[100005]={0};
ll calc[100005][32]={0};
ll ans=0;
ll qpow(ll a,ll b,ll mod){
    if(b==0) return 1;
    ll c=qpow(a,b/2,mod);
    if(b%2==0) return c*c%mod;
    else return c*c%mod*a%mod;
}
int main(){
    for(ll i=2;i<=100000;i++){
        if(!pri[i]){
            for(ll j=i*i;j<=100000;j+=i) pri[j]=1;
        }
    }
    for(ll i=2;i<=100000;i++){
        if(pri[i]) continue;
        ll j=i;
        while(j<=)
    }
}