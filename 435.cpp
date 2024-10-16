#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
ll fib[100005]={0,1};
ll dp[6]={2,3,5,7,11,13};
ll mod[6];
ll ans[6]={0};
ll n=1000000000000000;
ll lop[6]={0};
ll qpow(ll a,ll b,ll mod){
    if(b==0) return 1;
    ll c=qpow(a,b/2,mod);
    if(b%2==0) return c*c%mod;
    else return c*c%mod*a%mod;
}
ll firstN(ll inv,ll p,ll cnt,ll mod){
    if(p==0) return 0;
    if(p==1) return cnt;
    return (qpow(p,cnt,mod)-1)*inv;
}
/*
s0=1+p+p^2+...+p^(n-1)
ps0=p+p^2+...+p^n
(p-1)s0=p^n-1
s0=p^n-1/p-1
a0*(1+)
*/
int main(){
    for(ll i=2;i<=30;i++){
        fib[i]=(fib[i-1]+fib[i-2])%13;
        cout<<i<<" "<<fib[i]<<"\n";
    }
    ll mul=1;
    for(ll i=1;i<=15;i++) mul*=i;
    for(ll i=0;i<6;i++){
        ll cnt=0;
        mod[i]=1;
        while(mul%dp[i]==0){
            mod[i]*=dp[i];
            mul/=dp[i];
            cnt++;
        }
        cout<<dp[i]<<" "<<cnt<<" "<<mod[i]<<"\n";
        pair<ll,ll> pp;
        pp.first=0;pp.second=1;
        map<pair<ll,ll>,ll > mp;
        lop[i]=1;
        mp[pp]=1;
        while(true){
            ll p3=pp.second;
            pp.second=(pp.second+pp.first)%mod[i];
            pp.first=p3;
            //cout<<lop[i]<<" --- "<<pp.first<<" "<<pp.second<<"\n";
            if(mp.count(pp)) break;
            mp[pp]=1;
            lop[i]++;
        }
        cout<<lop[i]<<"\n";
    }
    for(ll i=0;i<6;i++){
        ans[i]=0;
        fib[0]=0;fib[1]=1;
        for(ll j=2;j<lop[i];j++){
            fib[j]=(fib[j-1]+fib[j-2])%mod[i];
        }
        for(ll j=1;j<=100;j++){
            ll nw=1,gb=qpow(j,lop[i],mod[i]);
            ll ginv;
            for(ll k=1;k<mod[i];k++){
                if((gb-1)*k%mod[i]==1){
                    ginv=k;break;
                }
            }
            for(ll k=0;k<lop[i];k++){
                ans[i]=(ans[i]+fib[i]*nw%mod[i]*firstN(ginv,gb,(n-k)/lop[i]+1,mod[i]))%mod[i];
                nw=nw*j%mod[i];
            }
        }
        cout<<"finish - "<<i<<" - "<<ans[i]<<"\n";
    }
    ll gg=252541322550;
    for(ll i=0;i<6;i++){
        cout<<gg%mod[i]<<"\n";
    }
    // for(ll i=0;i<6;i++){
    //     cout<<ans[i]<<"\n";
    // }
}