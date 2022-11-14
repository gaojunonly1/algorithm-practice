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

const int N1=200005;

int n,m;
ll a[N1];
ll s[N1];

int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int oo,pp,qq;
	ll o,p,q;
	
	ll gj=0;
	scanf("%d%d",&n,&m);
	fz1(i,n) {
		scanf("%lld",&a[i]);
		gj+=a[i];
	}
	sort(a+1,a+n+1);
	s[0]=0;
	fz1(i,n) {
		s[i]=s[i-1]+a[i];
	}
	vector<pii>syf;
	pii tmp;
	tmp.fi=1;
	ll jyl=0;
	fz(i,2,n) {
		if(a[i]==a[i-1]||a[i]==a[i-1]+1) {
			continue;
		}
		else {
			tmp.se=i-1;
			syf.pb(tmp);
			tmp.fi=i;
		}
	}
	tmp.se=n;
	syf.pb(tmp);
	ff(syf,itr) {
		jyl=max(jyl,s[(*itr).se]-s[(*itr).fi-1]);
	}
	if(a[n]==m-1&&a[1]==0&&syf.size()>1) {
		jyl=max(jyl,s[syf[0].se]+s[syf[syf.size()-1].se]-s[syf[syf.size()-1].fi-1]);
	}
	gj-=jyl;
	printf("%lld\n",gj);
    return 0;
}
