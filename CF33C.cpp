#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
int n;
ll a[100005],s[100005];
ll wwx;
int main() {
	int i,j,k;
	ll oo,pp,qq;
	scanf("%d",&n);
	s[0]=0;
	for(i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	ll mn=0,jyl=0;
	for(i=1;i<=n;i++) {
		jyl=max(jyl,s[i]-mn);
		mn=min(mn,s[i]);
	}
	wwx=jyl*2-s[n];
	printf("%lld\n",wwx);
	return 0;
}
