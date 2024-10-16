#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
bool prm[2000006]={0};
vector<ll> pr;
int main(){
    ll n;cin>>n;ll sum=0;
    for(ll i=2;i<=n;i++){
        if(prm[i]==0){
            sum+=i;
            for(ll j=i*i;j<=n;j+=i){
                prm[j]=1;
            }
        }
    }
    cout<<sum<<"\n";
}
/*
142913828922
*/