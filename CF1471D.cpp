#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,a[300005];
int pf[1005];
void solve();
int wwx[3];
int tot;
struct block {
	int num,cnt;
}b[300005];
int main() {
	int i;
	for(i=1;i<=1000;i++)
		pf[i]=i*i;
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
    return 0;
}
void solve() {
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		for(j=2;j<=1000;j++)
			while(a[i]%pf[j]==0)
				a[i]/=pf[j];
	}
	sort(a+1,a+n+1);
	tot=0;
	b[tot=1]=(block){a[1],1};
	for(i=2;i<=n;i++) {
		if(a[i]==a[i-1])
			b[tot].cnt++;
		else
			b[++tot]=(block){a[i],1};
	}
	wwx[0]=0;
	int oo=0;
	for(i=1;i<=tot;i++) {
		wwx[0]=max(wwx[0],b[i].cnt);
		if(b[i].cnt%2==0||b[i].num==1)
			oo+=b[i].cnt;
	}
	wwx[1]=oo;
	for(i=1;i<=tot;i++) {
		if(b[i].cnt%2==0||b[i].num==1)
			continue;
		else
			wwx[1]=max(wwx[1],b[i].cnt);
	}
	int q;
	scanf("%d",&q);
	while(q--) {
		ll pp;
		scanf("%lld",&pp);
		if(pp==0)
			printf("%d\n",wwx[0]);
		else
			printf("%d\n",wwx[1]);
	}
}
