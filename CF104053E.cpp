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

const int N1=500005;

ll n,m;
struct node {
	ll num;
	int id;
	int pos;
	ll syf;
}a[N1];
bool cmpnum(node pp,node qq);
bool cmpid(node pp,node qq);

struct BIT {
	#define lowbit(x) ((x)&(-x))
	int n;
	ll s[N1<<1];
	BIT() {
		n=0;
		memset(s,0,sizeof s);
	}
	void Init(int n1) {
		int i;
		n=n1;
		fz1(i,n) {
			s[i]=0;
		}
	}
	void Add(int x,ll y) {
		while(x<=n) {
			s[x]+=y;
			x+=lowbit(x);
		}
	}
	ll Ask(int x) {
		ll jyl=0;
		while(x>0) {
			jyl+=s[x];
			x-=lowbit(x);
		}
		return jyl;
	}
};

BIT T1;

int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int oo,pp,qq;
	ll o,p,q;
	
	scanf("%lld%lld",&n,&m);
	fz1(i,n) {
		scanf("%lld",&a[i].num);
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmpnum);
	a[1].pos=1;
	fz(i,2,n) {
		if(a[i].num!=a[i-1].num) {
			a[i].pos=a[i-1].pos+1;
		}
		else {
			a[i].pos=a[i-1].pos;
		}
	}
	o=0;
	fz1(i,n) {
		a[i].syf=(i-1)*a[i].num-o;
		o+=a[i].num;
	}
	sort(a+1,a+n+1,cmpid);
	T1.Init(n);
	fz1(i,n) {
		a[i].syf+=T1.Ask(a[i].pos);
		T1.Add(a[i].pos,1);
	}
	fz1(i,n) {
		if(a[i].syf>m-2) {
			a[i].syf=-1;
		}
		printf("%lld\n",a[i].syf);
	}
    return 0;
}
bool cmpnum(node pp,node qq) {
	return pp.num<qq.num;
}
bool cmpid(node pp,node qq) {
	return pp.id<qq.id;
}
