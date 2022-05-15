#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
vector<int>dist(3000,998244353);
vector<int>G[3005];
void dfs(int u);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int>deg(n,0);
	int i;
	for(i=0;i<n;i++) {
		int p,q;
		cin>>p>>q;
		p--; q--;
		G[p].pb(q);
		G[q].pb(p);
		deg[p]++;
		deg[q]++;
	}
	queue<int>que;
	for(i=0;i<n;i++)
		if(1==deg[i])
			que.push(i);
	while(!que.empty()) {
		int o=que.front();
		que.pop();
		for(auto v:G[o]) {
			deg[v]--;
			if(1==deg[v])
				que.push(v);
		}
	}
	vector<int>huan;
	for(i=0;i<n;i++)
		if(deg[i]>1) {
			dist[i]=0;
			huan.pb(i);
			dfs(i);
		}
	for(i=0;i<n;i++)
		cout<<dist[i]<<" ";
    return 0;
}
void dfs(int u) {
	for(auto v:G[u]) {
		if(dist[v]==0)	
			continue;
		if(dist[v]>dist[u]+1) {
			dist[v]=dist[u]+1;
			dfs(v);
		}
	}
}
