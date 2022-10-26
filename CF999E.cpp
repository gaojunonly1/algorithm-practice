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

const int N1=5005,M1=10005;

class Graph{
	public:
		Add(int u,int v) {
			Next[++tot]=head[u];
			to[tot]=v;
			head[u]=tot;
		}
		Addedge(int u,int v) {
			Add(u,v);
		}
		void Init(int nn) {
			int i;
			n=nn;
			idx=0;
			top=0;
			scc_num=0;
			fz1(i,n) {
				head[i]=0;
				dfn[i]=low[i]=0;
				instk[i]=0;
				col[i]=0;
				scc[i].resize(0);
			}
		}
		int idx;
		int dfn[N1],low[N1];
		int top;
		int stk[N1];
		bool instk[N1];
		int col[N1];
		int scc_num;
		vector<int>scc[N1];
		void Tarjan(int u) {
			dfn[u]=low[u]=++idx;
			stk[++top]=u;
			instk[u]=1;
			int i;
			for(i=head[u];i!=0;i=Next[i]) {
				int v=to[i];
				if(!dfn[v]) {
					Tarjan(v);
					low[u]=min(low[u],low[v]);
				}
				else if(instk[v]) {
					low[u]=min(low[u],dfn[v]);
				}
			}
			if(low[u]==dfn[u]) {
				scc_num++;
				while(true) {
					int oo=stk[top--];
					col[oo]=scc_num;
					instk[oo]=0;
					scc[scc_num].pb(oo);
					if(oo==u) {
						break;
					}
				}
			}
		}
		int syf[N1];
		int Solve(int root) {
			int i,j;
			fz1(i,scc_num) {
				syf[i]=0;
			}
			syf[col[root]]=1;
			fz1(i,n) {
				int u=col[i];
				for(j=head[i];j!=0;j=Next[j]) {
					int v=col[to[j]];
					if(u==v)
						continue;
					syf[v]++;
				}
			}
			int gj=0;
			fz1(i,scc_num) {
				if(syf[i]==0) {
					gj++;
				}
			}
			return gj;
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
	
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	G1.Init(n);
	fz1(i,m) {
		scanf("%d%d",&p,&q);
		G1.Addedge(p,q);
	}
	fz1(i,n) {
		if(!G1.dfn[i]) {
			G1.Tarjan(i);
		}
	}
	printf("%d\n",G1.Solve(s));
    return 0;
}
