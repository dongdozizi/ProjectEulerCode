#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll cnm[5]={1,4,6,4,1};
ll ans=0;

void dfs(ll n,ll hand,ll crib,ll runnum,ll runsize,ll ansSum,vector<ll> dp){
    if(crib>340||n==14){
        if(hand==crib) ans+=ansSum;
        return;
    }
    dfs(n+1,hand,crib,0,1,ansSum,dp);
    ll val=min(n,10ll);
    ll lastDp15=dp[15]*2ll;
    for(ll i=1;i<=4;i++){
        ll newCrib=crib+i*(i-1);
        if(runnum>=3) newCrib-=runsize*runnum;
        if(runnum+1>=3) newCrib+=(runsize*i)*(runnum+1);
        for(ll j=15;j>=val;j--) dp[j]+=dp[j-val];
        newCrib=newCrib-lastDp15+dp[15]*2ll;
        dfs(n+1,hand+i*val,newCrib,runnum+1,runsize*i,ansSum*cnm[i],dp);
    }
}

int main(){
    vector<ll> dp(16,0);
    dp[0]=1;
    dfs(1,0,0,0,1,1,dp);
    cout<<ans-1<<"\n";
}