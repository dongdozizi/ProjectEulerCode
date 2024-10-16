#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;

vector<ll> yinzi[20000007];
set<ll> inver[20000007];

/*
ax+by=gcd(a,b)
*/
ll euclid(ll a, ll b, ll &x, ll &y) {
    if (!b) return x = 1, y = 0, a;
    ll d = euclid(b, a % b, y, x);
    return y -= a/b * x, d;
}

ll getinv(ll q1,ll q2,ll p1,ll p2){
    ll x,y;
    euclid(q1,q2,x,y);
    x=((p2-p1)*x%q2+q2)%q2;
    
    // cout<<"\n"<<q1<<" "<<q2<<" "<<p1<<" "<<p2<<" "<<x<<" "<<y<<"\n"; 
    // cout<<q1*x+p1<<"\n";
    // cout<<q1*x%(q1*q2)*p2%(q1*q2)<<"\n";
    // cout<<"FINAL "<<((p1*x+q1)%(q1*q2)+q1*q2)%(q1*q2)<<"\n";
    //cout<<((q2-q1)*x%(q1*q2)*p2%(q1*q2)+q1*q2)%(q1*q2)<<"\n";
    return ((q1*x+p1)%(q1*q2)+q1*q2)%(q1*q2);
// q1*i+p1=q2*j+p2 (mod q1*q2)
// q1*x=1 (mod q2)
// q1*x=1 (mod q2)
// q1*x*p2=p2 (mod q2)
}

ll gcd(ll a,ll b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
ll N=20000000;
/*
61128033
*/
void init(){
    ll sum=0;
    for(ll i=2;i<=N;i++){
        if(yinzi[i].size()==0){
            for(ll j=i;j<=N;j+=i){
                ll pq=1,j1=j;
                while(j1%i==0){
                    j1/=i;
                    pq*=i;
                }
                yinzi[j].push_back(pq);
            }
        }
        sort(yinzi[i].begin(),yinzi[i].end());
        sum+=yinzi[i].size();
    }
    cout<<sum<<"\n";
}
int main(){
    init();
    ll ans=0;
    for(ll i=2;i<=N;i++){
        if(yinzi[i].size()==1){
            inver[i].insert(1);
            if(i%8==0){
                inver[i].insert(i/2-1);
                inver[i].insert(i/2+1);
            }
            inver[i].insert(i-1);
        }
        else{
            ll q1=yinzi[i][0],q2=i/q1;
            //cout<<q1<<" "<<q2<<"\n";
            for(auto p1:inver[q1]){
                for(auto p2:inver[q2]){
                    //cout<<q1<<" "<<q2<<" "<<inver[q1][j1]<<" "<<inver[q2][j2]<<" - ";
                    //cout<<getinv(q1,q2,inver[q1][j1],inver[q2][j2])<<"\n";
                    inver[i].insert(getinv(q1,q2,p1,p2));
                }
            }        
        }
    }
    //cout<<inver[100][inver[100].size()-2]<<"\n";
    for(ll i=3;i<=N;i++){
        auto ed=inver[i].end();
        ed--;ed--;
        ans+=*ed;
        //cout<<i<<" "<<*ed<<"\n";
    }
    cout<<ans<<"\n";
    // for(ll i=1;i<=100;i++){
    //     cout<<i<<" - ";
    //     for(ll j=0;j<yinzi[i].size();j++) cout<<yinzi[i][j]<<" ";
    //     cout<<"\n";
    // }
    // ll ans=0;
    // for(ll i=3;i<=10000;i++){
    //     ll tmp=0;
    //     for(ll j=1;j<=i-1;j++){
    //         if(gcd(i,j)==1&&(j*j%i==1)){
    //             //cout<<j<<" ";
    //             tmp++;
    //         }
    //     }
    //     ans=max(tmp,ans);
    //     //cout<<"\n";
    // }
    // cout<<ans<<"\n";
}
/*
153651073760956
153651073760956
p1%q1
p2%q2
q1*q2?
1/q1=mod q2
q1*i=p2-p1 mod q2
q1*i+p1=q2*j+p2 (mod q2)
q1*i+p1%q1*q2
3 - 1 2 
4 - 1 3 
5 - 1 4 
6 - 1 5 
7 - 1 6 
8 - 1 3 5 7 
9 - 1 8 
10 - 1 9 
11 - 1 10 
12 - 1 5 7 11 
13 - 1 12 
14 - 1 13 
15 - 1 4 11 14 
16 - 1 7 9 15 
17 - 1 16 
18 - 1 17 
19 - 1 18 
20 - 1 9 11 19 
21 - 1 8 13 20 
22 - 1 21 
23 - 1 22 
24 - 1 5 7 11 13 17 19 23 
25 - 1 24 
26 - 1 25 
27 - 1 26 
28 - 1 13 15 27 
29 - 1 28 
30 - 1 11 19 29 
31 - 1 30 
32 - 1 15 17 31 
33 - 1 10 23 32 
34 - 1 33 
35 - 1 6 29 34 
36 - 1 17 19 35 
37 - 1 36 
38 - 1 37 
39 - 1 14 25 38 
40 - 1 9 11 19 21 29 31 39 
41 - 1 40 
42 - 1 13 29 41 
43 - 1 42 
44 - 1 21 23 43 
45 - 1 19 26 44 
46 - 1 45 
47 - 1 46 
48 - 1 7 17 23 25 31 41 47 
49 - 1 48 
50 - 1 49 
51 - 1 16 35 50 
52 - 1 25 27 51 
53 - 1 52 
54 - 1 53 
55 - 1 21 34 54 
56 - 1 13 15 27 29 41 43 55 
57 - 1 20 37 56 
58 - 1 57 
59 - 1 58 
60 - 1 11 19 29 31 41 49 59 
61 - 1 60 
62 - 1 61 
63 - 1 8 55 62 
64 - 1 31 33 63 
65 - 1 14 51 64 
66 - 1 23 43 65 
67 - 1 66 
68 - 1 33 35 67 
69 - 1 22 47 68 
70 - 1 29 41 69 
71 - 1 70 
72 - 1 17 19 35 37 53 55 71 
73 - 1 72 
74 - 1 73 
75 - 1 26 49 74 
76 - 1 37 39 75 
77 - 1 34 43 76 
78 - 1 25 53 77 
79 - 1 78 
80 - 1 9 31 39 41 49 71 79 
81 - 1 80 
82 - 1 81 
83 - 1 82 
84 - 1 13 29 41 43 55 71 83 
85 - 1 16 69 84 
86 - 1 85 
87 - 1 28 59 86 
88 - 1 21 23 43 45 65 67 87 
89 - 1 88 
90 - 1 19 71 89 
91 - 1 27 64 90 
92 - 1 45 47 91 
93 - 1 32 61 92 
94 - 1 93 
95 - 1 39 56 94 
96 - 1 17 31 47 49 65 79 95 
97 - 1 96 
98 - 1 97 
99 - 1 10 89 98 
100 - 1 49 51 99 
*/