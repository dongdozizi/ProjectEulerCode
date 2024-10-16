#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;
ll dp[50][50]={0};
ll sm[60]={0};
ll calc(ll n){
    n++;
    ll ctt=0;
    while()
}
int main(){
    sm[0]=1;
    for(ll i=1;i<=60;i++){
        sm[i]=sm[i-1]*2+(1<<(i-1));
        cout<<i<<" "<<sm[i]<<"\n";
    }
    cout<<calc(7)<<"\n"<<calc(7*7)<<"\n";
    dp[0][0]=0;
    for(ll i=0;i<50;i++){
        dp[0][i]=dp[i][0]=0;
    }
    ll ans=1;
    for(ll i=1;i<50;i++){
        ans++;
        for(ll j=1;j<50;j++){
            dp[i][j]=0;
            ll tp=min(i,j);
            for(ll k=0;k<=tp;k++){
                if(i-k==0||(j-tp+k)==0){
                    continue;
                }
                if(dp[i-k][j-tp+k]==0){
                    dp[i][j]=1;break;
                }
            }
            if(i>=j&&dp[i][j]==0) ans++;
            //cout<<dp[i][j]<<"";
        }cout<<i<<" "<<ans<<"\n";
    }
    cout<<ans<<"\n";
}
/*
1
2
1
4
1
8
1
2
1
4
1
2
1
16
*/