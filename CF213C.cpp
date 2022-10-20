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
const int N1=305;
int n;
int a[N1][N1];
int dp[N1][N1][N1];
int main() {
	freopen("test.in","r",stdin);
	int i,j,k,L;
	int o,p,q;
	ll oo,pp,qq;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			scanf("%d",&a[i][j]);
		}
	}
	memset(dp,0,sizeof dp);
//	fill(&dp[0][0],&dp[n][n],0);
	for(i=1;i<=n;i++) {
		for(j=1;j<=n;j++) {
			for(k=1;k<=min(n,i+j-1);k++) {
				L=i+j-k;
				int tmp=a[i][j]+a[k][L];
				dp[i][j][k]=-iinf;
				if(i>1||(i==1&&j==1)) {
					if(L>1||(i==1&&j==1)) {
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+tmp);
					}
					if(k>1||(i==1&&j==1)) {
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+tmp);
					}
				}
				if(j>1||(i==1&&j==1)) {
					if(L>1||(i==1&&j==1)) {
						dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+tmp);
					}
					if(k>1||(i==1&&j==1)) {
						dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k-1]+tmp);
					}
				}
				if(i==k&&j==L)
					dp[i][j][k]-=a[i][j];
//				cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
//				if(i==1&&j==2&&k==2)
//					return 0;
			}
		}
	}
	printf("%d\n",dp[n][n][n]);
    return 0;
}
