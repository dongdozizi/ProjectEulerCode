#include<iostream>
using namespace std;
typedef long long ll;
ll N=10000000,cantMask=0,ans=0,tmp=0;
void dfs(ll x,ll curY,ll cnt,ll curResult,ll curMask,bool canAdd){
    tmp++;
    if((curResult&curMask)||(cnt>=24)||(curY>x)) return;
    if(canAdd&&(!(curResult&cantMask))&&x>=curY) ans++;
    dfs(x,curY|(1ll<<cnt),cnt+1,curResult^(x<<cnt),curMask|(1ll<<((cnt/2)*2)),true);
    dfs(x,curY,cnt+1,curResult,curMask|(1ll<<((cnt/2)*2)),false);
}
int main(){
    for(int i=0;i<30;i++) cantMask|=(1ll<<(i*2));
    for(ll i=0;i<=N;i++) dfs(i,0,0,0,0,true);
    cout<<ans;
}