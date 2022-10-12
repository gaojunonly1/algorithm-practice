#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,a[200005];
void solve();
int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	ll oo,pp,qq;
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
    return 0;
}
void solve() {
	int r1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	r1=1;
	ll wwx=0;
	for(int i=1;i<=n;i++) {
		for(int j=r1;j<=n;j++) {
			if(a[j]<j-i+1) {
				r1=j-1;
				wwx+=1ll*(r1-i+1);
				break;
			}
			if(j==n) {
				r1=n;
				wwx+=1ll*(r1-i+1);
				break;
			}
		}
	}
	printf("%lld\n",wwx);
}
