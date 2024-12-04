#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
#include<map>
#include<numeric>
#include<set>
#include<utility>
#include<algorithm>
#include<unordered_set>
using namespace std;
typedef long long ll;
ll f1[1000],f2[1000];
ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
int main(){
    f1[1]=1,f2[1]=-1;
    for(int i=2;i<=100;i++){
        f1[i]=(f1[i-1]-1)*(f1[i-1]-1)*(f1[i-1]-1)+2;
        f2[i]=(f2[i-1]+1)*(f2[i-1]+1)*(f2[i-1]+1);
        cout<<f1[i]<<" "<<f2[i]<<"\n";
    }
    for(int i=1;i<=7;i++){
        for(int j=1;j<=7;j++){
            if(gcd(f1[i],f1[j])!=1)
            cout<<i<<" "<<j<<" "<<gcd(f1[i],f1[j])<<"\n";
        }
    }
}
/*
*/