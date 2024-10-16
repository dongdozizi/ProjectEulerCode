#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n=100000000000ll;
bool isp[20000007]={0};
ll minp[20000007]={0};
ll thr[245]={0};
ll pcnt[20000007]={0};
ll qpow(ll a,ll b,ll mod){
    if(b==0) return 1;
    if(b==1) return a;
    ll c=qpow(a,b/2,mod);
    if(c&1) return c*c%mod*a%mod;
    else return c*c%mod;
}
void init(){
    thr[1]=0,thr[3]=1,thr[9]=2,thr[27]=3,thr[81]=4,thr[243]=5;
    for(ll i=2;i<=10000000;i++){
        isp[i]=!isp[i];
        if(!isp[i]) continue;
        for(ll j=i*i;j<=10000000;j+=i) isp[j]=1;
    }
    pcnt[1]=1;
    for(ll i=2;i<=10000000;i++){
        //if(i%100000==0) cout<<i<<"\n";
        if(isp[i]){
            if(i*i>=100000000){
                minp[i]=i;
                if(i%3==1) pcnt[i]=3;
                else pcnt[i]=1;
                continue;
            }
            ll i2=i;
            while(i2<=20000000){
                //cout<<i2<<" -- ";
                ll cnt=0;
                for(ll j=1;j<i2;j++){
                    if(j*j%i2*j%i2==1){
                        //cout<<j<<","<<(j*j%i2*j)/i2<<" - ";
                        pcnt[i2]++;
                        cnt++;
                    }
                }
                minp[i2]=i;
                if(cnt>3){
                    exit(0);
                }
                //cout<<"\n";
                i2=i2*i;
            }
        }
    }
    for(ll i=1;i<=10000000;i++){
        if(pcnt[i]>3){
            cout<<"_______ASDLKJLSDKJALKSJDALKJSDKL\n";
        }
    }
    // for(ll i=1;i<=1000;i++){
    //     cout<<i<<" "<<pcnt[i]<<" "<<minp[i]<<" "<<isp[i]<<"\n";
    // }
}
ll cai(ll x){
    ll ret=0;
    for(ll i=1;i<x;i++){
        if(i*i%x*i%x==1) ret++;
    }
    return ret;
}
ll ans=0;
void calc(ll st,ll cur,ll sm){
    //cout<<st<<" "<<cur<<" "<<sm<<"\n";
    if(sm==243){
        //cout<<st<<" "<<cur<<" "<<sm<<" "<<cai(cur)<<"\n";
        ans+=cur;
        for(ll i=st;i<=n/cur;i++){
            if(minp[i]>=st&&pcnt[i]==1){
                calc(minp[i]+1,cur*i,sm);
            }
        }
        return;
    }
    ll lg=pow(n/cur,1.0/thr[243/sm])+10;
    for(ll i=st;i<=min(n/cur,lg);i++){
        ll now=1;
        if(minp[i]>=st){
            calc(minp[i]+1,cur*i,sm*pcnt[i]);
        }
    }
}
int main(){
    //cout<<cai(47907018978)<<"\n";
    cout<<n/7/9/13/19<<"\n";
    init();
    cout<<"Init Over\n";
    calc(2,1,1);
    cout<<ans<<"\n";
}
/*
# include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100000000000;
const int Q=242;
const int O=log(Q+1)/log(3)+1e-8;
const ll M=N/7/13/19/9+200;
int vis[M+4];
int pr[M/10+1000],m=0;
ll v[M+4];
ll ans=0,s[M+4];
void dfs(int f,int pos,ll n){
    if(f==0){
        ans+=s[N/n]*n;
        return;
    }
    for(int i=pos;i<=m;i++){
        ll ok=n;
        for(int k=0;k<f&&i+k<=m&&ok<=N;k++)
            ok*=pr[i+k];
        if(ok>N) break;
        for(ll k=n*pr[i];k<=N;k*=pr[i])
            dfs(f-1,i+1,k);
    }
}
int main(){
    s[1]=1;
    for(int i=2;i<=M;i++){
        if(v[i]==0){
            v[i]=i;pr[++m]=i;
            s[i]=(i%3==2);
        }
        for(int j=1;j<=m;j++){
            if(pr[j]>v[i]||pr[j]>M/i) break;
            v[i*pr[j]]=pr[j];
            s[i*pr[j]]=pr[j]%3==2?s[i]:0;
        }
    }
    int t=m;m=0;
    for(int i=1;i<=t;i++)
        if(pr[i]%3==1) pr[++m]=pr[i];
    for(int i=1;i<=M;i++)
        s[i]=s[i-1]+s[i]*i;
    dfs(O,1,1);dfs(O,1,3);
    for(ll k=9;k<=N;k*=3)
        dfs(O-1,1,k);
    printf("%lld\n",ans);
}


8140339356290894563
actual answer:8495585919506151122
*/