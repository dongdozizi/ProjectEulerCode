#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
int main(){
    for(ll i=1;i<=1000-i*2;i++){
        for(ll j=i+1;j<=1000-i-j;j++){
            ll k=1000-i-j;
            if(i*i+j*j==k*k){
                cout<<i<<" "<<j<<" "<<k<<" "<<i*j*k<<"\n";
            }
        }
    }
}
/*
3187500
*/