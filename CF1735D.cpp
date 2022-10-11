#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,K;
ll bin[25];
struct node {
	ll num;
	int c[25];
	ll tot;
	node() {
		num=0ll;
		tot=0;
	}
	bool operator<(const node tmp) const{
		for(int i=1;i<=K;i++) {
			if(c[i]!=tmp.c[i])
				return c[i]<tmp.c[i];
		}
	}
}a[1005];
bool cmpnum(node pp,node qq);
map<ll,int>jyl;
int main() {
	int i,j,k;
	ll oo,pp,qq;
	scanf("%d%d",&n,&K);
	bin[0]=1ll;
	for(i=1;i<=21;i++)
		bin[i]=bin[i-1]*3ll;
	jyl.clear();
	for(i=1;i<=n;i++) {
		for(j=1;j<=K;j++) {
			scanf("%d",&a[i].c[j]);
			a[i].num=(ll)a[i].num*3ll+a[i].c[j];
		}
	}
	sort(a+1,a+n+1,cmpnum);
	jyl.clear();
	node tmp;
	tmp.num=tmp.tot=0;
	for(i=1;i<=n;i++) {
		for(j=i+1;j<=n;j++) {
			tmp.num=0;
			for(k=1;k<=K;k++) {
				tmp.c[k]=(a[i].c[k]+a[j].c[k])%3;
				tmp.num=tmp.num*3+tmp.c[k];
			}
			jyl[tmp.num]++;
		}
	}
	for(i=1;i<=n;i++) {
		tmp.num=0;
		for(j=1;j<=K;j++) {
			tmp.c[j]=(3-a[i].c[j])%3;
			tmp.num=tmp.num*3+tmp.c[j];
		}
		a[i].tot=jyl[tmp.num];
	}
	ll wwx=0;
	for(i=1;i<=n;i++) {
		wwx+=a[i].tot*(a[i].tot-1)/2;
	}
	printf("%lld\n",wwx);
    return 0;
}
bool cmpnum(node pp,node qq) {
	return pp.num<qq.num;
}
