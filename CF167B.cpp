#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
const int N1=205;
int n,l,K;
double p[N1];
double dp[N1][N1][N1<<1];
int main() {
	freopen("test.in","r",stdin);
	int i,j,k;
	int o,q;
	ll oo,pp,qq;
	scanf("%d%d%d",&n,&l,&K);
	for(i=1;i<=n;i++) {
		scanf("%lf",&p[i]);
		p[i]*=0.01;
	}
	dp[0][0][K+200]=1;
	for(i=1;i<=n;i++) {
		scanf("%d",&o);
		for(j=0;j<=i-1;j++)
			for(k=0;k<=401;k++) {
				dp[i][j][k]+=dp[i-1][j][k]*(1-p[i]);
				dp[i][j+1][min(401,k+o)]+=dp[i-1][j][k]*p[i];
			}
	}
	double wwx=0;
	for(i=l;i<=n;i++)
		for(j=200;j<=401;j++) {
			wwx+=dp[n][i][j];
//			if(dp[n][i][j])
//				cout<<i<<" "<<j<<" "<<dp[n][i][j]<<endl;
		}
	printf("%.6lf\n",wwx);
    return 0;
}
