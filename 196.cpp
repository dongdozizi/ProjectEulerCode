#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
bool isp[10000007]={0};
bool ckp[5][10000007]={0};
ll d[8][2]={0,1,1,1,1,0,1,-1,0,-1,-1,-1,-1,0,-1,1};
bool ok(bool ck[5][5]){
    ll cnt=0,x,y;
    ck[2][2]=0;
    for(ll i=0;i<8;i++){
        if(ck[2+d[i][0]][2+d[i][1]]){
            cnt++;
            x=2+d[i][0],y=2+d[i][1];
        }
    }
    if(cnt>=2) return true;
    if(cnt==0) return false;
    for(ll i=0;i<8;i++){
        if(ck[x+d[i][0]][y+d[i][1]]) return true;
    }
    return false;
}
ll f(ll N){
    memset(ckp,0,sizeof(ckp));
    for(ll n=N-2;n<=N+2;n++){
        ll st=n*(n-1)/2ll+1,ed=n*(n+1)/2ll;
        //cout<<st<<" "<<ed<<"\n";
        for(ll i=2;i<=n;i++){
            if(isp[i]) continue;
            ll jst=st%i==0?st:((st/i+1)*i);
            for(ll j=0;jst+j*i<=ed;j++){
                ckp[n-N+2][jst+j*i-st]=1;
            }
        }
        for(ll i=0;i<n;i++){
            ckp[n-N+2][i]=!ckp[n-N+2][i];
            //cout<<ckp[n-N+2][i];
        }
        //cout<<"\n";
    }
    ll ret=0;
    bool ck[5][5]={0};
    for(ll i=0;i<N;i++){
        if(ckp[2][i]==0) continue;
        for(ll j1=0;j1<5;j1++){
            for(ll j2=0;j2<5;j2++){
                if(i+j2-2<0) ck[j1][j2]=0;
                else ck[j1][j2]=ckp[j1][i+j2-2];
            }
        }
        if(ok(ck)) ret+=N*(N-1)/2ll+1+i;
    }
    return ret;
}
int main(){
    for(ll i=2;i<=10000000;i++){
        if(isp[i]) continue;
        for(ll j=i*i;j<=10000000;j+=i) isp[j]=1;
    }
    cout<<f(8)<<"\n"<<f(9)<<"\n";
    cout<<f(10000)<<"\n"<<f(5678027)+f(7208785);
}