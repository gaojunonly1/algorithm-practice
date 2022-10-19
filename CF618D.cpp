#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
#define iinf INT_MAX
const int N1=200005;
int n;
ll x,y;
vector<int>G[N1];
int dp[N1][2];
void dfs(int u,int f);
int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	scanf("%d%lld%lld",&n,&x,&y);
	for(i=1;i<n;i++) {
		scanf("%d%d",&p,&q);
		G[p].pb(q);
		G[q].pb(p);
	}
	ll wwx=0;
	if(x<y) {
		memset(dp,63,sizeof dp);
		dfs(1,0);
		wwx=(n-dp[1][0])*x+(dp[1][0]-1)*y;
	}
	else {
		wwx=(n-1)*y;
		for(i=1;i<=n;i++) {
			if(G[i].size()==n-1) {
				wwx=wwx-y+x;
				break;
			}
		}
	}
	printf("%lld\n",wwx);
    return 0;
}
void dfs(int u,int f) {
	vector<int>son(0);
	for(auto v:G[u]) {
		if(v==f)
			continue;
		dfs(v,u);
		son.pb(v);
	}
	if(son.size()==0) {
		dp[u][0]=dp[u][1]=1;
		return;
	}
	else if(son.size()==1) {
		dp[u][0]=min(dp[son[0]][0]+1,dp[son[0]][1]);
		dp[u][1]=min(dp[son[0]][0]+1,dp[son[0]][1]);
		return;
	}
	else {
		int jyl=0;
		int mn1=son[0],mn2=son[1];
		if(-dp[mn1][0]+dp[mn1][1]>-dp[mn2][0]+dp[mn2][1])
			swap(mn1,mn2);
		for(auto v:son) {
			jyl+=dp[v][0];
			if(v==mn1||v==mn2)
				continue;
			if(-dp[v][0]+dp[v][1]<-dp[mn1][0]+dp[mn1][1]) {
				mn2=mn1;
				mn1=v;
			}
			else if(-dp[v][0]+dp[v][1]<-dp[mn2][0]+dp[mn2][1]){
				mn2=v;
			}
		}
		dp[u][1]=min(jyl+1,jyl-dp[mn1][0]+dp[mn1][1]);
		dp[u][0]=jyl-dp[mn1][0]+dp[mn1][1]-dp[mn2][0]+dp[mn2][1]-1;
	}
}
