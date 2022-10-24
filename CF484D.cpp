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
ll a[N1];
ll dp[N1];
void Max(ll &x,ll y);
int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	
	int n;
	scanf("%d",&n);
	fz1(i,n) {
		scanf("%lld",&a[i]);
	}
	memset(dp,0,sizeof dp);
	dp[2]=abs(a[1]-a[2]);
	fz(i,3,n) {
		if((a[i]>=a[i-1]&&a[i-1]>=a[i-2])||(a[i]<=a[i-1])&&(a[i-1]<=a[i-2])) {
			Max(dp[i],dp[i-1]+abs(a[i]-a[i-1]));
		}
		else {
			Max(dp[i],dp[i-2]+abs(a[i]-a[i-1]));
			Max(dp[i],dp[i-1]);
		}
	}
	printf("%lld\n",dp[n]);
    return 0;
}
void Max(ll &x,ll y) {
	x=max(x,y);
}
