#include <bits/stdc++.h>

#define int long long

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

const int N1=100005;

int sgn(int x);

struct pot {
	int x,y;
	pot():x(0),y(0){}
	pot(int xx,int yy):x(xx),y(yy){}
	pot operator -(const pot tmp)const {
		pot jyl(x-tmp.x,y-tmp.y);
		return jyl;
	}
	int operator ^(const pot tmp)const {
		return x*tmp.y-y*tmp.x;
	}
	int operator *(const pot tmp)const {
		return x*tmp.x+y*tmp.y;
	}
}p[N1];

void solve();

bool judge(pot a,pot b,pot c,pot d,pot e);

signed main() {
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	
	int T;
	scanf("%lld",&T);
	while(T--) {
		solve();
	}

    return 0;
}

void solve() {
	int i,j,k;
	int n;
	scanf("%lld",&n);
	fz1(i,n) {
		scanf("%lld%lld",&p[i].x,&p[i].y);
	}
	if(n<5) {
		printf("NO\n");
		return;
	}
	int id=-1;
	fz(i,5,n) {
		if(judge(p[1],p[2],p[3],p[4],p[i])) {
			id=i;
			break;
		}
	}
	if(id==-1) {
		printf("NO\n");
		return;
	}
	swap(p[id],p[5]);
	fz1(i,5) {
		vector<pot>v;
		v.clear();
		fz1(j,5) {
			if(j==i)
				continue;
			v.pb(p[i]-p[j]);
		}
		bool flg=0;
		fz0k(j,4) {
			fz0k(k,4) {
				if(j==k)
					continue;
				if(sgn(v[j]^v[k])==0&&sgn(v[j]*v[k])>0) {
					flg=1;
					break;
				}
			}
		}
		if(!flg) {
			printf("YES\n");
			printf("%lld %lld\n",p[i].x,p[i].y);
			fz1(j,5) {
				if(j==i)
					continue;
				printf("%lld %lld\n",p[j].x,p[j].y);
			}
			return;
		}
	}
}

bool judge(pot a,pot b,pot c,pot d,pot e) {
	pot v1=b-a;
	pot v2=c-b;
	pot v3=d-c;
	pot v4=e-d;
	if(sgn(v1^v2)||sgn(v2^v3)||sgn(v3^v4))
		return 1;
	return 0;
}

int sgn(int x) {
	if(x==0)
		return 0;
	if(x<0)
		return -1;
	return 1;
}
