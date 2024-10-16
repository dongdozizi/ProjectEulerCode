#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b%a,a);
}
// bool check(ll n,ll m){
//     if(m==0||n==m) return false;
//     if(gcd(n,m)==1)
//     return true;
// }

ll calc(ll n){
    if(n%2==0) return 0;
    ll ans=0;
    n=(n+3ll)/2ll;
    
    for(ll i=(n%3==0?0:3-n%3);i<=n;i+=3){
        if(gcd(n,i)==1) ans++;
//        if(check(n,i)) ans++;
    }
    return ans;
}

int main(){
    cout<<calc(11)<<"\n";
    cout<<calc(1000001)<<"\n";
    cout<<calc(12017639147)<<"\n";
}