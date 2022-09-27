#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
int A,B,C;
vector<int>G[200005];
int fa[200005][20];
int dep[200005];
int yszc[200005],yy[200005];
void dfs(int u,int f);
int Ask_lca(int a,int b);
int main() {
	int i,j,k;
	int oo,pp,qq;
	scanf("%d",&n);
	for(i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	scanf("%d%d%d",&A,&B,&C);
	dep[A]=0;
	fa[A][0]=A;
	dfs(A,A);
	for(i=1;i<=19;i++)
		for(j=1;j<=n;j++)
			fa[j][i]=fa[fa[j][i-1]][i-1];
	int wwxB=yszc[B],B1=yy[B];
	for(i=1;i<=n;i++) {
		oo=Ask_lca(i,B);
		if(dep[B]-dep[oo]<dep[oo]) {
			pp=dep[i];
			if(pp>wwxB) {
				wwxB=pp;
				B1=i;
			}
		}
	}
	int wwxC=wwxB;
	oo=Ask_lca(yy[C],B1);
	wwxC+=dep[B1]+yszc[C]-2*dep[oo];
	for(i=1;i<=n;i++) {
		oo=Ask_lca(B1,i);
		qq=Ask_lca(C,oo);
		if(dep[C]+dep[oo]-2*dep[qq]<dep[B1]-dep[oo]+wwxB)
			wwxC=max(wwxC,wwxB+dep[i]+dep[B1]-2*dep[oo]);
	}
	printf("%d %d\n",wwxB,wwxC);
    return 0;
}
void dfs(int u,int f) {
	yszc[u]=dep[u];
	yy[u]=u;
	for(auto v:G[u]) {
		if(v==f)
			continue;
		fa[v][0]=u;
		dep[v]=dep[u]+1;
		dfs(v,u);
		if(yszc[v]>yszc[u]) {
			yszc[u]=yszc[v];
			yy[u]=yy[v];
		}
	}
}
int Ask_lca(int a,int b) {
	int i,j,k;
	if(dep[a]<dep[b])
		swap(a,b);
	for(i=19;i>=0;i--)
		if(dep[fa[a][i]]>=dep[b])
			a=fa[a][i];
	if(a==b)
		return a;
	for(i=19;i>=0;i--) {
		if(fa[a][i]!=fa[b][i]) {
			a=fa[a][i];
			b=fa[b][i];
		}
	}
	return fa[a][0];
}
