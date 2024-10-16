#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll dp[1000006]={0};
ll get(ll i){
    if(i<=1000000){
        if(dp[i]!=0) return dp[i];
        if(i%2==0) return dp[i]=get(i/2ll)+1ll;
        else return dp[i]=get(i*3ll+1ll)+1ll;
    }
    else{
        if(i%2==0) return get(i/2ll)+1ll;
        else return get(i*3ll+1ll)+1ll;
    }
}
int main(){
    dp[1]=1;
    ll ans=1;
    for(ll i=2;i<=1000000;i++){
        get(i);
        if(dp[i]>dp[ans]){
            ans=i;
        }
    }
    cout<<ans<<" "<<dp[13]<<"\n";
}
/*
83799
*/
