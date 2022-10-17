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
int wwx[N1];
struct Edge {
	int u,v;
	int id;
}jyl[N1];
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
	bool Merge(int x,int y) {
		int fx=Find(x);
		int fy=Find(y);
		if(fx!=fy) {
			f[fx]=fy;
			return 1;
		}
		return 0;
	}
};
void solve();
int n,m;
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
	int i,j;
	int u,v;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++) {
		scanf("%d%d",&jyl[i].u,&jyl[i].v);
		jyl[i].id=i;
	}
	for(i=1;i<=10;i++) {
		random_shuffle(jyl+1,jyl+m+1);
		bool flg=1;
		DSU D1(n);
		DSU D2(n);
		for(j=1;j<=m;j++) {
			u=jyl[j].u;
			v=jyl[j].v;
			if(D1.Merge(u,v)) {
				wwx[jyl[j].id]=0;
			}
			else {
				if(0==D2.Merge(u,v)) {
					flg=0;
					break;
				}
				else {
					wwx[jyl[j].id]=1;
				}
			}
		}
		if(flg==1) {
			for(j=1;j<=m;j++)
				printf("%d",wwx[j]);
			printf("\n");
			return;
		}
	}
}
