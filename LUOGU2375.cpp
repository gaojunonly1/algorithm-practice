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
const ll Mod=1000000007;

char s[N1];
int fail[N1];
ll dp[N1];

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
	scanf("%s",s+1);
	int n=strlen(s+1);
	fail[0]=fail[1]=0;
	dp[0]=0;
	dp[1]=1;
	j=0;
	fz(i,2,n) {
		while(j&&s[i]!=s[j+1]) {
			j=fail[j];
		}
		if(s[j+1]==s[i]) {
			j++;
		}
		fail[i]=j;
		dp[i]=dp[fail[i]]+1; 
	}
	ll gj=1;
	fd1(i,n) {
		ll syf=i;
		while(syf&&syf>i/2) {
			syf=fail[syf];
		}
		gj=gj*(dp[syf]+1)%Mod;
		ll jyl=syf;
		syf=i;
		while(syf&&syf>i/2) {
			ll oo=syf;
			syf=fail[syf];
			fail[oo]=jyl;
		}
	}
	printf("%lld\n",gj);
}
