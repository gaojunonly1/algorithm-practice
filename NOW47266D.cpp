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

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
#endif
	int i,j,k;
	int oo,pp,qq;
	ll o,p,q;
	
	int T,m;
	ll n;
	scanf("%d",&T);
	while(T--) {
		scanf("%lld%d%d",&n,&k,&m);
		ll x;
		fz1(i,m) {
			scanf("%lld",&x);
			if(k==1) {
				printf("%lld\n",n-x);
			}
			else {
				ll syf=1,l1=x*k+1,r1=min(n-1,x*k+k);
				while(l1<n) {
					syf+=r1-l1+1;
					l1=l1*k+1;
					r1=min(n-1,r1*k+k);
				}
				printf("%lld\n",syf);
			}
		}
	} 

    return 0;
}
