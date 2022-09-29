#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
ll x;
void solve();
int main() {
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
    return 0;
}
void solve() {
	int i;
	ll oo;
	ll wwx=0,jyl=0;
	scanf("%d%lld",&n,&x);
	for(i=1;i<=n;i++) {
		scanf("%lld",&oo);
		wwx+=oo;
		jyl+=(oo+(x-1))/x;
	}
	printf("%lld %lld\n",(wwx+(x-1))/x,jyl);
}
