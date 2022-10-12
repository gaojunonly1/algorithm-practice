#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const ll inf=0x7fffffffffff;
class Graph {
	static const int maxN=2005;
	static const int maxM=8000005;
	public:
		int n,m,s,t;
		int mch[2005];
		Graph() {
			cnt=-1;
			memset(head,-1,sizeof head);
		}
		void Init() {
			cnt=-1;
			memset(head,-1,sizeof head);
		}
		void Add(int u,int v,ll w) {
			cnt++;
			Next[cnt]=head[u];
			head[u]=cnt;
			to[cnt]=v;
			val[cnt]=w;
		}
		void AddEdge(int u,int v,ll w) {
			Add(u,v,w);
			Add(v,u,0);
		}
		ll dfs(int u,ll flow) {
			if(u==t)
				return flow;
			for(int& i=cur[u];flow&&i!=-1;i=Next[i]) {
				if(depth[to[i]]==depth[u]+1&&val[i]>0) {
					ll oo=dfs(to[i],min(flow,val[i]));
					if(oo>0) {
						val[i]-=oo;
						val[i^1]+=oo;
						return oo;
					}
				}
			}
			return 0ll;
		}
		bool bfs() {
			queue<int>que;
			while(!que.empty())
				que.pop();
			memset(depth,-1,sizeof depth);
			depth[s]=1;
			que.push(s);
			while(!que.empty()) {
				int u=que.front();
				que.pop();
				for(int i=head[u];i!=-1;i=Next[i]) {
					if(depth[to[i]]==-1&&val[i]>0) {
						depth[to[i]]=depth[u]+1;
						que.push(to[i]);
					}
				}
			}
			return (depth[t]>0)?1:0;
		}
		ll Dinic() {
			ll wwx=0;
			while(bfs()) {
				for(int i=1;i<=n;i++)
					cur[i]=head[i];
				while(ll oo=dfs(s,inf))
					wwx+=oo;
			}
			return wwx;
		}
		void Match() {
			int i,j,k;
			for(i=1;i<=n;i++) {
				for(j=head[i];j!=-1;j=Next[j]) {
					if(to[j]==s)
						continue;
					if(val[j]==0)
						mch[i]=to[j];
				}
			}
		}
	private:
		int cnt;
		int head[maxN];
		int Next[maxM];
		int to[maxM];
		ll val[maxM];
		int depth[maxN];
		int cur[maxN];
};
int n;
ll h[1005],p1,p2;
ll d1[1005],d2[1005];
map<ll,int>jyl;
map<ll,bool>vis;
void solve();
void PRINT(bool oo,ll delta);
Graph G;
bool judge(ll delta);
int main() {
	freopen("test.in","r",stdin);
	int i,j,k;
	ll oo,pp,qq;
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
    return 0;
}
void solve() {
	int i,j,k;
	ll oo,pp,qq;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",d1+i);
	for(i=1;i<=n;i++)
		scanf("%lld",d2+i);
	sort(d2+1,d2+n+1);
	jyl.clear();
	for(i=1;i<=n;i++)
		if(0==jyl[d2[i]])
			jyl[d2[i]]=i;
	vis.clear();
	for(i=1;i<=n;i++) {
		oo=abs(d1[i]-d2[1]);
		if(!vis[oo]) {
			if(judge(oo)) {
				PRINT(1,oo);
				return;
			}
			vis[oo]=1;
		}
		oo=d1[i]+d2[1];
		if(!vis[oo]) {
			if(judge(oo)) {
				PRINT(1,oo);
				return;
			}
			vis[oo]=1;
		}
	}
	PRINT(0,0);
}
void PRINT(bool oo,ll delta) {
	if(1==oo) {
		printf("YES\n");
		G.Match();
		p1=0;
		p2=delta;
		for(int i=1;i<=n;i++) {
			int j=G.mch[i]-n;
			if(d1[i]-d2[j]==delta||d1[i]+d2[j]==delta)
				h[i]=p1+d1[i];
			else
				h[i]=p1-d1[i];
		}
		ll mn=2000000000;
		for(int i=1;i<=n;i++)
			mn=min(mn,h[i]);
		if(mn<0) {
			mn*=-1;
			for(int i=1;i<=n;i++)
				h[i]+=mn;
			p1+=mn;
			p2+=mn;
		}
		for(int i=1;i<=n;i++)
			printf("%lld ",h[i]);
		printf("\n");
		printf("%lld %lld\n",p1,p2);
	}
	else
		printf("NO\n");
}
bool judge(ll delta) {
	int i,j,k;
	ll oo;
	G.Init();
	G.n=n*2+2;
	G.s=n*2+1;
	G.t=n*2+2;
	for(i=1;i<=n;i++) {
		G.AddEdge(n*2+1,i,1);
		G.AddEdge(i+n,n*2+2,1);
		oo=d1[i]+delta;
		k=jyl[oo];
		if(k) {
			for(j=k;j<=n&&d2[j]==d2[k];j++)
				G.AddEdge(i,j+n,1);
		}
		if(d1[i]<=delta) {
			oo=delta-d1[i];
			k=jyl[oo];
			if(k) {
				for(j=k;j<=n&&d2[j]==d2[k];j++)
					G.AddEdge(i,j+n,1);
			}
		}
		if(d1[i]>=delta) {
			oo=d1[i]-delta;
			k=jyl[oo];
			if(k) {
				for(j=k;j<=n&&d2[j]==d2[k];j++)
					G.AddEdge(i,j+n,1);
			}
		}
	}
	int wwx=G.Dinic();
	return (wwx==n)?1:0;
}
