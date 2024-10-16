#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;

ll n,m;
ll mod=1e9+7,modinv;

ll gcd(ll x,ll y){
    if(x==0) return y;
    else return gcd(y,x%y);
}
ll lcm(ll x,ll y){
    return x*y/gcd(x,y);
}

ll sig[10004];
ll tao[10004];
ll taoinv[10004];
ll pi[10004];

ll pa[10004],sz[10004];

ll cur[10004];

ll findpa(ll x){
    if(pa[x]==x) return x;
    else return pa[x]=findpa(pa[x]);
}

void unite(ll x,ll y){
    x=findpa(x);
    y=findpa(y);
    if(x==y) return;
    if(sz[x]>sz[y]){
        pa[y]=x;
        sz[x]+=sz[y];
    }
    else{
        pa[x]=y;
        sz[y]+=sz[x];
    }
}

int main(){
    m=100;
    n=m*(m+1)/2;
    for(ll i=1;i<=n;i++){
        tao[i]=mod*i%n+1;
        taoinv[tao[i]]=i;
    }
    for(ll i=1;i<=n;i++) cur[i]=i;
    for(ll i=1;i<=10000;i++) sig[i]=i+1;
    for(ll i=1;i<=101;i++){
        sig[i*(i+1)/2]=i*(i-1)/2+1;
    }
    for(ll i=1;i<=n;i++){
        pi[i]=taoinv[sig[tao[i]]];
    }
    for(ll i=1;i<=n;i++){
        pa[i]=i;
        sz[i]=1;
    }
    for(ll i=1;i<=n;i++){
        unite(pi[i],i);
    }
    ll cur=1;
    for(ll i=1;i<=n;i++){
        if(pa[i]!=i) continue;
        cout<<i<<" - "<<sz[i]<<"\n";
        cur=lcm(cur,sz[i]);
        cout<<cur<<"\n";
    }
    // for(ll i=1;i<=n;i++){
    //     cout<<i<<" - "<<tao[i]<<" "<<taoinv[i]<<" "<<sig[i]<<" "<<pi[i]<<"\n";
    // }
    // for(ll i=1;i<=1;i++){
    //     for(ll j=1;j<=n;j++){
    //         cur[j]=pi[cur[j]];
    //         cout<<cur[j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<"\n";
}
/*
1 2 3

*/