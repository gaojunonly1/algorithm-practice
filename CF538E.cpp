#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
int n;
vector<int>G[200005];
int dp[200005][2];
int deg[200005];
bool leaf[200005];
void dfs(int u,int f);
int main() {
	int i,j,k;
	ll oo,pp,qq;
	scanf("%d",&n);
	if(n==1) {
		printf("1 1\n");
		return 0;
	}
	for(i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
		deg[u]++;
		deg[v]++;
	}
	int jc=0;
	for(i=2;i<=n;i++)
		if(deg[i]==1) {
			leaf[i]=1;
			jc++;
		}
	dfs(1,0);
	printf("%d %d\n",jc-dp[1][1]+1,dp[1][0]);
    return 0;
}
void dfs(int u,int f) {
	if(leaf[u]) {
		dp[u][0]=dp[u][1]=1;
		return;
	}
	dp[u][1]=n;
	dp[u][0]=0;
	for(auto v:G[u]) {
		if(v==f)
			continue;
		dfs(v,u);
		dp[u][1]=min(dp[u][1],dp[v][0]);
		dp[u][0]+=dp[v][1];
	}
}
