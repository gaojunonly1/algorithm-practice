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
int num[N1];
ll a,b;
ll dp[N1][3];
void get(int num,set<int> &oo);
ll solve(int gg);
int main() {
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	scanf("%d%lld%lld",&n,&a,&b);
	for(i=1;i<=n;i++)
		scanf("%d",&num[i]);
	set<int>jyl;
	get(num[1]-1,jyl);
	get(num[1],jyl);
	get(num[1]+1,jyl);
	get(num[n]-1,jyl);
	get(num[n],jyl);
	get(num[n]+1,jyl);
	ll wwx=inf;
	for(auto oo:jyl) {
		wwx=min(wwx,solve(oo));
	}
	printf("%lld\n",wwx);
    return 0;
}
ll solve(int gg) {
	memset(dp,63,sizeof dp);
	dp[0][0]=dp[0][1]=dp[0][2]=0;
	int i;
	for(i=1;i<=n;i++) {
		if(num[i]%gg==0) {
			dp[i][0]=dp[i-1][0];
			dp[i][2]=min(dp[i-1][1],dp[i-1][2]);
		}
		else if((num[i]+1)%gg==0||(num[i]>1&&(num[i]-1)%gg==0)) {
			dp[i][0]=dp[i-1][0]+b;
			dp[i][2]=min(dp[i-1][1],dp[i-1][2])+b;
		}
		dp[i][1]=min(dp[i-1][0],dp[i-1][1])+a;
	}
	return min(dp[n][0],min(dp[n][1],dp[n][2]));
}
void get(int num,set<int> &oo) {
	for(int i=2;i*i<=num;i++) {
		if(num%i==0) {
			oo.insert(i);
			while(num%i==0) {
				num/=i;
			}
		}
	}
	if(num>1)
		oo.insert(num);
}
