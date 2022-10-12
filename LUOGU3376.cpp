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
	public:
		int n,m,s,t;
		Graph() {
			cnt=-1;
			memset(head,-1,sizeof head);
			memset(Next,-1,sizeof Next);
		}
		void Init() {
			cnt=-1;
			memset(head,-1,sizeof head);
			memset(Next,-1,sizeof Next);
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
	private:
		int cnt;
		int head[205];
		int Next[10005];
		int to[10005];
		ll val[10005];
		int depth[205];
		int cur[205];
};
int main() {
	int i,j,k;
	ll oo;
	int pp,qq;
	Graph G;
	scanf("%d%d%d%d",&G.n,&G.m,&G.s,&G.t);
	for(i=1;i<=G.m;i++) {
		scanf("%d%d%lld",&pp,&qq,&oo);
		G.AddEdge(pp,qq,oo);
	}
	printf("%lld\n",G.Dinic());
    return 0;
}
