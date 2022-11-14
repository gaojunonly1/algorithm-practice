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

int n,m,K;
vector<pii>G[N1];
vector<int>kg;
bool skg[N1];
bool vis[N1][2];
int dist[N1][2];

void bfs(int s,int opt);

int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int oo,pp,qq;
	ll o,p,q;
	
	scanf("%d%d%d",&n,&m,&K);
	fz1(i,m) {
		scanf("%d%d%d",&pp,&qq,&oo);
		G[pp].pb(mp(qq,oo));
		G[qq].pb(mp(pp,oo));
	}
	fz1(i,K) {
		scanf("%d",&oo);
		kg.pb(oo);
		skg[oo]=1;
	}
	bfs(1,1);
	if(dist[n][0]==-1) {
		printf("%d\n",dist[n][1]);
	}
	else {
		if(dist[n][1]==-1) {
			printf("%d\n",dist[n][0]);
		}
		else {
			printf("%d\n",min(dist[n][0],dist[n][1]));
		}
	}
    return 0;
}

void bfs(int s,int opt) {
	queue<pii>que;
	memset(dist,-1,sizeof dist);
	que.push(mp(s,opt));
	dist[s][opt]=0;
	if(skg[s]) {
		que.push(mp(s,opt^1));
		dist[s][opt^1]=0;
	}
	while(!que.empty()) {
		pii tmp=que.front();
		vis[tmp.fi][tmp.se]=1;
		ff(G[tmp.fi],itr) {
			if((*itr).se!=tmp.se)
				continue;
			if(vis[(*itr).fi][tmp.se])
				continue;
			pii jyl;
			jyl.fi=(*itr).fi;
			jyl.se=tmp.se;
			if(dist[jyl.fi][jyl.se]==-1||dist[jyl.fi][jyl.se]>dist[tmp.fi][tmp.se]+1) {
				dist[jyl.fi][jyl.se]=dist[tmp.fi][tmp.se]+1;
				que.push(jyl);
			}
			if(skg[jyl.fi]) {
				jyl.se^=1;
				if(dist[jyl.fi][jyl.se]==-1||dist[jyl.fi][jyl.se]>dist[tmp.fi][tmp.se]+1) {
					dist[jyl.fi][jyl.se]=dist[tmp.fi][tmp.se]+1;
					que.push(jyl);
				}
			}
		}
		que.pop();
	}
}
