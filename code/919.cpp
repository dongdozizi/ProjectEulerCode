#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<map>
#include<utility>
#include<map>
#include<unordered_map>
using namespace std;
typedef long long ll;
unordered_map<ll,ll> ump;
vector<pair<ll,ll> > fp[10000007];
vector<ll> fc[10000007];
ll N=10000000;
void get_fac(ll cur,ll n,vector<pair<ll,ll> > &prim,vector<ll> &fac){
    if(n==prim.size()){
        fac.push_back(cur);
        return;
    }
    for(ll i=0;i<=prim[n].second;i++){
        get_fac(cur,n+1,prim,fac);
        cur=cur*prim[n].first;
    }
}
int main(){
    map<pair<ll,ll>,ll> mc,mc2;
    ll cnt=0;
    
    for(ll i=2;i<=N;i++){
        if(fp[i].size()==0){
            for(ll j=i;j<=N;j+=i){
                ll cc=j,cp=0;
                while(cc%i==0){
                    cc/=i;
                    cp++;
                }
                fp[j].emplace_back(i,cp);
            }
        }
    }
    for(ll i=1;i<=N;i++){
        for(ll j=0;j<fp[i].size();j++){
            fp[i][j].second*=2;
        }
        bool find3=0,find5=0;
        for(ll j=0;j<fp[i].size();j++){
            if(fp[i][j].first==3){
                fp[i][j].second++;
                find3=1;
            }
            if(fp[i][j].first==5){
                fp[i][j].second++;
                find5=1;
            }
        }
        if(!find3) fp[i].emplace_back(3,1);
        if(!find5) fp[i].emplace_back(5,1);
    }
    for(ll i=1;i<=N;i++){
        if(i%100000==0) printf("%d\n",i);
        get_fac(1,0,fp[i],fc[i]);
        fp[i].clear();
    }
    printf("FINISH\n");
    cnt=0;
    for(ll i=1;i<=N;i++){
        if(i%100000==0) printf("%d\n",i);
        for(ll u:fc[i]){
            ll v=i*i*15ll/u;
            //printf("%d - %d %d %d\n",i,u,v,u*v);
            cnt++;
            if(u>v) swap(u,v);
            if((v-u)%2!=0) continue;
            if((v+u)%8!=0) continue;
            ll c=(v+u)/8;
            if(c>N) continue;
            mc[make_pair(i,c)]=(v-u)/2;
        }
    }
    ll sum=0;
    for(auto &x:mc){
        ll a=x.first.first,c=x.first.second;
        ll bb=x.second;
        //cout<<a<<" "<<c<<" "<<bb<<"\n";
        ll b;
        b=a+bb;
        if(b>0&&b%4==0){
            b=b/4;
            if(a+b+c<=N){
                sum+=a+b+c;
                //printf("%d %d %d\n",a,b,c);
            }
        }
        b=a-bb;
        if(b>0&&b%4==0){
            b=b/4;
            if(a+b+c<=N){
                sum+=a+b+c;
                //printf("%d %d %d\n",a,b,c);
            }
        }
        b=-a+bb;
        if(b>0&&b%4==0){
            b=b/4;
            if(a+b+c<=N){
                sum+=a+b+c;
                //printf("%d %d %d\n",a,b,c);
            }
        }
    }
    cout<<sum<<" "<<sum/2ll<<" "<<cnt<<"\n";
    //printf("%d\n",mc.size());
    // for(auto x:mc2){
    //     ll a=x.first,c=x.second;
    //     printf("%d %d %d\n",a,c,16*c*c-15*a*a);
    // }
    // cout<<" --------------------------\n";
    // for(auto x:mc){
    //     ll a=x.first,c=x.second;
    //     printf("%d %d %d\n",a,c,16*c*c-15*a*a);
    // }
    // ll cnt=0;
    // map<ll,ll> mp;
    // for(ll a=1;a<=10000;a++){
    //     int pt=0;
    //     for(ll b=a;a+b<=10000;b++){
    //         if(a%2!=0&&b%2!=0) continue;
    //         ll c=2ll*a*a+2ll*b*b-a*b;
    //         if(ump.count(c)){
    //             c=ump[c];
    //             if(a+b+c>10000) break;
    //             cnt+=a+b+c;
    //             pt++;
    //             mp[16*c*c-15*a*a]=1;
    //             //printf("%d %d %d %d %d\n",a,b,c);
    //         }
    //     }
    // }
    // printf("%d\n",mp.size());
    // for(auto &x:mp){
    //     printf("%d %d\n",x.first,x.second);
    // }
    // mp.clear();
    // for(ll a=1;a<=10000;a++){
    //     ll pt=0;
    //     for(ll b=a;b+a<=10000;b++){
    //         if(a%2!=0&&b%2!=0) continue;
    //         ll c=2ll*a*a+2ll*b*b+a*b;
    //         if(ump.count(c)){
    //             c=ump[c];
    //             if(a+b+c>10000) break;
    //             cnt+=a+b+c;
    //             pt++;mp[c*c-a*a]=1;
    //             //if(__gcd(a,b)==1)
    //             //printf("%d %d %d\n",a,b,c);
    //         }
    //     }
    //     //if(pt>2) printf(" ---------------------------------------- \n");
    // }printf("%d\n",mp.size());
    // printf("%d\n",cnt);
}
/*
100000 52162
2*a*a+2*b*b-a*b
a*a+2*b*b
2*(2*b+1)-b
-4*b+2
*/