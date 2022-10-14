#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,m,v;
vector<pii>wwx;
int main() {
	int i,j,k;
	ll oo,pp,qq;
	scanf("%d%d%d",&n,&m,&v);
	if(m<n-1) {
		printf("-1\n");
		return 0;
	}
	if(v==1)
		oo=2;
	else
		oo=1;
	for(i=1;i<=n&&m>0;i++) {
		if(i==v)
			continue;
		wwx.pb(mp(v,i));
		m--;
	}
	for(i=1;i<=n&&m>0;i++) {
		if(i==v||i==oo)
			continue;
		for(j=i+1;j<=n&&m>0;j++) {
			if(j==v||j==oo)
				continue;
			wwx.pb(mp(i,j));
			m--;
		}
	}
	if(m>0)
		printf("-1\n");
	else {
		for(auto tmp:wwx) {
			printf("%d %d\n",tmp.fi,tmp.se);
		}
	}
    return 0;
}
