#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;

ll n=32,m=10;

ll a[35]={0};

vector<ll> vp[33];

ll dp[12][3340]={0};
int main(){
    vp[1].push_back(1<<1);
    vp[2].push_back(1<<2);
    for(ll i=3;i<n;i++){
        for(ll j=0;j<vp[i-2].size();j++){
            vp[i].push_back(vp[i-2][j]|1<<i);
        }
        for(ll j=0;j<vp[i-3].size();j++){
            vp[i].push_back(vp[i-3][j]|1<<i);
        }
        cout<<vp[i].size()<<"\n";
    }
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<vp[i].size();j++){
            vp[i][j]-=1<<i;
        }
    }
    for(ll i=0;i<vp[n-1].size();i++) dp[0][i]=1;
    ll ans=0;
    for(ll i=1;i<m;i++){
        ll tmp=0;
        for(ll j=0;j<vp[n-1].size();j++){
            for(ll k=0;k<vp[n-1].size();k++){
                if(!(vp[n-1][j]&vp[n-1][k])){
                    dp[i][j]+=dp[i-1][k];
                }
            }
            tmp+=dp[i][j];
        }
        cout<<i<<" "<<tmp<<"\n";
    }
}