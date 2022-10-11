#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
char s[105];
ll dp[105][3005];
const ll Mod=1000000007; 
void solve();
ll dfs(int n,int m);
int main() {
	int i,j,k;
	ll oo,pp,qq;
	memset(dp,-1,sizeof dp);
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
    return 0;
}
void solve() {
	int i,j,k;
	int jyl=0;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++)
		jyl+=(int)(s[i]-'a');
	printf("%lld\n",(dfs(n,jyl)+Mod-1)%Mod);
}
ll dfs(int n,int m) {
	if(n==0)
		return m==0?1:0;
	if(-1!=dp[n][m])
		return dp[n][m];
	int i,oo=min(25,m);
	ll jyl=0;
	for(i=0;i<=oo;i++) {
		(jyl+=dfs(n-1,m-i))%=Mod;
	}
	return dp[n][m]=jyl;
}
