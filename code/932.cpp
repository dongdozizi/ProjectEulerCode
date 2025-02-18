#include<iostream>
#include<vector>
#include<math.h>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;

ll logten[100000008];
ll tenpow[102];

ll calc(ll i,ll ilog,ll jlog){
    if(ilog<=0||jlog<=0||ilog+jlog>16) return 0;
    ll ip=i*(tenpow[jlog]-i);
    ll delta=(2*i-1)*(2*i-1)+ip*4;
    if(delta<0) return 0;
    ll sqd=sqrt(delta);
    if(sqd*sqd!=delta){
        sqd--;
        if(sqd*sqd!=delta){
            sqd+=2;
            if(sqd*sqd!=delta) return 0;
        }
    }
    //cout<<i<<" "<<ilog<<" "<<jlog<<" "<<ip<<" "<<sqd<<" "<<delta<<"\n";
    ip=1-2*i+sqd;
    if(ip%2!=0||ip<0) return 0;
    ip/=2;
    if(logten[ip]==jlog){
        //cout<<i<<" "<<ip<<" "<<(i+ip)*(i+ip)<<"\n";
        return (i+ip)*(i+ip);
    }
    return 0;
}

int main(){
    logten[0]=0;
    for(ll i=1;i<=100000000;i++){
        logten[i]=logten[i/10]+1;
    }
    tenpow[0]=1;
    for(ll i=1;i<=100;i++){
        tenpow[i]=tenpow[i-1]*10;
    }
    ll ans=0;
    for(ll i=1;i<=99999999;i++){
        if(i*i>=100000000000000000ll) break;
        ll ilog=logten[i];
        ans+=calc(i,ilog,ilog-1);
        ans+=calc(i,ilog,ilog);
        ans+=calc(i,ilog,ilog+1);
        //cout<<i<<"\n";
    }
    cout<<ans<<"\n";
}