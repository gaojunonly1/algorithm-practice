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
const int N1=2005;
const ll Mod=1000000007;
int n,h;
int a[N1];
ll dp[N1][N1];
int main() {
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	scanf("%d%d",&n,&h);
	for(i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		a[i]=h-a[i];
	}
	dp[0][0]=1;
	for(i=1;i<=n;i++) {
		for(j=0;j<=i-1;j++) {
			if(a[i]==j) {
				if(j>=1) {
					dp[i][j-1]=(dp[i][j-1]+dp[i-1][j]*j%Mod)%Mod;  //  ]
				}
				dp[i][j]=(dp[i][j]+dp[i-1][j])%Mod;        //none
			}
			if(a[i]==j+1) {
				dp[i][j+1]=(dp[i][j+1]+dp[i-1][j])%Mod;  //  [
				if(j>=1) {
					dp[i][j]=(dp[i][j]+dp[i-1][j]*j%Mod)%Mod;      //  ][
				}
				dp[i][j]=(dp[i][j]+dp[i-1][j])%Mod;      //  []
			}
		}
	}
	printf("%lld\n",dp[n][0]);
    return 0;
}
