#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
ll a[100005],s[100005];
ll bin[65];
int main() {
	freopen("test.in","r",stdin);
	int i,j;
	ll k;
	ll oo,pp,qq;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	s[n+1]=0;
	for(i=n;i>=1;i--) {
		s[i]=s[i+1]+a[i];
	}
	int T;
	scanf("%d",&T);
	ll lwj=0;
	for(i=n;i>=1;i--) {
		lwj+=a[i]*(n-i);
	}
	while(T--) {
		scanf("%lld",&k);
		if(k==1) {
			printf("%lld\n",lwj);
			continue;
		}
		ll wwx=0;
		ll r=n;
		int o=0;
		bin[o=0]=1;
		while(r>=1) {
			wwx+=(s[max(1ll,r-bin[o]+1)]-s[r+1])*o;
			r-=bin[o];
			o++;
			bin[o]=bin[o-1]*k;
		}
		printf("%lld ",wwx);
	}
	printf("\n");
    return 0;
}
