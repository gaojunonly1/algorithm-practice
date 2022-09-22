#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,q,l1,r1;
char s[1000005];
int a[1000005],b[1000005],sb[1000005];
int zb1[1000005],yb1[1000005];
int main() {
	int i,j;
	int oo,pp,qq;
	scanf("%d%d",&n,&q);
	scanf("%s",s+1);
	for(i=1;i<=n;i++)
		a[i]=s[i]-'0';
	for(i=1;i<=n;i++) {
		b[i]=a[i];
		if(b[i]==1)
			b[i]=b[i-1]^1;
		sb[i]=sb[i-1]+b[i];
	}
	zb1[0]=0;
	for(i=1;i<=n;i++)
		zb1[i]=(a[i])?zb1[i-1]+1:0;
	yb1[n+1]=0;
	for(i=n;i>=1;i--)
		yb1[i]=(a[i])?yb1[i+1]+1:0;
	while(q--) {
		scanf("%d%d",&l1,&r1);
		pp=yb1[l1]; //从l1开始往右的1的数量
		qq=zb1[r1]; //从r1开始往左的1的数量
		int wwx=sb[r1-qq]-sb[l1+pp-1];
		wwx+=(pp+qq)/2+((pp+qq)&1);
		printf("%d\n",max(0,(r1-l1+1)/3-wwx));
	}
    return 0;
}
