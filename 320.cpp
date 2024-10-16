#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<pair<ll,ll> > getyinzi(ll x){
    vector<pair<ll,ll> > ret;
    for(ll i=2;i*i<=x;i++){
        if(x%i==0){
            ll cnt=0;
            while(x%i==0){
                cnt++;x/=i;
            }
            ret.emplace_back(cnt,i);
        }
    }
    if(x>1) ret.emplace_back(1,x);
    return ret;
}

ll f(ll pri,ll cn){
    ll l=1,r=cn;
    while(l<r){
        ll m=(l+r)/2;
        ll tmp=0;
        ll kk=m;
        while(kk){
            tmp+=kk;
            kk/=pri;
        }
        if(tmp<cn) l=m+1;
        else r=m;
    }
    //cout<<pri<<" "<<cn<<" "<<l*pri<<"\n";
    return l*pri;
}
ll cnt[1000006]={0};
int main(){
    ll ans=0;
    ll tmp=0;
    for(ll i=1;i<=10000000;i++){
        vector<pair<ll,ll> > pp=getyinzi(i);
        for(ll i=0;i<pp.size();i++){
            cnt[pp[i].second]+=pp[i].first*1234567890;
            tmp=max(tmp,f(pp[i].second,cnt[pp[i].second]));
        }
        if(i>=10)
        ans=(ans+tmp)%1000000000000000000ll;
        if(i==1000) cout<<ans<<"\n";
    }
    cout<<ans<<"\n";
}