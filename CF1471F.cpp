#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,m;
vector<int>G[300005];
bool vis[300005];
int cor[300005];
void solve();
void CSH();
void dfs(int u,int f);
int main() {
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
    return 0;
}
void solve() {
	int i,j,k;
	int u,v;
	scanf("%d%d",&n,&m);
	CSH();
	for(i=1;i<=m;i++) {
		scanf("%d%d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	cor[1]=vis[1]=1;
	for(auto oo:G[1])
		dfs(oo,1);
	vector<int>wwx;
	for(i=1;i<=n;i++) {
		if(0==vis[i]) {
			printf("NO\n");
			return;
		}
		else if(cor[i]==1)
			wwx.pb(i);
	}
	printf("YES\n");
	printf("%d\n",(int)wwx.size());
	sort(wwx.begin(),wwx.end());
	for(auto oo:wwx)
		printf("%d ",oo);
	printf("\n");
}
void CSH() {
	int i;
	for(i=1;i<=n;i++) {
		vis[i]=cor[i]=0;
		G[i].resize(0);
	}
}
void dfs(int u,int f) {
	vis[u]=1;
	int jyl=0;
	for(auto oo:G[u])
		jyl|=cor[oo];
	if(jyl==0)
		cor[u]=1;
	else
		cor[u]=3-jyl;
	for(auto oo:G[u])
		if(!vis[oo])
			dfs(oo,u);
}
