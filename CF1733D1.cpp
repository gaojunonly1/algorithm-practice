#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
ll x,y;
int a[3005],b[3005];
char sa[3005],sb[3005];
ll wwx;
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
	CSH();
	int i,j,k;
	int oo,pp,qq;
	scanf("%d%lld%lld",&n,&x,&y);
	scanf("%s",sa+1);
	scanf("%s",sb+1);
	qq=0;
	for(i=1;i<=n;i++) {
		a[i]=sa[i]-'0';
		b[i]=sb[i]-'0';
		if(a[i]!=b[i])
			qq++;
	}
	if(qq&1) {
		printf("-1\n");
		return;
	}
	if(qq>2)
		wwx=1ll*y*qq/2;
	else if(qq==2){
		bool flg=0;
		for(i=1;i<n;i++) if(a[i]!=b[i]&&a[i+1]!=b[i+1]) {
			flg=1;
			break;
		}
		if(flg)
			wwx=min(x,y*2);
		else
			wwx=y;
	}
	printf("%lld\n",wwx);
	return;
}
void CSH() {
	wwx=0;
	return;
}
