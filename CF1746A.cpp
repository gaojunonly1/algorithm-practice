#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
int n,m;
int a[55];
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
	scanf("%d%d",&n,&m);
	int wwx=0;
	for(i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		wwx|=a[i];
	}
	wwx?printf("YES\n"):printf("NO\n");
}
