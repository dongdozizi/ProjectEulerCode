#include<iostream>
#include<vector>
#include<math.h>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;

vector<vector<double> > vd;

int main(){
    ll n=12345;
    vd.resize(n+1,vector<double>(n+1));
    for(ll i=0;i<n;i++){
        vd[i][0]=0;
        vd[0][i]=1;
    }
    for(ll i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            vd[i][j]=(2.0*j*vd[i][j-1]+(2.0*i-1.0)*vd[i-1][j])/(2.0*j+2.0*i-1.0);
        }
    }
    printf("%f %f %f %.20f\n",vd[1][2],vd[5][9],vd[17][25],vd[12345][12345]);
}