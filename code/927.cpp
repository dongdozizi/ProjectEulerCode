#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll inf=1e18;
ll n1=20,n2=10000000;
vector<ll> prim;
vector<bool> is_prime(10000007,false);
vector<bool> notin(10000007,false);
ll qpow(ll a,ll b,ll mod){
    if(b==0) return 1;
    ll tmp=qpow(a,b/2,mod);
    if(b%2==0) return tmp*tmp%mod;
    else return tmp*tmp%mod*a%mod;
}
int main(){
    for(ll i=2;i<=n1;i++){
        if(is_prime[i]==false){
            prim.push_back(i);
            for(ll j=i*i;j<=n1;j+=i){
                is_prime[j]=true;
            }
        }
    }
    cout<<prim.size()<<"\n";
    ll ans=3,cnt=0;
    for(ll i=3;i<=n2;i++){
        if(notin[i]) continue;
        bool allok=1;
        for(ll j=0;j<prim.size();j++){
            ll st=2%i;
            bool ok=0;
            for(ll k=0;k<=i;k++){
                st=(qpow(st,prim[j],i)+1)%i;
                if(st==0){
                    ok=1;
                    break;
                }
            }
            if(!ok){
                st=3%i;
                for(ll k=0;k<=i;k++){
                    st=(qpow(st,prim[j],i)+1)%i;
                    if(st==0){
                        ok=1;
                        break;
                    }
                }
            }
            if(!ok){
                allok=0;
                break;
            }
        }
        if(allok){
            ans+=i;cnt++;
            cout<<cnt<<" "<<i<<"\n";
        }
        else{
            for(ll j=i;j<=n2;j+=i){
                notin[j]=1;
            }
        }
    }
    cout<<cnt<<" "<<ans<<"\n";
}