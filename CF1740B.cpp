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

struct node {
	ll x,y;
	bool operator<(const node tmp)const {
		if(max(x,y)!=max(tmp.x,tmp.y))
			return max(x,y)>max(tmp.x,tmp.y);
		return min(x,y)>min(tmp.x,tmp.y);
	}
}a[N1];

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
	int i,j,k;
	int n;
	scanf("%d",&n);
	fz1(i,n) {
		scanf("%lld%lld",&a[i].x,&a[i].y);
	}
	if(n==1) {
		printf("%lld\n",2*(a[1].x+a[1].y));
		return;
	}
	sort(a+1,a+n+1);
	ll syf=max(a[1].x,a[1].y);
	ll gj=0;
	fz(i,2,n) {
		gj+=min(a[i].x,a[i].y)*2;
	}
	gj+=2*(a[1].x+a[1].y);
	printf("%lld\n",gj);
}
