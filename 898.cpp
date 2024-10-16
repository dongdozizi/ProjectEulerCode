#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;
double p[25]={0.6,0.8};
ll n=2;
void init(){
    n=25;
    for(ll i=0;i<n;i++){
        p[i]=0.51+0.01*i;
    }
}
const ll N=1<<25;
struct node{
    double l1,l2,bi;
}calc[N+1];
double bi[N+1];
double pl[N+1];
double pr[N+1];
bool cmp(node &a1,node &a2){
    return a1.bi<a2.bi;
}
int main(){
    cout<<"tmp\n";
    init();
    cout<<"Initover\n";
    for(ll i=0;i<(1<<n);i++){
        calc[i].l1=calc[i].l2=1.0;
        for(ll j=0;j<n;j++){
            if((1<<j)&i){
                calc[i].l1*=p[j];
                calc[i].l2*=(1-p[j]);
            }
            else{
                calc[i].l1*=(1-p[j]);
                calc[i].l2*=p[j];
            }
        }
        calc[i].bi=calc[i].l1/calc[i].l2;
    }
    cout<<"tmp\n";
    sort(calc,calc+(1<<n),cmp);
    pl[0]=calc[0].l1;
    pr[0]=calc[0].l2;
    bi[0]=calc[0].bi;
    for(ll i=1;i<(1<<n);i++){
        pl[i]=pl[i-1]+calc[i].l1;
        pr[i]=pr[i-1]+calc[i].l2;
        bi[i]=calc[i].bi;
    }
    double ans=0;
    for(ll i=0;i<(1<<n);i++){
        double gai1=1.0,gai2=1.0;
        for(ll j=0;j<n;j++){
            if((1<<j)&i){
                gai1*=p[j];
                gai2*=(1-p[j]);
            }
            else{
                gai1*=(1-p[j]);
                gai2*=p[j];
            }
        }
        ll wei=lower_bound(bi,bi+(1<<n),gai2/gai1)-bi;
        //cout<<i<<" "<<wei<<"\n";
        ans=ans+gai1*(pl[(1<<n)-1]-(wei==0?0.0:pl[wei-1]))+gai2*(wei==0?0.0:pr[wei-1]);
    }
    cout<<ans<<"\n";
    cout<<setprecision(15)<<ans/2.0<<"\n";
}