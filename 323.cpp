#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n=1;
ld dp[20][200];
ld cnm[50][50];
ll sn[100005];
ld mydp[44];
ld tw[50];
ld f(ll cur,ld step,ld gai){
    //cout<<cur<<" "<<step<<" "<<gai<<"\n";
    dp[n][cur]+=step*gai;
    if(cur==1) return 0.0;
    if(cur==(1<<n)-1){
//        dp[n][cur]+=step*gai;
        return step*gai;
    }
    //if(step>10) return 0;
    if(step&&gai*step<=1e-9) return gai*step;
    ld ret=0;
    for(ll i=0;i<(1<<n);i++){
        ret+=f(cur|(i),step+1,gai/(1<<n));
    }
    return ret;
}
void init(){
    cnm[0][0]=1.0;
    for(ll i=1;i<=32;i++){
        cnm[i][0]=cnm[i][i]=1.0;
        for(ll j=1;j<i;j++){
            cnm[i][j]=cnm[i-1][j-1]+cnm[i-1][j];
        }
    }
    tw[0]=1.0;
    for(ll i=1;i<=32;i++) tw[i]=tw[i-1]*2.0;
}
int main(){
    init();
    mydp[0]=0.0;
    mydp[1]=2.0;
    for(ll i=2;i<=32;i++){
        mydp[i]=1.0/tw[i];
        for(ll j=0;j<i;j++){
            mydp[i]+=cnm[i][j]*(1.0+mydp[j])/tw[i];
        }
        mydp[i]/=(1.0-1.0/tw[i]);
        cout<<i<<" "<<setprecision(20)<<mydp[i]<<"\n";
    }
}