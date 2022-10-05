#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,m,s,t;
ll L;
struct node {
	int u;
	ll w;
	operator<(const node oo) const{
		return w>oo.w;
	}
};
priority_queue<node>heap;
ll dis[1005][1005];
bool vis[1005];
vector<pair<int,ll>>G[1005];
vector<pii> wwx;
ll jgy;
ll jyl[1005];
ll jc[1005][1005];
void Dijkstra(int s,ll *a);
void solve(int s,ll *a);
int main() {
	int i;
	int u,v;
	ll w;
	scanf("%d%d%lld%d%d",&n,&m,&L,&s,&t);
	s++;
	t++;
	for(i=1;i<=m;i++) {
		scanf("%d%d%lld",&u,&v,&w);
		u++;
		v++;
		G[u].pb(mp(v,w));
		G[v].pb(mp(u,w));
		jc[u][v]=jc[v][u]=(w==0)?1:w;
		wwx.pb(mp(u,v));
	}
	Dijkstra(s,dis[s]);
//	Dijkstra(t,dis[t]);
	jgy=L-dis[s][t];
	if(dis[s][t]>L) {
		printf("NO\n");
		return 0;
	}
	solve(s,jyl);
	if(jyl[t]!=L) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for(auto tmp:wwx)
		printf("%d %d %lld\n",tmp.fi-1,tmp.se-1,jc[tmp.fi][tmp.se]);
    return 0;
}
void Dijkstra(int s1,ll *a) {
	fill(a,a+n+1,-1);
	memset(vis,0,sizeof vis);
	while(!heap.empty())
		heap.pop();
	heap.push((node){s1,a[s1]=0});
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
			ll w=jc[u][v];
			if(a[v]==-1||a[v]>val+w) {
				a[v]=val+w;
				heap.push((node){v,a[v]});
			}
		}
	}
}
void solve(int s1,ll *a) {
	fill(a,a+n+1,-1);
	memset(vis,0,sizeof vis);
	while(!heap.empty())
		heap.pop();
	heap.push((node){s1,a[s1]=0});
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
			if(w==0&&a[u]+jc[u][v]<dis[s][v]+jgy)
				jc[u][v]=jc[v][u]=dis[s][v]+jgy-a[u];
			if(a[v]==-1||a[v]>a[u]+jc[u][v]) {
				a[v]=a[u]+jc[u][v];
				heap.push((node){v,a[v]});
			}
		}
	}
}
