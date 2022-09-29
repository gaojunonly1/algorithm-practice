#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,m;
int k[300005];
ll c[300005];
void solve();
int main() {
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
    return 0;
}
void solve() {
	int i,j;
	scanf("%d%d",&n,&m);
	ll wwx=0;
	for(i=1;i<=n;i++)
		scanf("%d",&k[i]);
	sort(k+1,k+n+1);
	for(i=1;i<=m;i++)
		scanf("%lld",&c[i]);
	j=1;
	for(i=n;i>=1;i--) {
		if(j<=k[i]&&j<=m) {
			wwx+=c[j];
			j++;
		}
		else
			wwx+=c[k[i]];
	}
	printf("%lld\n",wwx);
}
