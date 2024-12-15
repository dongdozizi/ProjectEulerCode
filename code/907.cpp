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
bool check(int p1,int t1,int p2,int t2){
    if(abs(p1-p2)==1&&t1==t2&&(p1==p2-1&&t1==0||p1-1==p2&&t1==1)||abs(p1-p2)==2&&t1!=t2){
        return true;
    }
    return false;
}
int n=6;
ll mod=1e9+7;
ll dp[10000007]={0};
ll b[10000007]={0};
int main(){
    dp[0]=0;
    dp[1]=dp[2]=dp[3]=1;
    for(ll i=4;i<=10000003;i++){
        dp[i]=dp[i-1]+dp[i-3];
    }
    // ll ans=;
    // for(ll i=1,2){

    // }
    // for(int i=1;i<=100;i++){
    //     printf("%lld %lld\n",i,dp[i]);
    // }
    vector<int> ps(n),nm(n);
    for(int i=0;i<n;i++){
        ps[i]=i;
    }
    int cnt=0;
    do{
        // printf(" ---   ");
        // for(int i=0;i<n;i++){
        //     printf("%d ",ps[i]);
        // }printf("\n");
        for(int i=0;i<(1<<n);i++){
            for(int j=0;j<n;j++){
                if((1<<j)&i) nm[j]=1;
                else nm[j]=0;
            }
            bool tr=true;
            for(int j=0;j+1<n;j++){
                //printf("%d ",nm[j]);
                if(!check(ps[j],nm[j],ps[j+1],nm[j+1])){
                    tr=false;break;
                }
            }
            if(tr){
                for(int j=0;j<n;j++){
                    printf("%d %d | ",ps[j],nm[j]);
                }
                printf("\n");
            }
            //printf("\n");
            if(tr) cnt++;
        }
    }while(next_permutation(ps.begin(),ps.end()));
    cout<<cnt;
}
/*
k -1 -> k-1 -1
k-1 1-> k 1
k 1 -> k-2 -1
k-2 1 -> k -1
k -1 -> k-2 1
k-2 -1 -> k 1
[2][2][2][2][2][2]
k-2,k-1,k,k+1,k+2

k-2,k,k-1,k+1
k,k-2,k-1,k+1 x
k-1,k
k,k-1,k+1

n-1,n,n-2
n,n-1
n-2 1,n -1,n-1 -1,n-3 1
n-3 -1,n-1 1,n 1,n-2,-1,n-4 1

n -1 ,n-2 1,n-1 1,n-3 -1
n -1,n-1 -1

n-1 1,n 1,n-2 -1
n-2 1,n -1,n-1 -1,n-3 1 x
n-3 -1,n-1 1,n 1,n-2 -1,n-4 1 x

n
n-1
n-2

n-5 
n-6

n-7
n-8
1 1
2 1
3 1
4 2
5 3
6 4
7 6
8 9
9 13
10 19

1:
1 3 2 0
1:a[n-2]
2 3 1 0

1 - 3 1 0 2

a[n-2]
3 2 0 1
a[n]
3 1 2 0
3 2 1 0
*/