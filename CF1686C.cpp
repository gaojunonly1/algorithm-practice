#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
int a[100005],b[100005];
void solve();
int main() {
	int i,j,k;
	int oo,pp,qq;
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
    return 0;
}
void solve() {
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n&1) {
		printf("NO\n");
		return;
	}
	sort(a+1,a+n+1);
	int cnt=0;
	for(i=1;i<=n/2;i++) {
		b[++cnt]=a[i];
		b[++cnt]=a[i+n/2];
	}
	for(i=1;i<=n;i++)
		if(b[i]==b[i%n+1]) {
			printf("NO\n");
			return;
		}
	printf("YES\n");
	for(i=1;i<=n;i++)
		printf("%d ",b[i]);
	printf("\n");
}
