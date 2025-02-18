#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef __int128 lll;

ll dp[10004][10004]={0};
ll mod=1e9+7;
ll fib[50],fibN=20;
vector<pair<ll,ll> > diff;
int main(){
    fib[0]=fib[1]=1;
    for(ll i=2;i<=fibN;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
    map<ll,ll> sqMap;
    for(ll i=0;i<=10000;i++) sqMap[i*i]=i;
    for(ll i=1;i<=fibN;i++){
        for(ll j=0;j<=fib[i];j++){
            if(sqMap.count(fib[i]*fib[i]-j*j)){
                diff.emplace_back(sqMap[fib[i]*fib[i]-j*j],j);
            }
        }
    }
    for(auto &p : diff){
        cout<<p.first<<" "<<p.second<<"\n";
    }
    dp[0][0]=1;
    for(ll i=0;i<=10000;i++){
        for(ll j=0;j<=10000;j++){
            for(auto &p : diff){
                if(i+p.first<=10000 && j+p.second<=10000){
                    dp[i+p.first][j+p.second]=(dp[i+p.first][j+p.second]+dp[i][j])%mod;
                }
            }
        }
        if(i%100==0){
            cout<<i<<" "<<dp[i][i]<<"\n";
        }
    }
    cout<<dp[10000][10000]<<"\n"<<dp[10][10]<<"\n";
}
