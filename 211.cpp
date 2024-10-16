#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;

const ll n=64000000-1;
ll a[n+6]={0};
bool isq(ll ai){
    ll sq=sqrt(ai);
    if(sq*sq==ai) return true;
    sq--;
    if(sq*sq==ai) return true;
    sq+=2;
    if(sq*sq==ai) return true;
    return false;
}
int main(){
    for(ll i=1;i<=n;i++){
        for(ll j=i;j<=n;j+=i){
            a[j]+=i*i;
        }
    }
    ll ans=0;
    for(ll i=1;i<=n;i++){
        if(isq(a[i])){
            ans+=i;
        }
    }
    cout<<ans<<"\n";
}