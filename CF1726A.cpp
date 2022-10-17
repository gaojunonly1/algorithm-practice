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
int n,a[2005];
void solve();
int main() {
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
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
		scanf("%d",&a[i]);
	if(n==1) {
		printf("%d\n",0);
		return;
	}
	int wwx=-iinf;
	for(i=2;i<=n;i++)
		wwx=max(wwx,a[i]-a[1]);
	for(i=1;i<n;i++)
		wwx=max(wwx,a[n]-a[i]);
	for(i=1;i<n;i++)
		wwx=max(wwx,a[i]-a[i+1]);
	printf("%d\n",wwx);
}
