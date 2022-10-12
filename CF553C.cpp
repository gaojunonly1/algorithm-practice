#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,m;
struct DSU {
	int n;
	int f[100005],g[100005];
	DSU() {
		n=0;
	}
	DSU(int oo) {
		n=oo;
		for(int i=1;i<=n;i++) {
			f[i]=i;
			g[i]=0;
		}
	}
	int Find(int x) {
		if(x==f[x])
			return x;
		int oo=f[x];
		f[x]=Find(f[x]);
		g[x]=(g[x]+g[oo])%2;
		return f[x];
	}
	//val[x]=val[y]+oo
	void Merge(int x,int y,int oo) {
		int fx=Find(x);
		int fy=Find(y);
		if(fx!=fy) {
			f[fx]=fy;
			g[fx]=(g[y]-oo-g[x]+4)%2;
		}
	}
};
const ll Mod=1000000007;
ll ksm(ll x,int y);
int main() {
	int i,j,k;
	int oo,pp,qq;
	scanf("%d%d",&n,&m);
	DSU D(n);
	bool jyl=1;
	for(i=1;i<=m;i++) {
		scanf("%d%d%d",&pp,&qq,&oo);
		int fx=D.Find(pp),fy=D.Find(qq);
		if(fx==fy) {
			if((D.g[pp]^D.g[qq])==oo) {
				jyl=0;
				break;
			}
		}
		else
			D.Merge(pp,qq,oo^1);
	}
	if(0==jyl) {
		printf("0\n");
		return 0;
	}
	int wwx=0;
	for(i=1;i<=n;i++)
		if(D.Find(i)==i)
			wwx++;
	printf("%lld\n",ksm(2,wwx-1));
    return 0;
}
ll ksm(ll x,int y) {
	ll jyl=1;
	while(y) {
		if(y&1)
			jyl=jyl*x%Mod;
		x=x*x%Mod;
		y>>=1;
	}
	return jyl;
}
