#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
char s[1000005];
int n;
ll dp[2][3];
const ll Mod=1000000007;
int main() {
	int i,j,k;
	int oo,pp,qq;
	scanf("%s",s+1);
	n=strlen(s+1);
	int o=0;
	dp[o][1]=dp[o][2]=1;
	for(i=1;i<=n;i++) {
		o^=1;
		memset(dp[o],0,sizeof dp[o]);
		if(s[i]=='?') {
			dp[o][0]=(dp[o^1][0]+dp[o^1][2])%Mod;
			dp[o][1]=(dp[o^1][0]+dp[o^1][1])%Mod;
			dp[o][2]=(dp[o^1][0]+dp[o^1][1])%Mod;
		}
		if(s[i]=='*') {
			dp[o][0]=(dp[o^1][0]+dp[o^1][2])%Mod;
		}
		if(s[i]=='0') {
			dp[o][1]=dp[o^1][1];
		}
		if(s[i]=='1') {
			dp[o][1]=dp[o^1][0];
			dp[o][2]=dp[o^1][1];
		}
		if(s[i]=='2') {
			dp[o][2]=dp[o^1][0];
		}
	}
	ll wwx=0;
	wwx=(dp[o][0]+dp[o][1])%Mod;
    printf("%lld\n",wwx);
	return 0;
}
