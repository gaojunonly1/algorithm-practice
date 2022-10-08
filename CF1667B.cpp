#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,m;
ll a[500005];
int dp[500005];
int xt[500005];
int inf=1e9+7;
struct node {
	ll qzh;
	int id,pos;
}jyl[500005];
bool cmpqzh(node pp,node qq);
bool cmpid(node pp,node qq);
struct Tree {
	int tn;
	int s[500005];
	#define lowbit(x) ((x)&(-x))
	Tree() {
		tn=0;
		return;
	}
	void CSH(int oo) {
		tn=oo;
		fill(s+1,s+tn+1,-inf);
		return;
	}
	void Add(int x,int y) {
		while(x<tn) {
			s[x]=max(s[x],y);
			x+=lowbit(x);
		}
	}
	int Ask(int x) {
		int jyl=-inf;
		while(x>0) {
			jyl=max(jyl,s[x]);
			x-=lowbit(x);
		}
		return jyl;
	}
}T;
void solve();
int main() {
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
	jyl[0].qzh=0;
	for(i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		jyl[i].qzh=jyl[i-1].qzh+a[i];
		jyl[i].id=i;
	}
	jyl[n+1].qzh=0;
	jyl[n+1].id=n+1;
	sort(jyl+1,jyl+n+2,cmpqzh);
	jyl[1].pos=m=1;
	for(i=2;i<=n+1;i++) {
		if(jyl[i].qzh!=jyl[i-1].qzh)
			m++;
		jyl[i].pos=m;
	}
	sort(jyl+1,jyl+n+2,cmpid);
	T=Tree();
	T.CSH(m);
	T.Add(jyl[n+1].pos,0);
	for(i=1;i<=m;i++)
		xt[i]=-n*2;
	dp[0]=0;
	for(i=1;i<=n;i++) {
		dp[i]=dp[i-1]+(a[i]>0?1:0)+(a[i]<0?-1:0);
		if(jyl[i].pos>1)
			dp[i]=max(dp[i],T.Ask(jyl[i].pos-1)+i);
		T.Add(jyl[i].pos,dp[i]-i);
	}
	printf("%d\n",dp[n]);
	return;
}
bool cmpqzh(node pp,node qq) {
	return pp.qzh<qq.qzh;
}
bool cmpid(node pp,node qq) {
	return pp.id<qq.id;
}
/*
5
4
0 -2 3 -4
3
1 2 -3
5
-1 -2 3 -1 -1
6
-1 2 -3 4 -5 6
7
1 -1 -1 1 -1 -1 1
*/
