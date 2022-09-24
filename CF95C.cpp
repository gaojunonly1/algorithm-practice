#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;
typedef pair<int,long long> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,m;
int A,B;
vector<pii>G[1005];
ll t[1005],c[1005];
ll tim[1005][1005];
ll dis[1005];
bool vis[1005];
struct node {
	int u;
	ll w;
	operator<(const node oo) const{
		return w>oo.w;
	}
};
priority_queue<node>heap;
void Dijkstra(int s,ll *a);
int main() {
	int i,j;
	int u,v;
	ll w;
	scanf("%d%d%d%d",&n,&m,&A,&B);
	for(i=1;i<=m;i++) {
		scanf("%d%d%lld",&u,&v,&w);
		G[u].pb(mp(v,w));
		G[v].pb(mp(u,w));
	}
	for(i=1;i<=n;i++)
		scanf("%lld%lld",&t[i],&c[i]);
	for(i=1;i<=n;i++)
		Dijkstra(i,tim[i]);
	for(i=1;i<=n;i++) {
		G[i].erase(G[i].begin(),G[i].end());
		G[i].resize(0);
		for(j=1;j<=n;j++) if(j!=i)
			if(tim[i][j]!=-1&&tim[i][j]<=t[i])
				G[i].pb(mp(j,c[i]));
	}
	Dijkstra(A,dis);
	printf("%lld\n",dis[B]);
	return 0;
}
void Dijkstra(int s,ll *a) {
	fill(a,a+n+1,-1);
	memset(vis,0,sizeof vis);
	while(!heap.empty())
		heap.pop();
	heap.push((node){s,a[s]=0});
	while(!heap.empty()) {
		auto oo=heap.top();
		heap.pop();
		int u=oo.u;
		ll val=oo.w;
		if(1==vis[u])
			continue;
		vis[u]=1;
		for(auto pp:G[u]) {
			int v=pp.fi;
			ll w=pp.se;
			if(a[v]==-1||a[v]>val+w) {
				a[v]=val+w;
				heap.push((node){v,a[v]});
			}
		}
	}
}
