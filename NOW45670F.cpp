#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
#define iinf INT_MAX

const ll Mod=1000000007;

const int N1=1000005;

ll fac[N1];

ll ksm(ll x,ll y);

int main() {
//	freopen("test.in","r",stdin);
	ll i,j,k;
	int oo,pp,qq;
	ll o,p,q;
	
	fac[0]=1;
	fz1(i,100000) {
		fac[i]=fac[i-1]*i%Mod;
	}
	ll inv4=ksm(4,Mod-2),inv2=ksm(2,Mod-2);
	int T;
	scanf("%d",&T);
	while(T--) {
		ll n;
		scanf("%lld",&n);
		ll syf=0;
		fz1(i,n) {
			o=(n-i+1)*(n-i+2)%Mod*inv2%Mod;
			(o*=i)%=Mod;
			(syf+=o)%=Mod;
		}
//		cout<<"syf="<<syf<<endl;
		ll gj=fac[n]*n%Mod*(n-1)%Mod*inv4%Mod;
		syf*=gj;
		syf%=Mod;
		printf("%lld\n",syf);
	}

    return 0;
}

ll ksm(ll x,ll y) {
	ll jyl=1;
	while(y) {
		if(y&1) {
			jyl=jyl*x%Mod;
		}
		x=x*x%Mod;
		y>>=1;
	}
	return jyl;
}
