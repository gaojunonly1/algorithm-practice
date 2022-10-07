#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,m;
vector<pii>jyl[4][200005];
int w[100005];
int wwx[10];
int main() {
	int i,j,k;
	int oo,pp,qq;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++) {
		scanf("%d%d",&oo,&pp);
		jyl[0][oo].pb(mp(pp,i));
		jyl[1][pp].pb(mp(oo,i));
		jyl[2][oo+pp].pb(mp(oo,i));
		jyl[3][oo-pp+n].pb(mp(pp,i));
	}
	for(i=0;i<4;i++) {
		for(j=1;j<=n*2;j++) {
			if(0==jyl[i][j].size())
				continue;
			sort(jyl[i][j].begin(),jyl[i][j].end());
			if(jyl[i][j].size()>1) {
				for(k=1;k<jyl[i][j].size()-1;k++)
					w[jyl[i][j][k].se]+=2;
				w[jyl[i][j][0].se]++;
				w[jyl[i][j][jyl[i][j].size()-1].se]++;
			}
		}
	}
	for(i=1;i<=m;i++)
		wwx[w[i]]++;
	for(i=0;i<=8;i++)
		printf("%d ",wwx[i]);
	printf("\n");
    return 0;
}
