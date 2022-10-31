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

const int N1=100005;

struct hash {
	ll base1=131;
	int n;
	ll has[N1],bin[N1];
	hash() {
		n=0;
		memset(has,0,sizeof has);
		return;
	}
	void Pre(char *s) {
		n=strlen(s+1);
		bin[0]=1ll; has[0]=0;
		for(int i=1;i<=n;i++) {
			bin[i]=bin[i-1]*base1;
			has[i]=(has[i-1]*base1+s[i]);
		}
	}
	ll Get(int l,int r) {
		ll jyl;
		jyl=has[r];
		jyl-=has[l-1]*bin[r-l+1];
		return jyl;
	}
}syf,gj;

char s[N1],t[N1];

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
	scanf("%s",s+1);
	scanf("%s",t+1);
	int sn=strlen(s+1),tn=strlen(t+1);
	syf.Pre(s);
	gj.Pre(t);
	int l1,r1,mid;
	int wwx=0;
	fz1(i,sn-tn+1) {
		int now=1,pos=i,gs=0;
		while(now<=tn&&gs<=3) {
			l1=1; r1=tn-now+1;
			int wyx=0;
			while(l1<=r1) {
				mid=(l1+r1)>>1;
				if(pos+mid-1<=sn&&syf.Get(pos,pos+mid-1)==gj.Get(now,now+mid-1)) {
					wyx=mid;
					l1=mid+1;
				}
				else {
					r1=mid-1;
				}
			}
			now+=wyx;
			if(now<=tn) {
				gs++;
				pos+=wyx+1;
				now++;
			}
		}
		if(now>tn&&gs<=3) {
			wwx++;
		}
	}
	printf("%d\n",wwx);
}
