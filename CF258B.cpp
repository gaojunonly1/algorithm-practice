#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
ll Mod=1e9+7;
int n;
int tot=0;
int a[15];
int dp[15][15];
int jyl[15];
ll wwx;
void solve(int num);
int dfs(int now,int gs,int limit,int qd0);
void dfs1(int now,int gs,ll sum);
int main() {
	freopen("test.in","r",stdin);
	int i,j,k;
	ll oo,pp,qq;
	scanf("%d",&n);
	solve(n);
    return 0;
}
void solve(int num) {
	int i;
	while(num) {
		a[++tot]=num%10;
		num/=10;
	}
	memset(dp,-1,sizeof dp);
	for(i=0;i<=tot;i++) {
		jyl[i]=dfs(tot,i,1,1);
	}
	jyl[0]--;
	wwx=0;
	dfs1(1,0,1ll);
	printf("%lld\n",wwx);
}
int dfs(int now,int gs,int limit,int qd0) {
	if(now==0) {
		return (gs==0)?1:0;
	}
	if(!limit&&-1!=dp[now][gs])
		return dp[now][gs];
	int jc=0;
	int oo=limit?a[now]:9;
	for(int i=0;i<=oo;i++) {
		if((gs-(i==4||i==7))>=0)
			jc+=dfs(now-1,gs-(i==4||i==7),limit&&i==a[now],qd0&&i==0);
	}
	if(0==limit)
		dp[now][gs]=jc;
	return jc;
}
void dfs1(int now,int gs,ll sum) {
	if(gs>=tot)
		return;
	if(now>6) {
		for(int i=gs+1;i<=tot;i++) {
			wwx+=1ll*sum*jyl[i]%Mod;
			wwx%=Mod;
		}
		return;
	}
	for(int i=0;i<=tot;i++) {
		if(!jyl[i])
			continue;
		jyl[i]--;
		dfs1(now+1,gs+i,sum*(jyl[i]+1)%Mod);
		jyl[i]++;
	}
}
