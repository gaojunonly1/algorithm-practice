#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
#define iinf INT_MAX
const int N1=200005;
struct DSU {
	int n;
	int f[N1];
	DSU() {
		n=0;
	}
	DSU(int oo) {
		n=oo;
		for(int i=1;i<=n;i++) {
			f[i]=i;
		}
	}
	int Find(int x) {
		if(x==f[x])
			return x;
		int oo=f[x];
		f[x]=Find(f[x]);
		return f[x];
	}
	void Merge(int x,int y) {
		int fx=Find(x);
		int fy=Find(y);
		if(fx!=fy) {
			f[fx]=fy;
		}
	}
	bool Ask(int x,int y) {
		int fx=Find(x);
		int fy=Find(y);
		return (fx==fy)?1:0;
	}
}D;
int n,Q;
int Next[N1];
int main() {
	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	scanf("%d%d",&n,&Q);
	DSU D(n);
	for(i=1;i<=n;i++)
		Next[i]=i+1;
	while(Q--) {
		scanf("%d%d%d",&o,&p,&q);
		if(o==1) {
			D.Merge(p,q);
		}
		else if(o==2){
			int jyl;
			for(i=p;i<q;i=jyl) {
				jyl=Next[i];
				if(jyl<=q)
					D.Merge(i,jyl);
				Next[i]=Next[q];
			}
		}
		else {
			D.Ask(p,q)?printf("YES\n"):printf("NO\n");
		}
	}
    return 0;
}
