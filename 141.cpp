#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<map>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef long double ld;
unordered_map<ll,ll> mp;
// bool ok(ll a,ll n){
//     ll aaabbb=(n*n/a-1)*a*a;
//     if(!mp.count(aaabbb)) return false;
//     ll ab=mp[aaabbb];
//     if((ab*ab)%a!=0) return false;
//     ll abb=ab*ab/a;
//     cout<<n*n<<" "<<abb*ab+a<<"\n";;
//     if(n*n!=abb*ab+a) cout<<"NOOOOOO\n";
// //    cout<<n*n<<" "<<n*n/(ab*ab/a)<<" "<<n*n
//     return true;
// }

// bool check(ll n){
//     vector<ll> vp;
//     for(ll j=1;j*j<=n;j++){
//         if(n%j!=0) continue;
//         vp.push_back(j);vp.push_back(n/j);
//     }
//     for(ll i=0;i<vp.size();i++){
//         for(ll j=i;j<vp.size();j++){
//             if(vp[i]*vp[j]>=n) continue;
//             if(ok(vp[i]*vp[j],n)){
//                 cout<<" --- "<<vp[i]*vp[j]<<" "<<n<<"\n";
//                 return true;
//             }
//         }
//     }
//     return false;
// }

bool check(ll n){
    n=n*n;
    for(ll i=1;i*i*i<=n;i++){
        ll a=i;
        ll aabbb=n-a;
        ll aaabbb=aabbb*a;
        if(!mp.count(aaabbb)) continue;
        ll ab=mp[aaabbb];
        if(aabbb%ab==0) return true;
    }
    return false;
}

bool badcheck(ll n){
    n=n*n;
    ll a[3];
    for(ll i=1;i*i<=n;i++){
        a[0]=i;
        a[1]=n/i;
        a[2]=n-i*a[1];
        sort(a,a+3);
        if(a[1]*a[1]==a[0]*a[2]){
            cout<<sqrt(n)<<" "<<i<<"\n";
            return true;
        }
    }
    return false;
}

int main(){
    ll n2=1000000000000;
    ll ans=0;
    for(ll i=1;i<=2000000;i++) mp[i*i*i]=i;
    for(ll i=1;i*i<=n2;i++){
        if(badcheck(i)){
            cout<<i<<" "<<i*i<<" ";
            ans+=i*i;
            cout<<ans<<"\n";
        }
    }
    cout<<ans<<"\n";
}
/*
//n/bba=a...ba | n=bbaa+ba=n*(n+1)
n/bba=ba...a | n=bbbaa+a=a+(ab^3)/a
n/a-1=bbb*a
 --- 1 3
3 9
 --- 36 102
102 10404
 --- 25 130
 675
 2 5 
130 16900
 --- 40 208
208 43264
 --- 45 234
234 54756
 --- 8 312
312 97344

759 
3 11 23
81
360
1600
160/36=40/9

aaabbb=ab^3
*/