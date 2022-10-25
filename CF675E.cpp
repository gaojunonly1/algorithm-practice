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
int a[N1];
ll dp[N1]; 
int main() {
	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	
	int n;
	scanf("%d",&n);
	fz1(i,n-1) {
		scanf("%d",&a[i]);
	}
	ll wwx;
	dp[n-1]=wwx=1;
	vector<int>jyl;
	jyl.pb(n-1);
	fd1(i,n-2) {
		int o=*(upper_bound(jyl.rbegin(),jyl.rend(),a[i])-1);
		dp[i]=dp[o]+(o-i)+(n-a[i]);
		wwx+=dp[i];
		while((!jyl.empty())&&(a[i]>a[jyl.back()])) {
			jyl.pop_back();
		}
		jyl.pb(i);
	}
	printf("%lld\n",wwx);
    return 0;
}
