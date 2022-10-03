#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,a,b;
int dp[105][105][2];
void solve();
int dfs(int a,int b,int o); //the number of odd is a, the number of even is b
int main() {
	int T;
	scanf("%d",&T);
	memset(dp,-1,sizeof dp);
	while(T--)
		solve();
    return 0;
}
void solve() {
	int i,j,k;
	int oo,pp,qq;
	scanf("%d",&n);
	a=b=0;
	for(i=1;i<=n;i++) {
		scanf("%d",&oo);
		if(oo&1)
			a++;
		else
			b++;
	}
	if(dfs(a,b,0))
		printf("Alice\n");
	else
		printf("Bob\n");
}
int dfs(int a,int b,int o) {
	if(~dp[a][b][o])
		return dp[a][b][o];
	if(a==0)
		return dp[a][b][o]=o^1;
	if(b==0)
		return dp[a][b][o]=((a+1)/2)%2==0?o^1:o;
	dp[a][b][o]=(a>=2?dfs(a-2,b,o^1):1)&dfs(a-1,b-1,o^1);
	dp[a][b][o]|=(b>=2?dfs(a,b-2,o):1)&dfs(a-1,b-1,o);
	return dp[a][b][o];
}
