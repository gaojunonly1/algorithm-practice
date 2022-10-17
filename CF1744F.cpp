#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
const int N1=200005;
int n,a[N1],pos[N1];
void solve();
int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
    return 0;
}
void solve() {
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		pos[a[i]]=i;
	}
	int pl=pos[0],pr=pos[0];
	ll wwx=0;
	set<int>jyl;
	for(i=1;i<=n+1;i++)
		jyl.insert(i);
	ll pp,qq,oo;
	int len;
	for(int mex=1;mex<=n;) {
		if(mex==n) {
			wwx++;
			break;
		}
		len=pr-pl+1;
		pp=(pos[mex]<pl)?(pos[mex]+1):1;
		qq=(pos[mex]>pr)?(pos[mex]-1):n;
		pp=pl-pp;
		qq=qq-pr;
		oo=mex*2-len;
		if(oo>=0) {
//			for(int i=0;i<=min(oo,pp);i++) {
//				wwx+=(min(oo-i,qq)+1);
//			}
			//oo-i>=qq
			if(oo-qq>=0) {
				wwx+=(qq+1)*(min(oo-qq,min(oo,pp))+1);
			}
			//oo-i<qq  i=[oo-qq+1,min(oo,pp)]
			if(oo-qq+1<=min(oo,pp)) {
				ll g1=max(0ll,oo-qq+1);
				ll g2=min(oo,pp);
				ll sx=oo-g2+1;
				ll wx=oo-g1+1;
				ll xs=g2-g1+1;
				wwx+=(sx+wx)*xs/2;
			}
		}
		if(pos[mex]>pr) {
			pr++;
			while(a[pr]!=mex) {
				jyl.erase(a[pr]);
				pr++;
			}
			jyl.erase(a[pr]);
		}
		else if(pos[mex]<pl) {
			pl--;
			while(a[pl]!=mex) {
				jyl.erase(a[pl]);
				pl--;
			}
			jyl.erase(a[pl]);
		}
		mex=(*jyl.begin());
	}
	printf("%lld\n",wwx);
}
