#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,k;
ll a[200005];
ll slm;
int lef,rig;
void solve();
int go_lef();
int go_rig();
signed main() {
	int T;
	scanf("%lld",&T);
	while(T--)	
		solve();
    return 0;
}
void solve() {
	int i,j;
	scanf("%lld%lld",&n,&k);
	lef=rig=k;
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	slm=a[k];
	if(slm<0) {
		printf("NO\n");
		return;
	}
	bool jyl=1;
	ll pp,qq;
	while(true) {
		if(lef==1||rig==n) {
			printf("YES\n");
			return;
		}
		if(0==jyl) {
			pp=qq=slm;
			for(i=lef-1;i>=1;i--) {
				pp+=a[i];
				if(pp<0)
					break;
				else if(i==1) {
					printf("YES\n");
					return;
				}
			}
			for(i=rig+1;i<=n;i++) {
				qq+=a[i];
				if(qq<0)
					break;
				else if(i==n) {
					printf("YES\n");
					return;
				}
			}
			printf("NO\n");
			return;
		}
		jyl=0;
		int slm1=slm;
		int lef1=lef;
		int rig1=rig;
		if(-1!=go_lef()||-1!=go_rig())
			jyl=1;
	}
}
int go_lef() {
	ll fb=slm;
	int fblef=lef;
	int pos=lef;
	ll mx=fb;
	while(fblef>1&&fb+a[fblef-1]>=0) {
		fblef--;
		fb+=a[fblef];
		if(fb>mx) {
			pos=fblef;
			mx=fb;
		}
	}
	if(mx>slm) {
		lef=pos;
		slm=mx;
		return pos;
	}
	else
		return -1;
}
int go_rig() {
	ll fb=slm;
	int fbrig=rig;
	int pos=rig;
	ll mx=fb;
	while(fbrig<n&&fb+a[fbrig+1]>=0) {
		fbrig++;
		fb+=a[fbrig];
		if(fb>mx) {
			pos=fbrig;
			mx=fb;
		}
	}
	if(mx>slm) {
		rig=pos;
		slm=mx;
		return pos;
	}
	else
		return -1;
}
