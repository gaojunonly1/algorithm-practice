#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
vector<pii>G[2005];
vector<int>dist1[2005];
void dfs(int rt,int u,int fa);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	vector<int>dist[2005];
	int i,j;
	cin>>n;
	for(i=0;i<n;i++) {
		dist[i].resize(n);
		for(j=0;j<n;j++)
			cin>>dist[i][j];
	}
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++)
			if(i!=j&&dist[i][j]!=dist[j][i]) {
				cout<<"NO"<<endl;
				return 0;
			}
		if(dist[i][i]!=0) {
			cout<<"NO"<<endl;
			return 0;
		}
	}
	vector<int>cost(n,1000000005);
	vector<bool>flg(n,0);
	priority_queue<pair<int,pii>>que;
	que.push(mp(cost[0]=0,mp(0,0)));
	int cnt=n-1;
	while(0==que.empty()) {
		auto tmp=que.top();
		que.pop();
		int u=tmp.se.se;
		if(flg[u])
			continue;
		flg[u]=1;
		if(tmp.se.fi!=tmp.se.se) {
			G[tmp.se.fi].pb(mp(u,-tmp.fi));
			G[u].pb(mp(tmp.se.fi,-tmp.fi));
			cnt--;
//			cout<<u<<" "<<tmp.se.fi<<" "<<-tmp.fi<<endl;
		}
		for(i=0;i<n;i++) {
			int w=dist[u][i];
			if(0==w)
				continue;
			if(cost[i]>w&&!flg[i]) {
				cost[i]=w;
				que.push(mp(-w,mp(u,i)));
			}
		}
	}
	if(cnt) {
		cout<<"NO"<<endl;
		return 0;
	}
//	for(i=0;i<n;i++)
//		for(auto v:G[i])
//			cout<<i<<" "<<v.fi<<endl;
	for(i=0;i<n;i++) {
		dist1[i].resize(n,0);
		dfs(i,i,i);
	}
	for(i=0;i<n;i++) {
		for(j=0;j<n;j++) {
			if(dist[i][j]!=dist1[i][j]) {
//				cout<<i<<" "<<j<<" "<<dist[i][j]<<" "<<dist1[i][j]<<endl;
				cout<<"NO"<<endl;
				return 0;
			}
		}
	}
	cout<<"YES"<<endl;
    return 0;
}
void dfs(int rt,int u,int fa) {
//	cout<<"rt="<<rt<<" "<<"u="<<" "<<u<<endl;
	for(auto tmp:G[u]) {
		int v=tmp.fi,w=tmp.se;
		if(v==fa)
			continue;
//		cout<<"------------> "<<"v="<<v<<" "<<"w="<<w<<endl;
		dist1[rt][v]=dist1[rt][u]+w;
		dfs(rt,v,u);
	}
}
