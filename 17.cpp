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
string p1[10]={"one","two","three","four","five","six","seven","eight","nine"};
string p2[10]={"ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninty"};
string p11[10]={"ten","eleven","twelve",""}; s
ll pt[10]={0};
ll pp[10]={4,3,3,5,4,4,3,5,5,4};
int main(){
    string ans="0";
    for(ll i=0;i<1000;i++){
        add(ans,"1");
        cout<<ans<<"\n";
        for(ll j=0;j<ans.size();j++){
            pt[ans[j]-'0']++;
        }
    }
    ll sm=0;
    for(ll i=0;i<10;i++){
        cout<<pt[i]<<" "<<pp[i]<<"\n";
        sm+=pt[i]*pp[i];
    }
    cout<<sm<<"\n";
}
/*
11571
*/