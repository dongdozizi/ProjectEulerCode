#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n=(1ll<<50)-1;
bool fd[100000008]={0};
// ll f(ll x){

// }
int main(){
    ll cnt=0,m=sqrt(n);
    for(ll i=2;i<=m;i++){
        if(!fd[i]){
            for(ll j=i*i;j<=m;j+=i) fd[j]=1;
        }
    }
    for(ll i=80;i<=sqrt(n);i++){
        if(!fd[i])
        cnt+=n/(i*i);
    }
    cout<<cnt<<"\n";
}