#include<iostream>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    cin>>n;
    ll p1=0,p2=0;
    for(ll i=1;i<=n;i++){
        p1+=i*i,p2+=i;
    }
    cout<<p2*p2-p1;
}
/*
25164150
*/