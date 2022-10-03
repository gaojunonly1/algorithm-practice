#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
int bo[100005];
ll a[100005],b[100005],c[100005];
ll wwx;
void solve();
void play(ll *a,ll *b);
int main() {
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
    return 0;
}
void solve() {
	int i,j,k;
	int oo;
	ll pp,qq;
	scanf("%d",&n);
	*a=*b=0;
	for(i=1;i<=n;i++)
		scanf("%d",&bo[i]);
	for(i=1;i<=n;i++) {
		scanf("%lld",&pp);
		if(bo[i])
			b[++*b]=pp;
		else
			a[++*a]=pp;
	}
	sort(a+1,a+*a+1);
	sort(b+1,b+*b+1);
	wwx=0;
	if(*a>=1)
		play(a,b);
	if(*b>=1)
		play(b,a);
	printf("%lld\n",wwx);
}
void play(ll *a,ll *b) {
	int j,k;
	ll jyl=0;
	jyl+=a[1];
	j=*a; k=*b;
	while(j>=2&&k>=1) {
		jyl+=b[k]*2;
		jyl+=a[j]*2;
		k--;
		j--;	
	}
	if(k>=1) {
		jyl+=b[k]*2;
		k--;
		while(k>=1) {
			jyl+=b[k];
			k--;
		}
	}
	else if(j>=2) {
		while(j>=2) {
			jyl+=a[j];
			j--;
		}
	}
	wwx=max(wwx,jyl);
}
