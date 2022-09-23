#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
ll a[1000005];
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
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	ll wwx=a[n]*3;
	for(i=3;i<=n;i++)
		wwx=min(wwx,a[i]-a[i-2]);
	printf("%lld\n",wwx);
}
