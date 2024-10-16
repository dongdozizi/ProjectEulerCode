#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;
/*
lcm(n,i)/n=i/gcd(n,i) 
gcd: greatest common divisor
lcm: least common multiple
n(1,N) i(1,n) lcm(n,i)/n = i(1,N) n(i,N) i/gcd(n,i)
*/
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}
ll A(ll n){
    ll ans=0;
    for(ll i=1;i<=n;i++) ans+=lcm(i,n)/n;
    return ans;
}

ll A2(ll n){

}
int main(){
    for(ll i=1;i<=100;i++){
        cout<<i<<" "<<A(i)<<"\n";
    }
}