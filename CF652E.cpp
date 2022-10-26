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

const int N1=600005;
const int M1=1200005;

class Graph{
public:
	void Add(int u,int v,int w) {
		Next[++tot]=head[u];
		to[tot]=v;
		val[tot]=w;
		bridge[tot]=0;
		head[u]=tot;
	}
	void Addedge(int u,int v,int w) {
		Add(u,v,w);
		Add(v,u,w);
	}
	void Init(int nn) {
		int i;
		n=nn;
		idx=0;
		tot=-1;
		fz1(i,n) {
			head[i]=-1;
			dfn[i]=low[i]=0;
			block[i]=0;
			syf[i]=0;
		}
	}
	int idx;
	int dfn[N1],low[N1];
	int bridge[M1];
	void Tarjan(int u,int in_edge){
        dfn[u]=low[u]=++idx;
        for(int i=head[u];i+1;i=Next[i]){
            int v=to[i];
            if(!dfn[v]){
                Tarjan(v,i);
                low[u]=min(low[u],low[v]);
                if(low[v]>low[u]) {
					bridge[i]=bridge[i^1]=1;
				}
            }
            else if(i!=(in_edge^1)) {
                low[u]=min(low[u],dfn[v]);
			}
        }
    }
	int block[N1],dcc=0;
	int syf[N1];
	void Dfs(int u,int col) {
		int i;
		block[u]=col;
		for(i=head[u];i!=-1;i=Next[i]) {
			int v=to[i];
			if(bridge[i]) {
				continue;
			}
			if(!block[v]) {
				Dfs(v,col);
			}
		}
	}
	void Get_edccs() {
		int i;
		fz1(i,n) {
			if(!block[i]) {
				dcc++;
				Dfs(i,dcc);
			}
		}
	}
	vector<pii>G[N1];
	int gj[N1];
	bool vis[N1];
	void Solve(int s,int t) {
		int i,j;
		fz1(i,n) {
			if(!dfn[i]) {
				Tarjan(i,-1);
			}
		}
		Get_edccs();
//		cout<<"dcc="<<dcc<<endl;
		fz1(i,n) {
			int u=block[i];
			for(j=head[i];j!=-1;j=Next[j]) {
				int v=block[to[j]];
				if(u==v) {
					syf[u]+=val[j];
				}
				else {
					G[u].pb(mp(v,val[j]));
				}
			}
		}
		queue<int>que;
		fill(vis+1,vis+dcc+1,0);
		s=block[s];
		t=block[t];
		gj[s]=syf[s];
		vis[s]=1;
		que.push(s);
		while(!que.empty()) {
			int u=que.front();
			ff(G[u],itr) {
				int v=(*itr).fi;
				if(vis[v])
					continue;
				gj[v]=gj[u]+(*itr).se+syf[v];
				vis[v]=1;
				que.push(v);
			}
			que.pop();
		}
		if(gj[t]!=0) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
	}
private:
	int n;
	int tot=-1;
	int head[N1],Next[M1],val[M1],to[M1];
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
		scanf("%d%d%d",&p,&q,&o);
		G1.Addedge(p,q,o);
	}
	int s,t;
	scanf("%d%d",&s,&t);
	G1.Solve(s,t);
    return 0;
}
