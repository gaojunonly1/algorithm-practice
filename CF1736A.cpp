#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,a[105],b[105];
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
	int pp=0,qq=0;
	int bo=1,boo=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		pp+=a[i];
	}
	for(i=1;i<=n;i++) {
		scanf("%d",&b[i]);
		qq+=b[i];
		if(a[i]>b[i])
			bo=0;
		if(a[i]<b[i])
			boo=0;
	}
	if(pp==qq) {
		printf("%d\n",1-(bo&boo));
	}
	else if(pp>qq) {
		printf("%d\n",pp-qq+(1-boo));
	}
	else {
		printf("%d\n",qq-pp+(1-bo));
	}
}
