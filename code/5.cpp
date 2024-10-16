#include<iostream>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}
int main(){
    ll n;
    cin>>n;
    ll c=1;
    for(ll i=1;i<=n;i++){
        c=lcm(c,i);
    }
    cout<<c<<"\n";
}
/*
232792560
*/