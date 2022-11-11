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

int a[N1];
int dp[N1];

int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int oo,pp,qq;
	ll o,p,q;
	
	int n;
	scanf("%d%d",&n,&k);
	fz1(i,n) {
		scanf("%d",&a[i]);
	}
	int syf=0;
	fz1(i,n) {
		dp[i]=a[i];
		fz1(j,i-k-1) {
			dp[i]=max(dp[i],dp[j]+a[i]);
		}
		syf=max(syf,dp[i]);
	}
	printf("%d\n",syf);
    return 0;
}
