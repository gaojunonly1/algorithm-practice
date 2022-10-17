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
const int N1=300005;
const ll Mod=998244353;
int n;
ll dp[N1],dp1[N1],bin[N1];
ll fac[N1],inv[N1];
void solve();
void init();
ll C(ll n,ll m);
ll ksm(ll x,ll y);
int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	int T;
	scanf("%d",&T);
	init();
	while(T--)
		solve();
    return 0;
}
void solve() {
	scanf("%d",&n);
	ll wwx=0;
	for(ll i=0;i<=n/4;i++) {
		ll oo=C(n-2*i,2*i);
		ll pp=dp1[2*i];
		ll qq=dp[n-4*i];
		(wwx+=oo*pp%Mod*bin[i]%Mod*qq%Mod)%=Mod;
	}
	printf("%lld\n",wwx);
}
void init() {
	int i,j,k;
	bin[0]=1;
	for(i=1;i<=300000;i++)
		bin[i]=bin[i-1]*2ll%Mod;
	inv[0]=inv[1]=1;
	for(ll i=2;i<=300000;i++)
		inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
	fac[0]=1;
	for(i=1;i<=300000;i++)
		fac[i]=fac[i-1]*i%Mod;
	dp[0]=dp[1]=1;
	for(i=2;i<=300000;i++) {
		dp[i]=(dp[i-1]+dp[i-2]*(i-1)%Mod)%Mod;
	}
	dp1[0]=dp1[2]=1;
	for(i=4;i<=300000;i+=2) {
		dp1[i]=dp1[i-2];
		(dp1[i]+=dp1[i-4]*C(i-2,2)%Mod*2)%=Mod;
	}
	return;
}
ll C(ll n,ll m) {
	return fac[n]*ksm(fac[m],Mod-2)%Mod*ksm(fac[n-m],Mod-2)%Mod;
}
ll ksm(ll x,ll y) {
	ll jyl=1;
	while(y) {
		if(y&1)
			jyl=jyl*x%Mod;
		x=x*x%Mod;
		y>>=1;
	}
	return jyl;
}
