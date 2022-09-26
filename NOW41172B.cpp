#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
ll a[100005];
void solve();
int main() {
	solve();
    return 0;
}
void solve() {
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	ll abld=0;
	int wwx=n;
	for(i=2;i<=n;i++) {
		abld+=a[i]-a[i-1];
		if(a[i]==a[i-1])
			wwx--;
	}
	if(n<3) {
		printf("%lld %d\n",abld,n);
		return;
	}
	if(a[1]==a[2])
		wwx++;
	if(a[n-1]==a[n])
		wwx++;
	printf("%lld %d\n",abld,wwx);
	return;
}
