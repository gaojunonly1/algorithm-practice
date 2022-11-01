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

const int N1=2000005;

int a[N1];
ll dp[N1];

int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	
	int n;
	scanf("%d",&n);
	fz1(i,n) {
		scanf("%d",&a[i]);
		dp[a[i]]++;
	}
	for(j=1;j<=100000;j*=10) {
		fz0g(i,999999) {
			if(i/j%10<9) {
				dp[i+j]+=dp[i];
			}
		}
	}
	ll syf=0;
	fz1(i,n) {
		syf+=dp[999999-a[i]];
		ll gj=1;
		o=a[i];
		while(o>0) {
			p=o%10;
			o/=10;
			if(p+p>9) {
				gj=0;
				break;
			}
		}
		syf-=gj;
	}
	printf("%lld\n",syf/2);
    return 0;
}
