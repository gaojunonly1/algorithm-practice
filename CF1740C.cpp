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

int n;
struct node {
	ll a;
	ll syf;
	bool operator<(const node tmp)const {
		return a<tmp.a;
	}
}jyl[N1];
ll mx1[N1],mx2[N1];

void solve();

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
	int i,j;
	int n;
	scanf("%d",&n);
	fz1(i,n) {
		scanf("%lld",&jyl[i].a);
	}
	sort(jyl+1,jyl+n+1);
	fz(i,2,n) {
		jyl[i].syf=jyl[i].a+jyl[i].a-jyl[i-1].a;
	}
	mx1[n+1]=mx2[n+1]=-inf;
	fd(i,n,2) {
		mx1[i]=max(mx1[i+1],jyl[i].a);
		mx2[i]=max(mx2[i+1],jyl[i].syf);
	}
	ll gj=-inf;
	fz1(i,n-2) {
		gj=max(gj,mx2[i+2]-jyl[i].a);
		gj=max(gj,jyl[i+1].a-jyl[i].a+mx1[i+2]-jyl[i].a);
	}
	printf("%lld\n",gj);
}
