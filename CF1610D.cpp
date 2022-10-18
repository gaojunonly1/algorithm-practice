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
const int N1=200005;
const ll Mod=1000000007;
int n;
ll a[N1];
ll cnt[N1];
ll bin[N1];
ll fac[N1];
ll dp[35];
ll s[35];
ll wwx=0;
ll ksm(ll x,ll y);
ll C(int n,int m);
void init();
int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	scanf("%d",&n);
	init();
	vector<ll>jyl;
	for(i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		if(a[i]%2==0) {
			jyl.pb(a[i]);
			oo=a[i];
			pp=0;
			while(oo%2ll==0) {
				pp++;
				oo/=2;
			}
			cnt[pp]++;
		}
	}
	int odd,even;
	odd=n-jyl.size();
	even=jyl.size();
	wwx=0;
	ll jc=0,jfm=0;
	pp=0;
	for(i=30;i>=1;i--) {
		ll oo=0;
		for(j=2;j<=cnt[i];j+=2) {
			oo=(oo+C(cnt[i],j)*bin[pp]%Mod)%Mod;
		}
		jc=(jc+oo)%Mod;
		pp+=cnt[i];
	}
	(wwx+=jc)%=Mod;
	jc=(bin[n]-bin[even]+Mod)%Mod;
	(wwx+=jc)%=Mod;
	printf("%lld\n",(wwx+Mod)%Mod);
    return 0;
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
void init() {
	ll i;
	bin[0]=1;
	for(i=1;i<=n;i++) {
		bin[i]=bin[i-1]*2ll%Mod;
	}
	fac[0]=1;
	for(i=1;i<=n;i++) {
		fac[i]=fac[i-1]*i%Mod;
	}
}
ll C(int n,int m) {
	return fac[n]*ksm(fac[m],Mod-2)%Mod*ksm(fac[n-m],Mod-2)%Mod;
}
