#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,m,e;
vector<int>G[505];
int wwx;
int jyl[505],vtim[505];
bool dfs(int u,int tag);
int main() {
	int i,j,k;
	int oo,pp,qq;
	scanf("%d%d%d",&n,&m,&e);
	for(i=1;i<=e;i++) {
		scanf("%d%d",&pp,&qq);
		G[pp].pb(qq);
	}
	fill(jyl+1,jyl+n+1,0);
	fill(vtim+1,vtim+n+1,0);
	wwx=0;
	for(i=1;i<=n;i++) if(dfs(i,i))
		wwx++;
	printf("%d\n",wwx);
    return 0;
}
bool dfs(int u,int tag) {
	if(vtim[u]==tag)
		return false;
	vtim[u]=tag;
	for(auto v:G[u])
		if(0==jyl[v]||dfs(jyl[v],tag)) {
			jyl[v]=u;
			return true;
		}
	return false;
}
