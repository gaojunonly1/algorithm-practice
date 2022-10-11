#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
int a[100005];
vector<int>jyl[100005];
int wwx[100005];
int main() {
	int i,j,k;
	ll oo,pp,qq;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",&oo);
		a[i]=oo;
		jyl[oo].pb(i);
	}
	for(i=2;i<=100000;i++)
		if(jyl[i].size()>jyl[i-1].size()) {
			printf("-1\n");
			return 0;
		}
	printf("%d\n",jyl[1].size());
	fill(wwx+1,wwx+n+1,0);
	for(i=1;i<=n;i++) {
		++wwx[a[i]];
		printf("%d ",wwx[a[i]]);
	}
	printf("\n");
    return 0;
}
