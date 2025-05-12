#include<iostream>
#include<vector>
#include<math.h>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;

ll mod=1123581313;
ll f[51];
ll A[12][12];
void matMul(ll A[2][2],ll B[2][2],ll C[2][2]){
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            C[i][j]=0;
            for(int k=0;k<2;k++){
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%mod;
            }
        }
    }
}

ll getMN(ll m,ll n){
    ll A[2][2]={-1,1,1,2};
    ll B[2][2]={1,0,0,1};
    ll C[2][2];
    ll D[2][2];
    ll E[2][2];
    ll n1=n;
    while(n1>0){
        if(n1%2==1){
            matMul(B,A,C);
            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    B[i][j]=C[i][j];
                }
            }
        }
        matMul(A,A,C);
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                A[i][j]=C[i][j];
            }
        }
        n1/=2;
    }
    ll b0=B[0][1];
    ll b1=B[1][1];
    cout<<b0<<" "<<b1<<'\n';
    A[0][0]=0,A[0][1]=1;
    A[1][0]=1,A[1][1]=3;
    B[0][0]=1,B[0][1]=0;
    B[1][0]=0,B[1][1]=1;
    n1=m;
    while(n1>0){
        if(n1%2==1){
            matMul(B,A,C);
            for(int i=0;i<2;i++){
                for(int j=0;j<2;j++){
                    B[i][j]=C[i][j];
                }
            }
        }
        matMul(A,A,C);
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                A[i][j]=C[i][j];
            }
        }
        n1/=2;
    }
    return (B[0][0]*b0+B[0][1]*b1)%mod;
}
int main(){
    getMN(3,0);
    getMN(3,1);
    getMN(3,2);
    getMN(3,3);
    f[0]=0;
    f[1]=1;
    for(int i=2;i<=50;i++){
        f[i]=f[i-1]+f[i-2];
    }
    ll ans=0;
    for(int i=2;i<=50;i++){
        for(int j=2;j<=50;j++){
            ans=(ans+getMN(f[i],f[j]))%mod;
        }
    }
    cout<<ans<<"\n";
    for(int i=0;i<=10;i++){
        for(int j=0;j<=10;j++){
            A[i][j]=-1;
        }
    }
    A[0][0]=0,A[0][1]=1;
    for(int i=0;i<=10;i++){
        for(int j=0;j<=10;j++){
            if(A[i][j]!=-1&&A[i][j+1]!=-1){
                A[i+1][j]=A[i][j+1]+A[i][j];
            }
            if(A[i][j]!=-1&&A[i+1][j]!=-1){
                A[i+1][j+1]=2*A[i+1][j]+A[i][j];
            }
            if(A[i+1][j]!=-1&&A[i][j]!=-1){
                A[i][j+1]=A[i+1][j]-A[i][j];
            }
        }
    }

    for(int i=0;i<=10;i++){
        for(int j=0;j<=10;j++){
            printf("%d\t",A[i][j]);
        }
        printf("\n");
    }

    ans=0;
    for(int i=2;i<=5;i++){
        for(int j=2;j<=5;j++){
            ans+=A[f[i]][f[j]];
        }
    }cout<<ans<<"\n";
}
/*
A[0][0]=0,A[0][1]=1;
A[m+1][n]=A[m][n+1]+A[m][n];
    =3A[m][n]+A[m-1][n];
A[m+1][n+1]=2A[m+1][n]+A[m][n];
A[m][n+1]=2A[m][n]+A[m-1][n];
A[m][n]=2A[m][n-1]+A[m-1][n-1];
    =3A[m-1][n]+A[m-2][n];
A[m][n+1]=A[m+1][n]-A[m][n];

A[m][n]=3A[m-1][n]+A[m-2][n];
A[m][n+1]=2A[m][n]+A[m-1][n];

A[1][n+1]=2A[1][n]+A[0][n];
A[0][n+1]=A[1][n]-A[0][n];

*/