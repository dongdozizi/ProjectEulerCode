#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;
double dp[33][33];
double d2[33][33][2];
ll d[4][2]={1,0,0,-1,-1,0,0,1};
ll n=30,m=30;
void get(ll x,ll y){
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            d2[i][j][0]=d2[i][j][1]=0.0;
        }
    }
    d2[x][y][0]=1.0;
    for(ll k=0;k<50;k++){
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                double div=0.0;
                for(ll k=0;k<4;k++){
                    ll x1=i+d[k][0],y1=j+d[k][1];
                    if(x1<0||x1>=n||y1<0||y1>=n) continue;
                    div+=1.0;
                }
                for(ll k=0;k<4;k++){
                    ll x1=i+d[k][0],y1=j+d[k][1];
                    if(x1<0||x1>=n||y1<0||y1>=n) continue;
                    d2[x1][y1][1]+=d2[i][j][0]/div;
                }
            }
        }
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                d2[i][j][0]=d2[i][j][1];
                d2[i][j][1]=0.0;
            }
        }
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            dp[i][j]*=1.0-d2[i][j][0];
        }
    }
}
int main(){
    //cout<<900.0/exp(1)<<"\n";
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            dp[i][j]=1.0;
        }
    }
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            get(i,j);
        }
    }
    double ans=0;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            ans+=dp[i][j];
        }
    }
    cout<<setprecision(15)<<ans<<"\n";
}