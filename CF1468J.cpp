#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
#define iinf INT_MAX

const int N1=200005;
const int M1=200005;

void solve();

struct Edge {
	int u,v;
	ll w;
	bool operator<(const Edge tmp)const  {
		return w<tmp.w;
	}
}e[M1];

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
};

int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	
	int T;
	scanf("%d",&T);
	while(T--) {
		solve();
	}

    return 0;
}

void solve() {
	int i;
	int n,m;
	ll K;
	scanf("%d%d%lld",&n,&m,&K);
	fz1(i,m) {
		scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	sort(e+1,e+m+1);
	DSU D(n);
	ll gj=0;
	fz1(i,m) {
		int fu=D.Find(e[i].u),fv=D.Find(e[i].v);
		if(fu==fv) {
			continue;
		}
		D.Merge(e[i].u,e[i].v);
		if(e[i].w>K) {
			gj+=e[i].w-K;
		}
	}
	ll syf=K;
	fz1(i,m) {
		syf=min(syf,abs(e[i].w-K));
	}
	if(gj==0) {
		printf("%lld\n",syf);
	}
	else {
		printf("%lld\n",gj);
	}
}
