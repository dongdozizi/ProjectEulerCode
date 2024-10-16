#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

ll dp[338351][102][2]={0};
ll a[102]={1,3,6,8,10,11};
int main(){
    for(ll i=0;i<100;i++){
        a[i]=(i+1)*(i+1);
    }
    ll n=100,m=50;
    ll sum=a[n-1];
    for(ll i=0;i<n;i++){
        dp[a[i]][i][0]=1;
    }
    for(ll i=2;i<=m;i++){
        for(ll j=0;j<=sum;j++){
            for(ll k1=0;k1<n;k1++){
                for(ll k2=k1+1;k2<n;k2++){
                    dp[j+a[k2]][k2][1]+=dp[j][k1][0];
                }
            }
        }
        sum+=a[n-i];
        for(ll j=0;j<=sum;j++){
            //cout<<"j - "<<j<<" -- ";
            for(ll k=0;k<n;k++){
                dp[j][k][0]=min(dp[j][k][1],100000ll);
                dp[j][k][1]=0;
                //cout<<dp[j][k][0]<<" ";
            }//cout<<"\n";
        }//cout<<" -------------\n";
    }
    ll ans=0;
    for(ll i=0;i<=sum;i++){
        ll tmp=0;
        for(ll j=0;j<n;j++){
            tmp+=dp[i][j][0];
        }
        if(tmp==1){
            //cout<<i<<" ";
            ans+=i;
        }
    }
    cout<<ans<<"\n";
}
/*
11571
*/