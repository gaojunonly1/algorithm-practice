#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,k;
int a[105];
int main() {
	int i,j;
	int T;
	ll oo,pp,qq;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		ll wwx=0;
		for(i=1;i<=k;i++) {
			oo=0;
			for(j=i;j<=n;j+=k)
				oo=max(oo,1ll*a[j]);
			wwx+=oo;
		}
		printf("%lld\n",wwx);
	} 
    return 0;
}
