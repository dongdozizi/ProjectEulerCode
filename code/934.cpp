#include<iostream>
#include<vector>
#include<math.h>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;

ll N=100000000000000000ll;
vector<ll> prim;
void dfs(ll n,ll pr,ll q){
    for(ll i=0;i<prim[n];i++){
        if(i%7==0){
            dfs(n+1,pr,q);
        }
    }
}
int main(){
    for(ll i=0;i<n;i++){

    }
    dfs(0);
}