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
int main() {
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	ll n,d,m,l;
	scanf("%lld%lld%lld%lld",&n,&d,&m,&l);
	ll pos=0;
	for(ll i=1;i<=n;i++) {
		if(pos<(i-1)*m) {
			printf("%lld\n",pos);
			return 0;;
		}
		else {
			if(pos<=(i-1)*m+l) {
				pos+=((i-1)*m+l-pos+d)/d*d;
			}
		}
	}
	printf("%lld\n",pos);
    return 0;
}
