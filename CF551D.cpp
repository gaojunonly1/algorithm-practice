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
ll mod;
struct node {
	ll a,b;
	node(ll aa=0,ll bb=0) {
		a=aa;
		b=bb;
	}
};
node feibo(ll oo);
ll ksm(ll x,ll y);
ll sqr(ll x);
int main() {
//	freopen("test.in","r",stdin);
	int i,j;
	int o,p,q;
	ll oo,pp,qq;
	
	ll n,k,l1;
	scanf("%lld%lld%lld%lld",&n,&k,&l1,&mod);
	if((l1<=63)&&(k>>l1)) {
		printf("0\n");
		return 0;
	}
	node tmp=feibo(n);
	pp=(tmp.a+tmp.b)%mod;
	qq=(ksm(2,n)-pp+mod)%mod;
//	cout<<"pp="<<pp<<" "<<"qq="<<qq<<endl;
	ll wwx=1;
	for(ll i=0;i<l1;i++){
		if((k>>i)&1ll) {
			wwx=wwx*qq%mod;
		}
		else {
			wwx=wwx*pp%mod;
		}
	}
	printf("%lld\n",wwx%mod);
    return 0;
}
node feibo(ll oo) {
	if(oo==0) {
		return node(0,1);
	}
	if(oo==1) {
		return node(1,1);
	}
	node tmp=feibo(oo>>1);
	ll a=tmp.a*(2ll*tmp.b%mod-tmp.a+mod)%mod;
	ll b=(sqr(tmp.a)+sqr(tmp.b))%mod;
	if(oo&1) {
		return node(b,a+b);
	}
	else {
		return node(a,b);
	}
}
ll sqr(ll x) {
	return x*x%mod;
}
ll ksm(ll x,ll y) {
	ll jyl=1;
	while(y) {
		if(y&1)
			jyl=jyl*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return jyl;
}
