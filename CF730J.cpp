#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
int jyl,jc;
struct node {
	int a,b;
}p[105];
int dp[2][105][20005];
int wwx;
bool cmpb(node pp,node qq);
int main() {
	int i,j,k;
	int oo,pp,qq;
	scanf("%d",&n);
	jyl=0;
	for(i=1;i<=n;i++) {
		scanf("%d",&p[i].a);
		jyl+=p[i].a;
	}
	for(i=1;i<=n;i++) {
		scanf("%d",&p[i].b);
	}
	sort(p+1,p+n+1,cmpb);
	oo=0;
	for(i=1;i<=n;i++) {
		oo+=p[i].b;
		if(oo>=jyl)
			break;
	}
	jc=i;
	printf("%d ",jc);
	int o=0;
	memset(dp,63,sizeof dp);
	dp[o][0][10000]=0;
	for(i=1;i<=n;i++) {
		o^=1;
		memset(dp[o],63,sizeof dp[o]);
		for(j=0;j<=20000;j++) {
			for(k=i-1;k>=0;k--) {
				dp[o][k+1][j+p[i].b-p[i].a]=min(dp[o][k+1][j+p[i].b-p[i].a],dp[o^1][k][j]);
				if(j>=p[i].a) {
					dp[o][k][j-p[i].a]=min(dp[o][k][j-p[i].a],dp[o^1][k][j]+p[i].a);				
				}
			}
		}
	}
	wwx=1e9+7;
	for(i=10000;i<=20000;i++) {
		wwx=min(wwx,dp[o][jc][i]);
	}
	printf("%d\n",wwx);
    return 0;
}
bool cmpb(node pp,node qq) {
	return pp.b>qq.b;
}
/*
10
18 42 5 1 26 8 40 34 8 29
18 71 21 67 38 13 99 37 47 76
*/
