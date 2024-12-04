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
ll s[20000007];
ll mod=998388889; // 29567*33767
ll mod1=29567,mod2=33767;
int main(){
    s[1]=102022661%mod1;
    cout<<mod<<" "<<mod1*mod2<<"\n";
    ll n=10000000;
    for(ll i=2;i<=n*2;i++){
        s[i]=s[i-1]*s[i-1]%mod1;
    }
    for(ll i=1;i<=n*2;i++){
        if(s[i]==s[100]){
            cout<<i<<"\n";
        }
    }
}
/*
a1 a2 a3 a4
a1 a2 a3 a4
a1 a2 a3 a4
a1 a2 a3 a4

b1 b1 b1 b1
b2 b2 b2 b2
b3 b3 b3 b3
b4 b4 b4 b4
a1+b2
dp[2n-1]
p1*a[1]+p2*b[p1]+p3*a[p2]+p4*b[p1+p4]
7391*16882
dp[i][j]=min(dp[i-1][j]+a[i],dp[i][j-1]+b[j]);
dp[i][0]=i*a[0]
dp[i][1]=b[0]+i*min(a[0],a[1])
b[0]*2+a[1]
*/