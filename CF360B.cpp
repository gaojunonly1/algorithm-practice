#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,k;
ll a[2005];
ll wwx;
int dp[2005];
bool check(ll oo);
int main() {
	int i,j;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	ll l1=0,r1=2e9;
	wwx=0;
	while(l1<=r1) {
		ll mid=(l1+r1)>>1;
		if(check(mid)) {
			wwx=mid;
			r1=mid-1;
		}
		else
			l1=mid+1;
	}
	printf("%lld\n",wwx);
    return 0;
}
bool check(ll oo) {
	int i,j;
	memset(dp,63,sizeof dp);
	for(i=1;i<n;i++) {
		dp[i]=min(dp[i],i-1);
		for(j=i+1;j<=n;j++)
			if(1ll*abs(a[j]-a[i])<=1ll*(j-i)*oo)
				dp[j]=min(dp[j],dp[i]+j-i-1);
	}
	int abld=dp[n];
	for(i=1;i<n;i++)
		abld=min(abld,dp[i]+n-i);
	return abld<=k?1:0;
}
