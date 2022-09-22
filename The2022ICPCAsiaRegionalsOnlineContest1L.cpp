#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int sn,tn;
char s[500005],t[500005];
bool jzjc[30][30];
bool vis[30];
int dp[500005][30];
int main() {
	int i,j,k;
	scanf("%s%s",s+1,t+1);
	sn=strlen(s+1);
	tn=strlen(t+1);
	memset(vis,0,sizeof vis);
	memset(jzjc,0,sizeof jzjc);
	for(i=tn;i>=1;i--) {
		for(j=1;j<=26;j++)
			if(1==vis[j])
				jzjc[t[i]-'a'+1][j]=1;
		vis[t[i]-'a'+1]=1;
	}
	dp[0][0]=0;
	for(i=1;i<=sn;i++) {
		for(j=0;j<=26;j++)
			dp[i][j]=max(dp[i][j],dp[i-1][j]);
		if(0==vis[s[i]-'a'+1]) {
			for(j=1;j<=26;j++)
				dp[i][j]=max(dp[i][j],dp[i-1][j]+1);
			dp[i][0]=max(dp[i][0],dp[i-1][0]+1);
			continue;
		}
		for(j=1;j<=26;j++)
			if(0==jzjc[j][s[i]-'a'+1])
				dp[i][s[i]-'a'+1]=max(dp[i][s[i]-'a'+1],dp[i-1][j]+1);
		dp[i][s[i]-'a'+1]=max(dp[i][s[i]-'a'+1],dp[i-1][0]+1);
	}
	int wwx=0;
	for(i=0;i<=26;i++)
		wwx=max(wwx,dp[sn][i]);
	printf("%d\n",wwx);
    return 0;
}
