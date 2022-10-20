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
ll a,b,w,x,c;
int main() {
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	scanf("%lld%lld%lld%lld%lld",&a,&b,&w,&x,&c);
	ll wwx=(w*(c-a)-b+(w-x-1))/(w-x);
	printf("%lld\n",max(0ll,wwx));
    return 0;
}
