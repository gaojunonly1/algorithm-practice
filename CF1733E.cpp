#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
ll t,x,y;
ll a[245],b[245]; //a表示向下,b表示向右 
void solve();
void CSH();
int main() {
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
    return 0;
}
void solve() {
	int i,j;
	scanf("%lld%lld%lld",&t,&x,&y);
	if(t<x+y) {
		printf("NO\n");
		return;
	}
	CSH();
	a[0]=t-x-y;
	b[0]=t+1-x-y;
	for(i=0;i<x+y;i++) {
		for(j=i;j>=0;j--) {
			a[j+1]+=a[j]/2;
			a[j]-=a[j]/2;
			b[j+1]+=b[j]/2;
			b[j]-=b[j]/2;
		}
	}
	ll x1=-1,y1=-1;
	for(i=0;i<240;i++)
		if(a[i]!=b[i]) {
			x1=i;
			y1=x+y-i;
		}
	if(x1==x&&y1==y)
		printf("YES\n");
	else
		printf("NO\n");
	return;
}
void CSH() {
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	return;
}
