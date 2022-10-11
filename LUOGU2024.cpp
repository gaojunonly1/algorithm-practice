#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,m;
int wwx=0;
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
		g[x]=(g[x]+g[oo])%3;
		return f[x];
	}
	//val[x]=val[y]+oo
	void Merge(int x,int y,int oo) {
		int fx=Find(x);
		int fy=Find(y);
		if(fx!=fy) {
			f[fx]=fy;
			g[fx]=(g[y]-oo-g[x]+6)%3;
		}
	}
}D;
int main() {
	int i,j,k;
	int oo,pp,qq;
	scanf("%d%d",&n,&m);
	DSU D(n);
	for(i=1;i<=m;i++) {
		scanf("%d%d%d",&oo,&pp,&qq);
		if(pp>n||qq>n) {
			wwx++;
			continue;
		}
		if(1==oo) {
			if(D.Find(pp)==D.Find(qq)) {
				pp=D.g[pp]; qq=D.g[qq];
				if(pp!=qq)
					wwx++; 
			}
			else
				D.Merge(pp,qq,0);
		}
		else {
			if(pp==qq) {
				wwx++;
				continue;
			}
			else {
				if(D.Find(pp)==D.Find(qq)) {
					if(D.g[qq]!=(D.g[pp]+1)%3)
						wwx++;
				}
				else {
					D.Merge(pp,qq,1);
				}
			}
		}
	}
	printf("%d\n",wwx);
    return 0;
}
