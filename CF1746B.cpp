#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
int n,a[100005];
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
	int r=n,l=1;
	while(a[l]==0)
		l++;
	while(a[r]==1)
		r--;
	int wwx=0;
	while(l<r) {
		swap(a[l],a[r]);
		wwx++;
		while(a[l]==0) {
			l++;
		}
		while(a[r]==1) {
			r--;
		}
	}
	printf("%d\n",wwx);
}
