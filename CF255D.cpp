#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
ll n,c,x,y;
ll check(ll tim);
ll compute(ll x,ll y,ll tim);
int main() {
	scanf("%lld%lld%lld%lld",&n,&x,&y,&c);
	if(x>y)
		swap(x,y);
	ll l1=0,r1=n+n;
	ll wwx=n*n;
	while(l1<=r1) {
		ll mid=(l1+r1)>>1;
		if(check(mid)>=c) {
			wwx=mid;
			r1=mid-1;
		}
		else
			l1=mid+1;
	}
	printf("%lld\n",wwx);
    return 0;
}
ll check(ll tim) {
	if(0==tim)
		return 1;
	ll abld=0;
	abld=compute(x,y,tim)
		+compute(n-x+1,y,tim)
		+compute(x,n-y+1,tim)
		+compute(n-x+1,n-y+1,tim);
	abld-=min(n,x+tim)-max(1ll,x-tim)+1;
	abld-=min(n,y+tim)-max(1ll,y-tim)+1;
	abld--;
	return abld;
}
ll compute(ll x,ll y,ll tim) {
	if(n-x+n-y<=tim)
		return 1ll*(n-x+1)*(n-y+1);
	ll jyl=1ll*(tim+1)*(tim+2)/2;
	if(x+tim>n)
		jyl-=(x+tim-n)*(x+tim-n+1)/2;
	if(y+tim>n)
		jyl-=(y+tim-n)*(y+tim-n+1)/2;
	return jyl;
}
