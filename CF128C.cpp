#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
const ll Mod=1000000007;
int n,m,k;
ll dp[1005][1005],s[1005][1005];
int main() {
	int i,j;
	ll oo,pp,qq;
	scanf("%d%d%d",&n,&m,&k);
	if(n<m)
		swap(n,m);
	for(i=1;i<=n;i++) {
		dp[1][i]=1;
	}
	for(i=2;i<=k+1;i++) {
		for(j=1;j<=n;j++) {
			s[i-1][j]=(s[i-1][j-1]+dp[i-1][j])%Mod;
			dp[i][j]=(dp[i][j-1]+((j>=2)?s[i-1][j-2]:0))%Mod;
		}
	}
	printf("%lld\n",dp[k+1][n]*dp[k+1][m]%Mod);
    return 0;
}
