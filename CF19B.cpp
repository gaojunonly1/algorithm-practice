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

const int N1=2005;
struct node {
	int t;
	ll c;
}a[N1];
ll dp[N1][N1<<1];

void Min(ll &x,ll y);

int main() {
	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	
	int n;
	scanf("%d",&n);
	fz1(i,n) {
		scanf("%d%lld",&a[i].t,&a[i].c);
	}
	memset(dp,63,sizeof dp);
	dp[0][n]=0;
	ll wwx=inf;
	fz1(i,n) {
		fd0g(j,2*n) {
			Min(dp[i][min(j+a[i].t+1,2*n)],dp[i-1][j]+a[i].c);
		}
		fz1(j,2*n) {
			Min(dp[i][j],dp[i-1][j]);	
		}
		Min(wwx,dp[i][2*n]);
	}
	printf("%lld\n",wwx);
    return 0;
}
void Min(ll &x,ll y) {
	x=min(x,y);
}
