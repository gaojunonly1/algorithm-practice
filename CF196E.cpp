#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,m,n1;
struct Edge {
	int u,v;
	ll w;
}jyl[100005];
vector<pair<int,ll>>G[100005];
ll dis[100005],dis1[100005];
bool vis[100005];
int las[100005];
int fa[100005];
ll wwx=0;
struct node {
	int u;
	ll w;
	operator<(const node oo) const{
		return w>oo.w;
	}
};
priority_queue<node>heap;
void Dijkstra(ll *a);
bool cmpw(Edge pp,Edge qq);
int getf(int x);
int main() {
	int i,j,k;
	int oo,pp;
	ll qq;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++) {
		scanf("%d%d%lld",&oo,&pp,&qq);
		G[oo].pb(mp(pp,qq));
		G[pp].pb(mp(oo,qq));
		jyl[i]=(Edge){oo,pp,qq};
	}
	memset(vis,0,sizeof vis);
	while(!heap.empty())
		heap.pop();
	memset(dis1,63,sizeof dis1);
	dis1[1]=0;
	heap.push((node){1,0});
	Dijkstra(dis1);
	set<int>csz;
	scanf("%d",&n1);
	wwx=1e9+7;
	for(i=1;i<=n1;i++) {
		scanf("%d",&oo);
		wwx=min(wwx,dis1[oo]);
		csz.insert(oo);
	}
	memset(vis,0,sizeof vis);
	while(!heap.empty())
		heap.pop();
	memset(dis,63,sizeof dis);
	for(auto tmp:csz) {
		dis[tmp]=0;
		heap.push((node){tmp,0});
		las[tmp]=tmp;
		fa[tmp]=tmp;
	}
	Dijkstra(dis);
	for(i=1;i<=m;i++) {
		jyl[i].w+=dis[jyl[i].u]+dis[jyl[i].v];
		jyl[i].u=las[jyl[i].u];
		jyl[i].v=las[jyl[i].v];
	}
	sort(jyl+1,jyl+m+1,cmpw);
	for(i=1;i<=m;i++) {
		oo=getf(jyl[i].u);
		pp=getf(jyl[i].v);
		if(oo==pp)
			continue;
		wwx+=jyl[i].w;
		fa[oo]=pp;
	}
	printf("%lld\n",wwx);
    return 0;
}
void Dijkstra(ll *a) {
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
				las[v]=las[u];
				heap.push((node){v,a[v]});
			}
		}
	}
}
bool cmpw(Edge pp,Edge qq) {
	return pp.w<qq.w;
}
int getf(int x) {
	return x==fa[x]?x:fa[x]=getf(fa[x]);
}
/*
3 3
1 2 2
1 3 1
2 3 5
2
2 3
*/
