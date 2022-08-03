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
void solve();
bool whlw(ll tim);
int main() {
	solve();
    return 0;
}
void solve() {
	int i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	while(0==a[n])
		n--;
	ll L=n+1,R=0;
	for(i=1;i<=n;i++)
		R+=a[i];
	R+=n;
	while(L<=R) {
		ll mid=(L+R)>>1;
		if(whlw(mid))
			R=mid-1;
		else
			L=mid+1;
	}
	cout<<L<<endl;
}
bool whlw(ll tim) {
	ll rs=0,tmp=0;
	for(int i=n;i>=1;i--) {
		if(a[i]<=tmp) {
			tmp-=a[i];
			continue;
		}
		ll oo=a[i]-tmp;
		tmp=0;
		ll jia=oo/(tim-i);
		rs+=jia;
		oo-=jia*(tim-i);
		if(0!=oo) {
			tmp+=tim-i-oo;
			rs++;
		}
	}
	return rs<=m;
}
