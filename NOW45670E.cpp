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

const int N1=1000005;

int n;
int a[N1];

int pcnt=0;
int prim[N1];
bool notp[N1];

struct DSU {
	int n;
	int fa[N1];
	int sz[N1];
	void Init(int n1) {
		int i;
		n=n1;
		fz1(i,n) {
			fa[i]=i;
			sz[i]=1;
		}
	}
	int Getfa(int x) {
		if(x==fa[x])
			return x;
		return fa[x]=Getfa(fa[x]);
	}
	void Union(int x,int y) {
		int x1=Getfa(x),y1=Getfa(y);
		if(x1!=y1) {
			fa[y1]=x1;
			sz[x1]+=sz[y1];
			sz[y1]=0;			
		}
	}
};

DSU D1;

void oula(int mx);

int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int oo,pp,qq;
	ll o,p,q;
	
	scanf("%d",&n);
	fz1(i,n) {
		scanf("%d",&a[i]);
	}
	oula(1000000);
	D1.Init(n);
	fz1(i,n-1) {
		scanf("%d%d",&pp,&qq);
		oo=__gcd(a[pp],a[qq]);
		int gj=0;
		fz1(j,pcnt) {
			if(oo%prim[j]==0) {
				gj++;
			}
			if(gj==0&&prim[j]*prim[j]>oo||gj==1&&prim[j]*2>oo||gj==2) {
				break;
			}
		}
		if(gj>1) {
			D1.Union(pp,qq);
		}
	}
	int syf=0;
	fz1(i,n) {
		syf=max(syf,D1.sz[i]);
	}
	printf("%d\n",syf);
    return 0;
}

void oula(int mx) {
	int i,j;
	notp[1]=1;
	fz(i,2,mx) {
		if(!notp[i]) {
			prim[++pcnt]=i;
		}
		fz1(j,pcnt) {
			if(prim[j]*i>mx)
				break;
			notp[prim[j]*i]=1;
			if(i%prim[j]==0)
				break;
		}
	}
}
