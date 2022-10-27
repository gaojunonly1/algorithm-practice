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

const int N1=100005,M1=200005;

class Graph{
public:
	void Add(int u,int v) {
		Next[++tot]=head[u];
		to[tot]=v;
		mark[tot]=0;
		head[u]=tot;
	}
	void Addedge(int u,int v) {
		Add(u,v);
		Add(v,u);
	}
	void Init(int nn) {
		int i;
		n=nn;
		tot=-1;
		idx=0;
		top=0;
		dcc=0;
		fz1(i,n) {
			head[i]=-1;
			dfn[i]=low[i]=0;
			vdcc[i].resize(0);
			is_cut[i]=0;
			block[i]=0;
		}
	}
	int idx;
	int dfn[N1],low[N1];
	int top;
	int stk[N1];
	bool mark[M1];
	bool is_cut[N1];
	int block[N1];
	int dcc;
	vector<int>vdcc[N1];
	vector<int>edcc[N1];
	void Tarjan(int u,int fa) {
		int i;
		dfn[u]=low[u]=++idx;
		int child=0;
		for(i=head[u];i!=-1;i=Next[i]) {
			if(mark[i])
				continue;
			mark[i]=mark[i^1]=1;
			stk[++top]=i;
			int v=to[i];
			if(!dfn[v]) {
				Tarjan(v,u);
				low[u]=min(low[u],low[v]);
				if(low[v]>=dfn[u]) {
					is_cut[u]=1;
					dcc++;
					int e;
					while(true) {
						e=stk[top--];
						if(block[to[e]]!=dcc) {
							block[to[e]]=dcc;
							vdcc[dcc].pb(to[e]);
						}
						if(block[to[e^1]]!=dcc) {
							block[to[e^1]]=dcc;
							vdcc[dcc].pb(to[e^1]);
						}
						edcc[dcc].pb((e>>1)+1);
						if(e==i)
							break;
					}
				}
			}
			else {
				low[u]=min(low[u],dfn[v]);
			}
		}
		if(fa<0&&child<2) {
			is_cut[u]=0;
		}
	}
	int Solve() {
		int i,j;
		fz1(i,n) {
			if(!dfn[i]) {
				Tarjan(i,-1);
			}
		}
		vector<int>gj;
		fz1(i,dcc) {
			if(vdcc[i].size()==edcc[i].size()) {
				ff(edcc[i],syf) {
					gj.pb(*syf);
				}
			}
		}
		printf("%d\n",gj.size());
		sort(gj.begin(),gj.end());
		ff(gj,itr) {
			printf("%d ",*itr);
		}
	}
private:
	int n;
	int tot;
	int head[N1],Next[M1],to[M1];
};
Graph G1;
int main() {
	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	
	int n,m;
	scanf("%d%d",&n,&m);
	G1.Init(n);
	fz1(i,m) {
		scanf("%d%d",&p,&q);
		G1.Addedge(p,q);
	}
	G1.Solve();
    return 0;
}
