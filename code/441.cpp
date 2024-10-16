#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef long double ld;
ld sum[10000007]={0};
ld divn[10000007]={0};
vector<ll> divs[10000007];
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
ll M=10000000;
ld divsum(ll x,ll l,ll r){ /*num of divs in [l,r]*/
    l=l%x==0?l/x-1:l/x;
    r=r/x;
    return divn[x]*(sum[r]-sum[l]);
}
ll divnum(ll x,ll l,ll r){
    l=l%x==0?l/x-1:l/x;
    r=r/x;
    return r-l;
}

ld f(ll x){
    ll l0=x+1,r0=max(M-x,x);
    ll l1=max(x+1,M-x+1),r1=M;
    ll n=divs[x].size();
    ld ret=0;
    //cout<<"x - "<<x<<" "<<l0<<" "<<r0<<" | "<<l1<<" "<<r1<<"\n";
    for(ll i=0;i<(1<<n);i++){
        ld mul=1.0;
        ll tmp=1;
        for(ll j=0;j<n;j++){
            if((1<<j)&i){
                mul=mul*-1.0;
                tmp=tmp*divs[x][j];
            }
        }
        // i<=M-x (x+1)/(x*i)=(x+1)/x * (1/i)
        ret+=mul*(x+1.0)/x*divsum(tmp,l0,r0);
        // i>M-x (M-i+1)/(x*i)=(M+1)/x * (1/i) - 1/x
        ret+=mul*((M+1.0)/x*divsum(tmp,l1,r1)-(1.0*divnum(tmp,l1,r1))/x);
        //cout<<"tmp "<<tmp<<" "<<mul<<" "<<(x+1.0)/x*divsum(tmp,l0,r0)<<" "<<(M+1.0)/x*divsum(tmp,l1,r1)<<" "<<divnum(tmp,l1,r1)<<"\n";
        //cout<<tmp<<" "<<l<<" "<<M<<" "<<mul<<" "<<div(tmp,l,M)<<"\n";
        //ret+=mul*div(tmp,l,r);
    }
    //cout<<"ret - "<<"\n";
    return ret;
}
int main(){
    // double aps=0;
    // ll cnt=0;
    // for(ll i=1;i<=M;i++){
    //     for(ll j=i+1;j<=M;j++){
    //         if(gcd(i,j)==1){
    //             cnt++;
    //             aps+=(min(i,M-j)+1.0)/(i*j);
    //         }
    //     }
    // }
    // cout<<aps<<" "<<cnt<<"\n";
    // sum[0]=0;
    for(ll i=1;i<=M;i++) divn[i]=1.0/i;
    for(ll i=1;i<=M;i++) sum[i]=sum[i-1]+divn[i];
    for(ll i=2;i<=M;i++){
        if(divs[i].size()!=0) continue;
        for(ll j=i;j<=M;j+=i) divs[j].push_back(i);
    }
    cout<<" Init over\n";
    ld ans=0;
    for(ll i=1;i<=M;i++){
        //if(i%(M/100)==0) cout<<i<<"\n";
        ans+=f(i);
    }
    cout<<setprecision(25)<<ans<<"\n";
}