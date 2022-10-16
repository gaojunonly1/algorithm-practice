#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
const int N1=200005;
int n;
int tot=0,head[N1],to[N1<<1],Next[N1<<1];
ll a[N1];
ll m,dp[N1];
ll wwx;
void solve();
void init();
void addedge(int u,int v);
void dfs(int u,int f,ll num);
int main() {
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	int T;
	scanf("%d",&T);
	while(T--)
		solve(); 
    return 0;
}
void solve() {
	init();
	int oo;
	scanf("%d%lld",&n,&m);
	for(int i=2;i<=n;i++) {
		scanf("%d",&oo);
		addedge(oo,i);
		addedge(i,oo);
	}
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	dfs(1,0,m);
	printf("%lld\n",wwx);
}
void dfs(int u,int f,ll num) {
	wwx+=num*a[u];
	dp[u]=a[u];
	int i,v,son=0;
	for(i=head[u];i!=-1;i=Next[i]) {
		v=to[i];
		if(v==f)
			continue;
		son++;
	}
	if(0==son)
		return;
	vector<pair<ll,int>>jyl;
	for(i=head[u];i!=-1;i=Next[i]) {
		v=to[i];
		if(v==f)
			continue;
		dfs(v,u,num/son);
		jyl.pb(mp(dp[v],v));
	}
	sort(jyl.begin(),jyl.end());
	reverse(jyl.begin(),jyl.end());
	int cnt=num%son;
	for(auto oo:jyl) {
		if(cnt>0) {
			wwx+=oo.fi;
			cnt--;
		}
		else
			dp[u]=max(dp[u],oo.fi+a[u]);
	}
}
void init() {
	tot=0;
	memset(head,-1,sizeof head);
	wwx=0;
}
void addedge(int u,int v) {
	Next[++tot]=head[u];
	to[tot]=v;
	head[u]=tot;
}
