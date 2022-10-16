#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
const int N1=505;
int n,m;
ll mod;
int cnt[N1];
char s[N1];
ll dp[N1][N1];
int main() {
	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	scanf("%d%d%lld",&n,&m,&mod);
	for(i=1;i<=m;i++) {
		scanf("%s",s+1);
		for(j=1;j<=n;j++) {
			if(s[j]=='1') {
				cnt[j]++;
			}
		}
	}
	o=p=0;
	for(j=1;j<=n;j++) {
		if(cnt[j]==1) {
			o++;
		}
		else if(cnt[j]==2) {
			p++;
		}
	}
	memset(dp,0,sizeof dp);
	dp[o][p]=1;
	for(i=m+1;i<=n;i++) {
		for(k=i;k>=0;k--) {
			j=i*2-k*2;
			if(j>n)
				continue;
			if(k>=2)
				(dp[j][k]+=dp[j+2][k-2]*((j+2)*(j+1)/2)%mod)%=mod;
			if(k>=1&&j>=1)
				(dp[j][k]+=dp[j][k-1]*((n-j-k+1)*j)%mod)%=mod;
			if(j>=2)
				(dp[j][k]+=dp[j-2][k]*((n-j+2-k)*(n-j+1-k)/2)%mod)%=mod;
		}
	}
	printf("%lld\n",dp[0][n]);
    return 0;
}
