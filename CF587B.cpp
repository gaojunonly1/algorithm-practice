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
const ll Mod=1000000007;
const int N1=1000005;
ll dp[2][N1];
ll sum[2][N1];
int a[N1],b[N1];
int main() {
	freopen("test.in","r",stdin);
	int o,p,q;
	ll oo,pp,qq;
	
	ll i,j;
	ll n,k,l,nn;
	scanf("%lld%lld%lld",&n,&l,&k);
	for(i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	nn=unique(b+1,b+n+1)-b-1;
	for(i=1;i<=n;i++) {
		a[i]=lower_bound(b+1,b+nn+1,a[i])-b;
	}
	ll wwx=0;
	oo=l/n;
	int pre=0,now=1;
	memset(dp,0,sizeof dp);
	dp[pre][0]=1; 
	for(i=1;i<=k&&i<=oo+1;i++) {
		for(j=0;j<=nn;j++) {
			dp[now][j]=0ll;
		}
		for(j=1;j<=nn;j++) {
			(dp[pre][j]+=dp[pre][j-1])%=Mod;
		}
		for(j=1;j<=n;j++) {
			(dp[now][a[j]]+=dp[pre][a[j]])%=Mod;
		}
		for(j=1;j<=nn;j++) {
			(wwx+=((oo-i+1)%Mod*(dp[now][j]%Mod))%Mod)%=Mod;
		}
		for(j=1;j<=l%n;j++) {
			(wwx+=dp[pre][a[j]])%=Mod;
		}
		swap(pre,now);
	}
	printf("%lld\n",wwx);
    return 0;
}
