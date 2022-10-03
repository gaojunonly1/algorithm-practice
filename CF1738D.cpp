#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,b[100005];
int k;
int a[100005];
void solve();
int main() {
	int T; 
	scanf("%d",&T);
	while(T--)
		solve(); 
    return 0;
}
void solve() {
	int i;
	int oo,pp,qq;
	scanf("%d",&n);
	vector<int>jyl[n+2];
	for(i=1;i<=n;i++) {
		scanf("%d",&b[i]);
		jyl[b[i]].pb(i);
	}
	k=0;
	for(i=1;i<=n;i++)
		if(b[i]>i)
			k++;
	printf("%d\n",k);
	vector<int>wwx;
	oo=jyl[0].size()?0:n+1;
	while(true) {
		pp=-1;
		for(auto o:jyl[oo]) {
			if(jyl[o].size())
				pp=o;
			else
				wwx.pb(o);
		}
		if(-1!=pp) {
			wwx.pb(pp);
			oo=pp;
		}
		else
			break;
	}
	for(auto o:wwx)
		printf("%d ",o);
	printf("\n");
}
