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
vector<pii>wwx;
void solve();
void CSH();
void play(int o);
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		solve();
	}
    return 0;
}
void solve() {
	CSH();
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	play(a[1]&1);
	printf("%d\n",wwx.size());
	for(auto oo:wwx)
		printf("%d %d\n",oo.fi,oo.se);
	return;
}
void CSH() {
	wwx.clear();
	wwx.resize(0);
	return;
}
void play(int o) {
	int i,j,k;
	int oo=1,pp,qq;
	pp=a[1];
	qq=1;
	for(i=2;i<=n;i++)
		if((o==(a[i]&1))&&a[i]<pp) {
			pp=a[i];
			qq=i;
		}
	if(qq!=1) {
		wwx.pb(mp(1,qq));
		a[1]=pp;
	}
	for(i=2;i<=n;i++)
		if(o!=(a[i]&1)) {
			wwx.pb(mp(1,i));
			a[i]=pp;
			oo=i;
		}
	for(i=2;i<oo;i++)
		if(o==(a[i]&1)&&a[i]!=pp){
			wwx.pb(mp(i,oo));
			a[i]=pp;
		}
	pp=0;
	for(i=n-1;i>=oo+1;i--)
		if(a[i]>a[i+1]) {
			pp=i;
			break;
		}
	if(0!=pp) {
		wwx.pb(mp(pp,pp+1));
		a[pp]=a[pp+1];
		for(i=oo+1;i<pp;i++)
			wwx.pb(mp(i,pp));
	}
	return;
}
