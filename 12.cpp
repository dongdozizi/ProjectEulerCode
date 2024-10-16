#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
ll calc(ll x){
    ll ans=0;
    for(ll i=1;i*i<=x;i++){
        if(x%i==0){
            ans+=2;
        }
        if(i*i==x) ans--;
    }
    return ans;
}
int main(){
    ll n;
    cin>>n;
    ll ans=1;
    while(true){
        if(calc(ans*(ans+1)/2ll)>=n){
            cout<<calc(ans*(ans+1)/2ll)<<"\n";
            cout<<ans*(ans+1)/2ll;
            break;
        }
        ans++;
    }
}
/*
76576500
*/
