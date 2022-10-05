#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,m,b;
ll dp[1<<21];
ll bin[21];
struct node {
	ll x;
	int k;
	ll zt;
}a[105];
bool cmpk(node pp,node qq);
int main() {
	int i,j,k;
	int oo,pp,qq;
	ll o;
	scanf("%d%d%lld",&n,&m,&b);
	bin[0]=1;
	for(i=1;i<=m;i++)
		bin[i]=bin[i-1]<<1;
	for(i=1;i<=n;i++) {
		scanf("%lld%d%d",&a[i].x,&a[i].k,&oo);
		a[i].zt=0;
		for(j=1;j<=oo;j++) {
			scanf("%d",&pp);
			a[i].zt|=bin[pp-1];
		}
	}
	sort(a+1,a+n+1,cmpk);
	fill(dp,dp+bin[m],-1);
	dp[0]=0;
	ll wwx=-1;
	for(i=1;i<=n;i++) {
		for(j=0;j<bin[m];j++) {
			if(-1!=dp[j]) {
				o=j|a[i].zt;
				if(dp[o]==-1)
					dp[o]=dp[j]+a[i].x;
				else
					dp[o]=min(dp[o],dp[j]+a[i].x);
			}
		}
		if(-1!=dp[bin[m]-1]) {
			o=dp[bin[m]-1]+1ll*b*a[i].k;
			wwx=(wwx==-1)?o:min(wwx,o);
		}
	}
	printf("%lld\n",wwx);
    return 0;
}
bool cmpk(node pp,node qq) {
	return pp.k<qq.k;
}
