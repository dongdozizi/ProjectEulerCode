#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
ll a[10005];
unordered_map<ll,ll> mp;
ll f(ll x){
    if(mp.count(x)) return mp[x];
    if(x%2==0) return mp[x]=2ll*f(x/2);
    else return mp[x]=f(x/2)-3ll*f(x/2+1);
}
int main(){
    mp[1]=1;
    cout<<4ll-f(1000000000000ll/2ll)<<"\n";
}
/*
a2n=2an
a2n+1=an-3an+1
a2n-a2n+1=an+3an+1
a2n+a2n+1=3an-3an+1
a2n-2+a2n-1+a2n+a2n+1=3an-1-3an+3an-3an+1=
a1+a2+a3+a4+a5+a6...+a2n=4-an
a[1000000000000]
*/