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

const int N1=5005;

ll dp[N1];
ll p[5],t[5];
ll h,s;

bool check(ll tim);

int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int oo,pp,qq;
	ll o,q;
	
	scanf("%lld%lld",&p[1],&t[1]);
	scanf("%lld%lld",&p[2],&t[2]);
	scanf("%lld%lld",&h,&s);
	
	fill(dp,dp+h+1,inf);
	dp[0]=0;
	fz0g(i,h) {
		if(dp[i]==inf)
			continue;
		dp[min(h,i+p[1]-s)]=min(dp[min(h,i+p[1]-s)],dp[i]+t[1]);
		dp[min(h,i+p[2]-s)]=min(dp[min(h,i+p[2]-s)],dp[i]+t[2]);
		fz1(j,h) {
			if(j*t[1]>=t[2]) {
				o=(j-1)*(p[1]-s)+((j*t[1])/t[2]-1)*(p[2]-s)+p[1]+p[2]-s;
				dp[min(h,i+o)]=min(dp[min(h,i+o)],dp[i]+j*t[1]);
			}
			if(j*t[2]>=t[1]) {
				o=(j-1)*(p[2]-s)+((j*t[2])/t[1]-1)*(p[1]-s)+p[1]+p[2]-s;
				dp[min(h,i+o)]=min(dp[min(h,i+o)],dp[i]+j*t[2]);
			}
		}
	}
	printf("%lld\n",dp[h]);
    return 0;
}
