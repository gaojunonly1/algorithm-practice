#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
const int N1=100005;
int n;
ll w[N1];
vector<int>G[N1];
ll wwx;
struct node {
	ll val;
	ll delta;
	node() {
		val=delta=0ll;
	}
}a[N1];
void dfs(int u,int f);
ll lcm(ll a,ll b);
int main() {
	int i,j,k;
	ll oo,pp,qq;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%llu",&w[i]);
		wwx+=w[i];
	}
	for(i=1;i<n;i++) {
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1,0);
	printf("%llu\n",wwx-a[1].val);
    return 0;
}
void dfs(int u,int f) {
	int son=0;
	a[u].delta=1;
	a[u].val=inf;
	int tag=1;
	ll jc=inf;
	for(auto v:G[u]) {
		if(v==f)
			continue;
		son++;
		dfs(v,u);
		if(tag)
			a[u].delta=lcm(a[u].delta,a[v].delta);
		if(a[u].delta>jc) {
			tag=0;
			a[u].delta=inf;
		}
	}
	if(son==0) {
		a[u].delta=1;
		a[u].val=w[u];
		return;
	}
	if(tag==0) {
		a[u].val=0;
		return;
	}
	for(auto v:G[u]) {
		if(v==f)	
			continue;
		a[u].val=min(a[u].val,a[v].val-a[v].val%a[u].delta);
	}
	a[u].val*=son;
	a[u].delta*=son;
}
ll lcm(ll a,ll b) {
  	return a/__gcd(a,b)*b;
}
