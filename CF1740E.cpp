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

const int N1=100005;

vector<int>G[N1];

int dp[N1][2];

void dfs(int u);

int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	
	int n;
	scanf("%d",&n);
	fz(i,2,n) {
		scanf("%d",&p);
		G[p].pb(i);
	}
	dfs(1);
	int gj=0;
	fz1(i,n) {
		gj=max(gj,max(dp[i][0],dp[i][1]));
	}
	printf("%d\n",gj);
    return 0;
}

void dfs(int u) {
	int syf=-iinf;
	if(G[u].size()==0) {
		dp[u][0]=0;
		dp[u][1]=1;
		return;
	}
	dp[u][0]=0;
	ff(G[u],itr) {
		int v=*itr;
		dfs(v);
		syf=max(syf,dp[v][1]);
		dp[u][0]+=max(dp[v][0],dp[v][1]);
	}
	dp[u][1]=syf+1;
}
/*
10
1 1 1 3 3 3 6 6 6
*/
