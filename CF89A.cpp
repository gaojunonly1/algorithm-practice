#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
ll m,K;
ll a[10005];
int main() {
	int i,j,k;
	ll oo,pp,qq;
	scanf("%d%lld%lld",&n,&m,&K);
	ll jyl=1e9+7;
	for(i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		if(i&1)
			jyl=min(jyl,a[i]);
	}
	ll wwx=0;
	oo=n/2;
	if(n&1) {
		wwx=min(jyl,m/(oo+1)*K);
	}
	printf("%lld\n",wwx);
    return 0;
}
