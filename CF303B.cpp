#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
ll n,m,sx,sy,a,b;
int main() {
	int i,j,k;
	ll oo,pp,qq;
	scanf("%lld%lld%lld%lld%lld%lld",&n,&m,&sx,&sy,&a,&b);
	ll gg=__gcd(a,b);
	k=min(n/(a/gg),m/(b/gg));
	ll xx=k*a/gg,yy=k*b/gg;
	ll x1,y1,x2,y2;
	x1=sx-(xx+1)/2;
	x2=x1+xx;
	y1=sy-(yy+1)/2;
	y2=y1+yy;
	x1=max(0ll,x1); x2=x1+xx;
	x2=min(n,x2); x1=x2-xx;
	y1=max(0ll,y1); y2=y1+yy;
	y2=min(m,y2); y1=y2-yy;
	printf("%lld %lld %lld %lld\n",x1,y1,x2,y2);
    return 0;
}
