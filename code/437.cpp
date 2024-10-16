#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
/*
1=a*(a-1)
a+1=a*a
a^n*(a+1)=a^n(a*a)
*/
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
const ll N=10000000;
bool pri[N+7]={0};
int main(){
    for(ll i=2;i<=N;i++){
        if(pri[i]) continue;
        for(ll j=i*i;j<=N;j+=i) pri[j]=1;
    }
    ll ans=0;
    map<ll,ll> mp;
    for(ll i=2;i<=10000;i++){
        if(pri[i]) continue;
        bool ok=0;
        cout<<i<<" - ";
        for(ll j=1;j<=i-1;j++){
            if(gcd(j,i-1)==1&&j*(j-1)%i==1){
                mp[j]++;
                cout<<j<<" ";
                ok=1;break;
            }
        }cout<<"\n";
        if(ok){
            ans+=i;
        }
    }
    for(auto x:mp){
        cout<<x.first<<" "<<x.second<<"\n";
    }
    cout<<ans<<"\n";
}