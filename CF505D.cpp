#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,m;
vector<int>G[100005],G1[100005];
int cnt;
int wwx=0;
int cor[100005],sz[100005],yh[100005];
int rd[100005];
void dfs(int u);
int main() {
	int i,j,k;
	int oo,pp,qq;
	scanf("%d%d",&n,&m);
	memset(rd,0,sizeof rd);
	for(i=1;i<=m;i++) {
		scanf("%d%d",&oo,&pp);
		G[oo].pb(pp);
		G[pp].pb(oo);
		G1[oo].pb(pp);
		rd[pp]++;
	}
	memset(cor,0,sizeof cor);
	for(i=1;i<=n;i++)
		if(!cor[i]) {
			cor[i]=++cnt;
			sz[cnt]=1;
			dfs(i);
		}
	queue<int>que;
	for(i=1;i<=n;i++)
		if(0==rd[i])
			que.push(i);
	while(!que.empty()) {
		oo=que.front();
		que.pop();
		for(auto v:G1[oo]) {
			rd[v]--;
			if(0==rd[v])
				que.push(v);
		}
	}
	for(i=1;i<=n;i++) {
		if(1==sz[cor[i]])
			continue;
		else if(0!=rd[i])
			yh[cor[i]]=1;
	}
	for(i=1;i<=cnt;i++) {
		if(1==sz[i])
			continue;
		if(yh[i])
			wwx+=sz[i];
		else
			wwx+=sz[i]-1;
	}
	printf("%d\n",wwx);
    return 0;
}
void dfs(int u) {
	for(auto v:G[u]) {
		if(0==cor[v]) {
			cor[v]=cnt;
			sz[cnt]++;
			dfs(v);
		}
	}
}
