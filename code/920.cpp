#include<iostream>
#include<vector>
#include<math.h>
#include<map>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
const ll n=42000;
ll N=1e16;
vector<ll> prim={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};
vector<ll> fact[n+5];
vector<pair<ll,ll>> fpow[n+5];
ll fast[105];
ll inf=1e18;
ll ptt=0;
lll qpow(lll a,lll b){
    if(b==0) return 1;
    lll c=qpow(a,b/2);
    if(c>=inf||c*c>=inf) return inf;
    if(b%2==0) return c*c;
    else return c*c*a;
}
ll calc(ll sz,ll n){
    vector<vector<ll>> vx,sub;

    for(ll i=0;i<(1<<sz);i++){
        vector<ll> tmp;
        for(ll j=0;j<sz;j++){
            if((1<<j)&i) tmp.push_back(fast[j]);
        }
        if(tmp.size()==fpow[n].size()){
            vx.push_back(tmp);
        }
    }
    sort(vx.begin(),vx.end());
    vx.erase(unique(vx.begin(),vx.end()),vx.end());
    {
        vector<ll> tmp;
        for(ll j=0;j<fpow[n].size();j++){
            tmp.push_back(j);
        }
        do{
            sub.push_back(tmp);
        }while(next_permutation(tmp.begin(),tmp.end()));
    }
    lll cur=inf;
    for(vector<ll> &wx:vx){
        for(vector<ll> &wsub:sub){
            vector<ll> tmpFast,tmpFpow;
            lll mul=1;
            for(ll i=0;i<fpow[n].size();i++){
                tmpFpow.push_back(fpow[n][i].second+1);
                mul=mul*qpow(fpow[n][i].first,fpow[n][i].second);
            }
            for(ll i=0;i<sz;i++){
                tmpFast.push_back(fast[i]);
            }
            vector<int> tmpSub;
            set_difference(tmpFast.begin(),tmpFast.end(),wx.begin(),wx.end(),back_inserter(tmpSub),greater<int>());
            
            for(ll i=0;i<wsub.size();i++){
                ll cur=tmpFpow[wsub[i]];
                if(tmpFpow[wsub[i]]>wx[i]){
                    mul=inf;
                    break;
                }
                tmpFpow[wsub[i]]=wx[i];
                if(qpow(fpow[n][wsub[i]].first,tmpFpow[wsub[i]]-cur)>=inf){
                    mul=inf;
                    break;
                }
                mul=mul*qpow(fpow[n][wsub[i]].first,tmpFpow[wsub[i]]-cur);
                if(mul>=inf) break;
            }
            if(mul>=inf) continue;
            for(ll i=0,j=0;i<prim.size()&&j<tmpSub.size();i++){
                for(ll k=0;k<fpow[n].size();k++){
                    if(fpow[n][k].first==prim[i]){
                        goto nex;
                    }
                }
                if(qpow(prim[i],tmpSub[j]-1)>=inf){
                    mul=inf;break;
                }
                mul=mul*qpow(prim[i],tmpSub[j++]-1);
                if(mul>=inf) break;
                nex:;
            }
            cur=min(cur,mul);
        }
    }
    return cur;
}
void dfs(ll cur,ll sz,ll x,ll mul,ll n,ll &ans){
    if(mul>N) return;
    if(x==1){
        ans=min(ans,calc(sz,n));
        return;
    }
    for(ll i:fact[x]){
        if(i>cur) continue;
        fast[sz]=i;
        lll qp=qpow(prim[sz],i-1);
        if(qp>=inf||qp*mul>=inf) continue;
        dfs(i,sz+1,x/i,mul*qp,n,ans);
    }
}
int main(){
    for(ll i=2;i<=n;i++){
        for(ll j=i;j<=n;j+=i){
            fact[j].push_back(i);
        }
    }
    for(ll i=2;i<=n;i++){
        if(fpow[i].size()==0){
            for(ll j=i;j<=n;j+=i){
                ll cnt=0,jj=j;
                while(jj%i==0){
                    jj/=i;
                    cnt++;
                }
                fpow[j].emplace_back(i,cnt);
            }
        }
    }
    for(ll i=2;i<=n;i++){
        reverse(fact[i].begin(),fact[i].end());
    }
    ll sum=1;
    for(ll i=2;i<=n;i++){
        ll ans=inf;
        //printf(" --- %lld\n",i);
        dfs(i,0,i,1,i,ans);
        if(ans<=N){
            //printf("i,ans %lld %lld\n",i,ans);
            sum+=ans;
        }
        // if(i%100000==0){
        //     printf("%lld %lld\n",i,ptt);
        // }
    }
    printf("%lld\n",sum);
}
/*
if x=pr[1]*pr[2]*...*pr[n] then pr[1]^(pr[n]-1)*pr[2]^(pr[n-1]-1)
if x=pr[1]^a[1]*pr[2]^a[2]*pr[3]^a[3]
20
232
3189
34170
549523
9658824
145432809

1 1
2 2
3 9
4 8
5 625
6 12
8 24
9 36
10 80
12 60
14 448
16 384
18 180
20 240
24 360
30 720
3189
*/