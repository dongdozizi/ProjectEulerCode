#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

void add(string &a,string b){
    reverse(b.begin(),b.end());
    reverse(a.begin(),a.end());
    if(a.size()<b.size()){
        ll c=0;
        while(b.size()>a.size()) a+='0';
    }
    for(ll i=0;i<a.size();i++) a[i]-='0';
    for(ll i=0;i<b.size();i++){
        a[i]+=b[i]-'0';
    }
    for(ll i=0;i<a.size();i++){
        if(a[i]>=10){
            a[i]-=10;
            if(i==a.size()-1) a+=1;
            else a[i+1]++;
        }
        a[i]+='0';
    }
    reverse(a.begin(),a.end());
}
int main(){
    string ans="1";
    ll n=0;cin>>n;
    for(ll i=2;i<=n;i++){
        string tmp=ans;
        for(ll j=0;j<i-1;j++){
            add(ans,tmp);
        }
        cout<<ans<<"\n";
    }
    ll cur=0;
    for(ll i=0;i<ans.size();i++){
        cur+=ans[i]-'0';
    }
    cout<<cur<<"\n";
}
/*
648
*/