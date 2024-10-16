#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
bool prm[1000006]={0};
vector<ll> pr;
int main(){
    for(ll i=2;i<=1000000;i++){
        if(prm[i]==0){
            pr.push_back(i);
            for(ll j=i*i;j<=1000000;j+=i){
                prm[j]=1;
            }
        }
    }
    ll n;
    cin>>n;
    cout<<pr[n-1];
}
/*
104743
*/