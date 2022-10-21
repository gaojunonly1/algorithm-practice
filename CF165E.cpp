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
const int N1=1000005;
int n;
int a[N1];
int bin[25];
int dp[(1<<23)+5];
int main() {
	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	scanf("%d",&n);
	memset(dp,-1,sizeof dp);
	for(i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		dp[a[i]]=a[i];
	}
	bin[0]=1;
	for(i=1;i<=22;i++)
		bin[i]=bin[i-1]<<1;
	for(i=0;i<bin[22];i++) {
		if(dp[i]!=-1)
			continue;
		for(j=0;j<22;j++) {
			if(((i>>j)&1)&&(dp[i^bin[j]]!=-1)) {
				dp[i]=dp[i^bin[j]];
				break;
			}
		}
	}
	for(i=1;i<=n;i++) {
		int oo=bin[22]-1-a[i];
		printf("%d ",dp[oo]);
	}
    return 0;
}
