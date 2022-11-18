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

// for Integers
template <class T> inline void read(T &x) {
    x = 0; int ch = getchar(), f = 0;
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = 1;
        ch = getchar();
    }
    while (ch >='0' && ch <='9') {
        x = (x << 1) + (x << 3) + (ch ^ 48);
        ch = getchar();
    }
    if (f) x = -x;
}

inline void write(__int128 x) {
    if(x>=10) {
    	write(x/10);
	}
	putchar(x%10+'0');
}

const int N1=100005;

int n;
__int128 ec,et,p,s;
__int128 t[N1];
int cnt=0;
__int128 jyl[N1],jyls[N1];

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
#endif
	int i,j,k;
	int oo,pp,qq;
	ll o,q;
	
	scanf("%d",&n);
	read(ec);
	read(et);
	read(p);
	read(s);
	fz1(i,n) {
		read(t[i]);
	}
	if(s<ec) {
		printf("-1\n");
		return 0;
	}
	
	int now=1;
	__int128 syf=0;
	
	jyl[0]=jyls[0]=0;
	
	while(true) {
		syf+=et;
		
		jyl[++cnt]=syf+t[now];
		jyl[cnt+1]=1e17;
		jyls[cnt]=jyls[cnt-1]+jyl[cnt]*p;
		if(now==n) {
			break;
		}
		__int128 l1=0,r1=cnt,wy=1;
		while(l1<=r1) {
			ll mid=(l1+r1)/2;
			if(s+jyl[mid+1]*mid*p-jyls[mid]>=(now+1)*ec) {
				wy=mid;
				r1=mid-1;
			}
			else {
				l1=mid+1;
			}
		}
		l1=jyl[wy]; r1=jyl[wy+1];
		__int128 gj=jyl[wy+1];
		while(l1<=r1) {
			__int128 mid=(l1+r1)/2;
			if(s+mid*wy*p-jyls[wy]>=(now+1)*ec) {
				gj=mid;
				r1=mid-1;
			}
			else {
				l1=mid+1;
			}
		}
		syf=max(syf,gj);
		now++;
	}
	fz1(i,cnt) {
		syf=max(syf,jyl[i]);
	}
	write(syf);
    return 0;
}
