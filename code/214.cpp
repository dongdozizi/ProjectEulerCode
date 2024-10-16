#include<iostream>
#include<vector>
#include<math.h>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;

const ll n=40000000;

int phi_euler[n+6], primes[n+6];	// 欧拉筛打phi函数值的表，已知质数表
int len[n+6];
bool isp[n+6]={0};
void phi_by_euler_seive(){
	// 初始化为phi[i] = 0，作为该数是否质数的标志
	memset(phi_euler, 0, (n + 1) * sizeof(int));
	phi_euler[1] = 1;	// 特判：phi[1] = 1

	int p = 0;		// 已知质数的个数
	for (int i = 2; i <= n; i++) {
		if (phi_euler[i] == 0) {		// 说明i是一个质数
			primes[p++] = i;		// 收录进已知质数表
            isp[i]=1;
			phi_euler[i] = i - 1;		// phi函数计算性质1
		}
		for (int j = 0; j < p && i * primes[j] <= n; j++) {
			if (i % primes[j] == 0) {	// i是primes[j]的倍数
				// phi函数计算性质4
				phi_euler[i * primes[j]] =
					phi_euler[i] * primes[j];
				break;
			} else {			// i和primes[j]互质
				// phi函数计算性质3
				phi_euler[i * primes[j]] =
					phi_euler[i] * phi_euler[primes[j]];
			}
		}
	}

	return;
}
int main(){
    phi_by_euler_seive();
    len[1]=1;
    ll ans=0;
    for(ll i=2;i<=n;i++){
        len[i]=len[phi_euler[i]]+1;
        if(len[i]==25&&isp[i]){
            //cout<<i<<"\n";
            ans+=i;
        }
    }
    cout<<ans<<"\n";
}