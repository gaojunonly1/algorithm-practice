#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
const int N1=200005;
int n;
int a[N1];
int wwx[N1];
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
	set<int>jyl;
	for(i=1;i<=n;i++) {
		jyl.insert(i);
		wwx[i]=1;
	}
	for(i=2;i<=n;i++) {
		if(a[i]<a[i-1]) {
			auto it=jyl.lower_bound(a[i-1]-a[i]);
//			cout<<"num="<<*it<<endl;
			wwx[*it]=i;
			jyl.erase(it);
		}
	}
	for(i=1;i<=n;i++)
		printf("%d ",wwx[i]);
	printf("\n");
}
