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
int n,a[1005];
ll dp[1005][20005];
int main() {
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dp[0][10000]=0;
	ll wwx=0;
	for(i=1;i<=n;i++) {
		dp[i][10000+a[i]]++;
		dp[i][10000-a[i]]++;
		for(j=0;j<=20000;j++) {
			if(j+a[i]<=20000) {
				(dp[i][j+a[i]]+=dp[i-1][j])%=Mod;
			}
			if(j-a[i]>=0) {
				(dp[i][j-a[i]]+=dp[i-1][j])%=Mod;
			}
		}
		(wwx+=dp[i][10000])%=Mod;
	}
	printf("%lld\n",wwx);
    return 0;
}
