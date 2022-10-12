#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
int a[200005];
char s[200005];
void solve();
int main() {
	int i,j,k;
	ll oo,pp,qq;
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
    return 0;
}
void solve() {
	int i,j,k;
	int cnt[2]={0};
	int pp=-1,qq=-1;
	scanf("%d",&n);
	scanf("%s",s+1);
	for(i=1;i<=2*n;i++) {
		a[i]=s[i]-'0';
		cnt[a[i]]++;
	}
	if(cnt[a[i]]&1) {
		printf("-1\n");
		return;
	}
	vector<int>wwx;
	int o=0;
	for(i=1;i<=n*2;i+=2) {
		if(a[i]!=a[i+1]) {
			a[i]==o?wwx.pb(i):wwx.pb(i+1);
			o^=1;
		}
	}
	printf("%d ",wwx.size());
	for(auto oo:wwx)
		printf("%d ",oo);
	printf("\n");
	for(i=1;i<=n*2;i+=2)
		printf("%d ",i);
	printf("\n");
}
