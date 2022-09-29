#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const ll Mod=1000000007;
int dp[1005][11][11][2][2][2];
char l1[1005],r1[1005];
int n;
int a[1005];
ll solve(char *s);
ll dfs(int pos,int las1,int las2,bool ok,bool qd0,bool limit);
int main() {
	scanf("%s%s",l1+1,r1+1);
	ll wwx=(solve(r1)-solve(l1)+Mod)%Mod;
	int i;
	for(i=2;i<=strlen(l1+1);i++)
		if(l1[i]==l1[i-1]||i>=3&&l1[i]==l1[i-2]) {
			(wwx+=1)%=Mod;
			break;
		}
	printf("%lld\n",wwx);
    return 0;
}
ll solve(char *s) {
	int i,j,k,L;
	n=strlen(s+1);
	for(i=1;i<=n;i++)
		a[i]=(int)s[i]-'0';
	memset(dp,-1,sizeof dp);
	return dfs(1,10,10,0,1,1);
}
ll dfs(int pos,int las1,int las2,bool ok,bool qd0,bool limit) {
	if(pos>n)
		return ok;
	if(~dp[pos][las1][las2][ok][qd0][limit])
		return dp[pos][las1][las2][ok][qd0][limit];
	int i;
	ll jyl=0;
	for(i=0;i<=9;i++) {
		if(i<=a[pos]||0==limit) {
			if(qd0&&i==0)
				(jyl+=1ll*dfs(pos+1,las1,las2,ok,qd0&&i==0,limit&&i==a[pos]))%=Mod;
			else
				(jyl+=1ll*dfs(pos+1,las2,i,ok||(i==las1||i==las2),0,limit&&i==a[pos]))%=Mod;
		}
	}
	return dp[pos][las1][las2][ok][qd0][limit]=jyl;
}
