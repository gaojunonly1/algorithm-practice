#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
#define iinf INT_MAX
int main() {
	int i,j,k,L;
	int o,p,q;
	ll oo,pp,qq;
	
	int n,h;
	ll dp[40][40][40];
	ll C[85][85];
	scanf("%d%d",&n,&h);
	C[0][0]=1;
	for(i=1;i<=n*2;i++) {
		C[i][0]=1;
		for(j=1;j<=i;j++) {
			C[i][j]=C[i-1][j]+C[i-1][j-1];
		}
	}
	memset(dp,0,sizeof dp);
	dp[1][1][1]=1;
	for(i=1;i<n;i++) {
		for(j=i;j<=n;j++) {
			for(k=1;k+(i-1)<=j&&k<=(1ll<<(i-1));k++) {
				for(L=1;j+L<=n&&L<=k*2&&L<=(1ll<<i);L++) {
					dp[i+1][j+L][L]+=dp[i][j][k]*C[2*k][L];
				}
			}
		}
	}
	ll wwx=0;
	for(i=h;i<=n;i++) {
		for(j=1;j<=n;j++) {
			wwx+=dp[i][n][j];
		}
	}
	printf("%lld\n",wwx);
    return 0;
}
