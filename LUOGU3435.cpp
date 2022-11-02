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
char s[N1];
int fail[N1];

int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	
	scanf("%d",&n);
	scanf("%s",s+1);
	
	fail[0]=fail[1]=0;
	j=0;
	fz(i,2,n) {
		while(j&&s[i]!=s[j+1]) {
			j=fail[j];
		}
		if(s[i]==s[j+1]) {
			j++;
		}
		fail[i]=j;
	}
	ll syf=0;
	fd1(i,n) {
		ll gj=fail[i];
		while(gj&&fail[gj]) {
			gj=fail[gj];
		}
		if(gj!=0) {
			syf+=i-gj;
		}
		j=i;
		while(j&&j!=gj) {
			int o=j;
			j=fail[j];
			fail[o]=gj;
		}
	}
	printf("%lld\n",syf);
    return 0;
}
