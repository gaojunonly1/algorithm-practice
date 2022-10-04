#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
ll n,m;
ll jyl[1000005];
ll wwx,lwj;
int main() {
	int i,j,k;
	int oo,pp,qq;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++) {
		scanf("%d%d",&oo,&pp);
		jyl[oo]++;
		jyl[pp]++;
	}
	wwx=n*(n-1)*(n-2)/6;
	lwj=0;
	for(i=1;i<=n;i++) {
		if(jyl[i])
			lwj+=1ll*(n-1-jyl[i])*jyl[i];
	}
	lwj>>=1;
	wwx-=lwj;
	printf("%lld\n",wwx);
    return 0;
}
