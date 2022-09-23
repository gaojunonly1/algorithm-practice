#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
vector<pii>G[100005];
ll sz[100005];
ll dp1[100005],dp2[100005];
ll wwx=0;
int check(int w);
void pre_sz(int u,int fa);
void pre_ts(int u,int fa);
void dfs1(int u,int fa);
void dfs2(int u,int fa);
int main() {
	int i;
	scanf("%d",&n);
	for(i=1;i<n;i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		w=check(w);
		G[u].pb(mp(w,v));
		G[v].pb(mp(w,u));
	}
	pre_sz(1,0);
	dfs1(1,0);
	dfs2(1,0);
	for(i=1;i<=n;i++)
		wwx+=dp1[i]*(dp1[i]-1)+dp2[i]*(dp2[i]-1)+dp1[i]*dp2[i]*2;
	printf("%lld\n",wwx);
    return 0;
}
void pre_sz(int u,int fa) {
	sz[u]=1;
	for(auto oo:G[u]) {
		int v=oo.se,w=oo.fi;
		if(v==fa)
			continue;
		pre_sz(v,u);
		sz[u]+=sz[v];
	}
	return;
}
void dfs1(int u,int fa) {
	dp1[u]=0;
	for(auto oo:G[u]) {
		int v=oo.se,w=oo.fi;
		if(v==fa)
			continue;
		dfs1(v,u);
		if(0!=w)
			dp1[u]+=sz[v];
		else
			dp1[u]+=dp1[v];
	}
}
void dfs2(int u,int fa) {
	for(auto oo:G[u]) {
		int v=oo.se,w=oo.fi;
		if(v==fa)
			continue;
		dp2[v]=w?(n-sz[v]):dp2[u]+dp1[u]-dp1[v];
		dfs2(v,u);
	}
}
int check(int w) {
	int jyl=1;
	while(w) {
		if(w%10!=4&&w%10!=7) {
			jyl=0;
			break;
		}
		w/=10;
	}
	return jyl;
}
