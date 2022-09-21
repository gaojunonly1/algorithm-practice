#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
ll x,y;
char sa[5005],sb[5005];
int a[5005],b[5005];
ll dp[5005][5005];
vector<int>jyl;
ll wwx;
void CSH();
void solve();
void solve1();
ll solve2(int l,int r);
int main() {
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
    return 0;
}
void solve() {
	int i;
	scanf("%d%lld%lld",&n,&x,&y);
	scanf("%s%s",sa+1,sb+1);
	for(i=1;i<=n;i++) {
		a[i]=sa[i]-'0';
		b[i]=sb[i]-'0';
	}
	CSH();
	for(i=1;i<=n;i++)
		if(a[i]!=b[i])
			jyl.pb(i);
	if(jyl.size()&1) {
		printf("-1\n");
		return;
	}
	if(x>=y)
		solve1();
	else {
		if(0!=jyl.size())
			wwx=solve2(0,jyl.size()-1);
		printf("%lld\n",wwx);
	}
}
void solve1() {
	int i;
	int oo=jyl.size();
	if(oo>2)
		wwx=1ll*y*oo/2;
	else if(oo==2) {
		bool flg=0;
		for(i=1;i<n;i++)
			if(a[i]!=b[i]&&a[i+1]!=b[i+1]) {
				flg=1;
				break;
			}
		if(flg)
			wwx=min(x,y*2);
		else
			wwx=y;
	}
	printf("%lld\n",wwx);
	return;
}
ll solve2(int l,int r) {
	ll oo=1e18;
	if(-1!=dp[l][r])
		return dp[l][r];
	if(l+1==r)
		return dp[l][r]=min(y,(jyl[r]-jyl[l])*x);
	oo=min(oo,min(y,(jyl[l+1]-jyl[l])*x)+solve2(l+2,r));
	oo=min(oo,min(y,(jyl[r]-jyl[r-1])*x)+solve2(l,r-2));
	oo=min(oo,y+solve2(l+1,r-1));
	return dp[l][r]=oo;
}
void CSH() {
	int i,j;
	wwx=0;
	jyl.erase(jyl.begin(),jyl.end());
	jyl.resize(0);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			dp[i][j]=-1;
	return;
}
