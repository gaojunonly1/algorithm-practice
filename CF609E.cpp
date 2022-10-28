#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
#define iinf INT_MAX

const int N1=200005;
const int M1=400005;

struct DSU {
	int n;
	int f[N1];
	DSU() {
		n=0;
	}
	DSU(int oo) {
		n=oo;
		for(int i=1;i<=n;i++) {
			f[i]=i;
		}
	}
	int Find(int x) {
		if(x==f[x])
			return x;
		f[x]=Find(f[x]);
		return f[x];
	}
	void Merge(int x,int y) {
		int fx=Find(x);
		int fy=Find(y);
		if(fx!=fy) {
			f[fx]=fy;
		}
	}
};

struct Edge {
	int u,v;
	int id;
	ll w;
	bool operator<(const Edge tmp)const {
		return w<tmp.w;
	}
}E[N1];

class Graph {
public:
	Graph() {
		n=0;
	}
	Graph(int nn,int mm) {
		int i;
		n=nn;
		m=mm;
		tot=-1;
		fz1(i,n) {
			head[i]=-1;
		}
		syf=0;
		fz1(i,m) {
			gj[i]=0;
		}
	}
	void Init(int nn,int mm) {
		int i;
		n=nn;
		m=mm;
		tot=-1;
		fz1(i,n) {
			head[i]=-1;
		}
		syf=0;
		fz1(i,m) {
			gj[i]=0;
		}
	}
	void Add(int u,int v,int id,int w) {
		Next[++tot]=head[u];
		to[tot]=v;
		val[tot]=w;
		eid[tot]=id;
		head[u]=tot;
	}
	void Addedge(int u,int v,int id,int w) {
		Add(u,v,id,w);
		Add(v,u,id,w);
	}
	void Kruskal() {
		int i;
		DSU D(n);
		syf=0;
		sort(E+1,E+m+1);
		fz1(i,m) {
			int pp=D.Find(E[i].u),qq=D.Find(E[i].v);
			if(pp==qq)
				continue;
			D.Merge(E[i].u,E[i].v);
//			cout<<"!!!  "<<E[i].u<<" "<<E[i].v<<" "<<E[i].w<<endl;
			syf+=E[i].w;
			Addedge(E[i].u,E[i].v,E[i].id,E[i].w);
		}
	}
	void Dfs(int u,int fa1) {
		int i;
		for(i=head[u];i!=-1;i=Next[i]) {
			int v=to[i];
			if(v==fa1)
				continue;
			gj[eid[i]]=syf;
			dep[v]=dep[u]+1;
			fa[v][0]=u;
			g[v][0]=val[i];
			Dfs(v,u);
		}
	}
	ll Askg(int x,int y) {
		int j;
		if(dep[x]<dep[y]) {
			swap(x,y);
		}
		ll jyl=0;
		if(dep[x]>dep[y]) {
			fd0g(j,20) {
				if(dep[fa[x][j]]>dep[y]) {
					jyl=max(jyl,g[x][j]);
					x=fa[x][j];
				}
			}
			jyl=max(jyl,g[x][0]);
			x=fa[x][0];
		}
		if(x==y) {
			return jyl;
		}
//		cout<<"x="<<x<<" "<<"y="<<y<<endl;
		fd0g(j,20) {
			if(fa[x][j]!=fa[y][j]) {
				jyl=max(jyl,g[x][j]);
				jyl=max(jyl,g[y][j]);
				x=fa[x][j];
				y=fa[y][j];
			}
		}
		jyl=max(jyl,g[x][0]);
		jyl=max(jyl,g[y][0]);
		return jyl;
	}
	void Solve() {
		int i,j;
		Kruskal();
		fa[1][0]=0;
		dep[1]=1;
		Dfs(1,0);
		fz1(j,20) {
			fz1(i,n) {
				fa[i][j]=fa[fa[i][j-1]][j-1];
				g[i][j]=max(g[i][j-1],g[fa[i][j-1]][j-1]);
			}
		}
		fz1(i,m) {
			if(gj[E[i].id]) {
				continue;
			}
			gj[E[i].id]=syf+E[i].w-Askg(E[i].u,E[i].v);
//			cout<<E[i].id<<" "<<E[i].w<<" "<<Askg(E[i].u,E[i].v)<<endl;
		}
		fz1(i,m) {
			printf("%lld\n",gj[i]);
		}
	}
private:
	int n;
	int tot;
	int head[N1],Next[M1],eid[M1],to[M1];
	ll val[M1];
	int m;
	ll syf;
	ll gj[N1];
	int dep[N1];
	int fa[N1][21];
	ll g[N1][21];
};

Graph G;

int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	
	int n,m;
	scanf("%d%d",&n,&m);
	G.Init(n,m);
	fz1(i,m) {
		scanf("%d%d%lld",&p,&q,&oo);
		E[i]=(Edge){p,q,i,oo};
	}
	G.Solve();
    return 0;
}
