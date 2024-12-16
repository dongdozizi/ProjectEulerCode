#include<iostream>
#include<vector>
#include<math.h>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef vector<vector<ll> > Matrix;
ll mod=398874989;
ll mod2=199437494;
ll mod3=99718746;
ll qpow(ll a,ll b,ll mod){
    if(b==0) return 1;
    ll c=qpow(a,b/2,mod);
    if(b%2==0) return c*c%mod;
    else return c*c%mod*a%mod;
}
Matrix multiply(const Matrix& a, const Matrix& b,ll mod) {
    Matrix result(2, vector<long long>(2, 0));
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                result[i][j] += a[i][k] * b[k][j];
                result[i][j] %= mod;
            }
        }
    }
    return result;
}

Matrix qpow(Matrix base,ll exp,ll mod) {
    Matrix result = {{1, 0}, {0, 1}};
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = multiply(result,base,mod); 
        }
        base = multiply(base,base,mod);
        exp /= 2;
    }
    return result;
}

ll getN(ll n,ll x,ll y,ll a1,ll a0,ll mod){
    Matrix mat={{x,y},{1,0}};
    mat=qpow(mat,n,mod);
    return (mat[1][0]*a1+mat[1][1]*a0)%mod;
}

int main(){
    ll sum=0;
    for(ll i=2;i<=1618034;i++){
        if(i%100000==0){
            cout<<i<<endl;
        }
        ll pn=getN(qpow(5,getN(i,1,1,1,0,mod3),mod2),4,1,1,0,mod),qn=getN(qpow(5,getN(i,1,1,1,0,mod3),mod2),4,1,2,1,mod);
        sum=sum+qpow(pn,5,mod)+qpow(qn,5,mod);
        sum%=mod;
    }
    printf("%lld\n",sum);
}
/*
32136171
a[n]=4*a[n-1]+a[n-2] a[0]=0,a[1]=1
b[n]=4*b[n-1]+b[n-2] b[0]=1,b[1]=2
p[n]=a[5^n] getN(qpow(5,n-1,mod2),4,1,1,0,mod) 199437494
q[n]=b[5^n] getN(qpow(5,n-1,mod2),4,1,2,1,mod) 199437494
fib[n]=     getN(i,1,1,1,0,mod)
*/