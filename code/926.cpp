#include<iostream>
#include<vector>
#include<math.h>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll pri[10000007]={0};
ll cnt[10000007]={0};
int main(){
    ll n=100000000;
    for(ll i=2;i<=n;i++){
        if(pri[i]==0){
            for(ll j=i;j<=n;j+=i){
                pri[j]=1;
                ll k=j;
                while(k%i==0){
                    k/=i;
                    cnt[i]++;
                }
            }
            pri[i]=0;
        }
    }
    vector<ll> vec;
    for(ll i=2;i<=n;i++){
        if(pri[i]==0){
            vec.push_back(cnt[i]);
            //printf("%lld %lld\n",i,cnt[i]);
        }
    }
    ll ans=0;
    for(ll i=1;i<=vec[0];i++){
        ll tmp=1;
        for(ll j=0;j<vec.size();j++){
            tmp=tmp*(vec[j]/i+1)%mod;
            if(vec[j]/i==0) break;
        }
//        cout<<tmp<<"\n";
        ans=(ans+tmp-1)%mod;
    }
    cout<<ans;
}