#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll dp[22][22];
int main(){
    ll n;
    cin>>n;
    dp[0][0]=1;
    for(ll i=1;i<=n;i++){
        dp[i][0]=dp[0][i]=1;
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    cout<<dp[n][n];
}
/*
137846528820
*/
