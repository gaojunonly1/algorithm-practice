#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,m;
ll a[100005];
ll wwx=0;
int check(int oo);
int main() {
	int i,j,k;
	int oo,pp,qq;
	int l1,r1,mid,jyl=-1;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++) {
		scanf("%d%I64d",&oo,&a[i]);
	}
	sort(a+1,a+m+1);
	reverse(a+1,a+m+1);
	l1=1;
	r1=m;
	while(l1<=r1) {
		mid=(l1+r1)>>1;
		if(check(mid)<=n) {
			l1=mid+1;
			jyl=mid;
		}
		else
			r1=mid-1;
	}
	wwx=0;
	for(i=1;i<=jyl;i++)
		wwx+=a[i];
	printf("%I64d\n",wwx);
    return 0;
}
int check(int oo) {
	if(oo<=2)
		return oo;
	if(oo&1)
		return 1ll*oo*(oo-1)/2+1;
	else
		return 1ll*oo*(oo-1)/2+1+(oo-2)/2;
}
