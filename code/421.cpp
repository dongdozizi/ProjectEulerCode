#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef __int128 lll;

//const ll N=10,M=1000;
const ll M=100000000ll,N=100000000000ll;
static const ll MAXP = sqrt(M)+1;
static vector<ll> smallPrimes;

vector<bool> isPrime(M+1, true);

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

void buildSmallPrimes() {
    isPrime[0] = false; 
    isPrime[1] = false;
    for(ll i = 2; i <= M; i++){
        if(isPrime[i]){
            for(ll j = i*i; j <= M; j+=i){
                isPrime[j] = false;
            }
        }
    }
    for(ll i=2; i<=MAXP; i++){
        if(isPrime[i]) smallPrimes.push_back(i);
    }
    cout<<isPrime.size()<<" "<<smallPrimes.size()<<"\n";
}

ll modPow(ll a,ll b,ll m){
    if(b==0) return 1;
    ll c=modPow(a,b/2,m);
    if(b%2==0) return c*c%m;
    else return c*c%m*a%m;
}

vector<ll> factorDistinct(ll n){
    vector<ll> factors;
    for(ll prime : smallPrimes){
        if(prime * prime > n) break;
        if(n % prime == 0){
            factors.push_back(prime);
            while(n % prime == 0) n /= prime;
        }
    }
    if(n > 1){
        factors.push_back(n);
    }
    return factors;
}

ll findPrimitiveRoot(ll p){
    ll phi = p - 1;
    vector<ll> pf = factorDistinct(phi);

    for(ll g = 2; g < p; g++){
        bool ok = true;
        for(ll f : pf){
            ll pw = (phi / f);
            if(modPow(g, pw, p) == 1){
                ok = false;
                break;
            }
        }
        if(ok) return g; 
    }
    return -1;
}
vector<ll> solveAllN_forPrime(ll p){
    ll phi = p - 1;
    ll g = findPrimitiveRoot(p);

    ll d = gcd((ll)15, phi);
    ll step = phi / d;

    vector<ll> solutions;
    solutions.reserve(d);
    for(ll k = 0; k < d; k++){
        ll exponent = k * step;
        ll n = modPow(g, exponent, p);
        solutions.push_back(n);
    }

    sort(solutions.begin(), solutions.end());
    solutions.erase(unique(solutions.begin(), solutions.end()), solutions.end());

    return solutions;
}

string int128ToString(__int128 x) {
    if (x == 0) return "0";
    string res;
    bool neg = x < 0;
    if (neg) x = -x;
    while (x > 0) {
        res += '0' + (x % 10);
        x /= 10;
    }
    if (neg) res += '-';
    reverse(res.begin(), res.end());
    return res;
}

lll calc(lll a,lll b,lll c){
    a = (a % b + b) % b; // 确保 0 <= a < b
    if (c < a) return 0;
    lll n = (c - a) / b + 1;
    return n * b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    buildSmallPrimes();
    
    cout<<"buildOver\n";

    lll ans=0;
    for(ll i=1;i<=M;i++){
        if(isPrime[i]){
            vector<long long> all = solveAllN_forPrime(i);
            for(ll &x : all){
                ans+=calc(i-x,i,N);
                //cout<<i<<" "<<x<<" | ";
            }
            //cout<<"\n";
        }
            if(i%(M/100+1)==0){
                cout<<i<<" "<<int128ToString(ans)<<"\n";
            }
    }
    cout<<int128ToString(ans)<<"\n";
    // int T;
    // cout << "请输入查询次数 T: ";
    // cin >> T;
    // while(T--){
    //     long long p;
    //     cout << "请输入一个素数 p (<=1e8): ";
    //     cin >> p;

    //     vector<long long> ans = solveAllN_forPrime(p);
        
    //     // 3) 输出
    //     cout << "满足 n^15 ≡ 1 (mod " << p << ") 的所有 n 共 " 
    //          << ans.size() << " 个:\n";
    //     for(auto &x : ans){
    //         cout << p-x << " ";
    //     }
    //     cout << "\n\n";
    // }

    return 0;
}
