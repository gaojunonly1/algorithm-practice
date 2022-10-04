#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
ll k,a[100005];
ll check(ll stp);
int main() {
	int i,j;
	ll l1,r1,jyl;
	set<ll>jihe;
	scanf("%d%lld",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	l1=0;
	r1=k;
	while(l1<=r1) {
		ll mid=(l1+r1)>>1;
//		cout<<l1<<" "<<r1<<" "<<mid<<endl;
		if(check(mid)<=k) {
			jyl=mid;
			l1=mid+1;
		}
		else
			r1=mid-1;
	}
	k-=check(jyl);
	for(i=1;i<=n;i++)
		a[i]=max(0ll,a[i]-jyl);
//	cout<<"jyl="<<jyl<<endl;
	for(i=1;i<=n&&k>0;i++)
		if(a[i]>0) {
			a[i]--;
			k--;
		}
	for(i=1;i<=n;i++)
		printf("%lld ",a[i]);
	printf("\n");
    return 0;
}
ll check(ll stp) {
	int i;
	ll oo=0;
	for(i=1;i<=n;i++)
		oo+=min(a[i],stp);
	return oo;
}
