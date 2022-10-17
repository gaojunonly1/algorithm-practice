#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
ll sx,sy;
int n;
struct pot {
	ll x,y;
}a[25];
ll bin[25];
ll dp[1<<24];
ll jyl[1<<24];
ll dist(pot pp,pot yy);
ll sqr(ll x);
int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	scanf("%lld%lld",&sx,&sy);
	scanf("%d",&n);
	a[n]=(pot){sx,sy};
	for(i=0;i<n;i++) {
		scanf("%lld%lld",&a[i].x,&a[i].y);
	}
	bin[0]=1;
	for(i=1;i<=n;i++)
		bin[i]=bin[i-1]<<1;
	for(i=0;i<bin[n];i++)
		dp[i]=inf;
	dp[0]=0;
	for(i=0;i<bin[n];i++) {
		if(dp[i]==inf)
			continue;
		for(j=0;j<n;j++) {
			if(i&bin[j])
				continue;
			for(k=0;k<n;k++) {
				if(i&bin[k])
					continue;
				if(dp[i|bin[j]|bin[k]]>dp[i]+dist(a[n],a[j])+dist(a[j],a[k])+dist(a[k],a[n])) {
					dp[i|bin[j]|bin[k]]=dp[i]+dist(a[n],a[j])+dist(a[j],a[k])+dist(a[k],a[n]);
					jyl[i|bin[j]|bin[k]]=bin[j]|bin[k];
				}
				break;
			}
		}
	}
	printf("%lld\n",dp[bin[n]-1]);
	vector<int>wwx;
	ll jc=bin[n]-1;
	while(jc>0) {
		for(i=0;i<n;i++) {
			if(bin[i]&jyl[jc]) {
				wwx.pb(i+1);
			}
		}
		wwx.pb(0);
		jc-=jyl[jc];
	}
	reverse(wwx.begin(),wwx.end());
	wwx.pb(0);
	for(auto tmp:wwx)
		printf("%d ",tmp);
    return 0;
}
ll dist(pot pp,pot qq) {
	return sqr(pp.x-qq.x)+sqr(pp.y-qq.y);
}
ll sqr(ll x) {
	return x*x;
}
