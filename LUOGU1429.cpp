#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
const int N1=200005;
int n,tot;
struct node {
	ll x,y;
	bool operator<(node tmp)const {
		return x<tmp.x;
	}
}pot[N1],pp[N1];
ll Abs(ll x);
ll sqr(ll x);
ll dist(node pp,node qq);
void merge(int l,int r);
ll solve(int l,int r);
int main() {
	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%lld%lld",&pot[i].x,&pot[i].y);
	sort(pot+1,pot+n+1);
	double wwx=solve(1,n);
	printf("%.4lf\n",sqrt(wwx));
    return 0;
}
ll solve(int l,int r) {
	if(l>=r)
		return inf;
	if(l+1==r) {
		if(pot[l].y>pot[r].y)
			swap(pot[l],pot[r]);
		return dist(pot[l],pot[r]);
	}
	int mid=(l+r)>>1;
	ll midx=pot[mid].x;
	ll jyl=min(solve(l,mid),solve(mid+1,r));
	merge(l,r);
	int i,j;
	tot=0;
	for(i=l;i<=r;i++)
		if(sqr(pot[i].x-midx)<jyl)
			pp[++tot]=pot[i];
	for(i=1;i<=tot;i++)
		for(j=i+1;j<=tot&&sqr(pp[i].y-pp[j].y)<jyl;j++)
			jyl=min(jyl,dist(pp[i],pp[j]));
	return jyl;
}
void merge(int l,int r) {
	int mid=(l+r)>>1;
	int i=l,j=mid+1;
	for(int k=l;k<=r;k++) {
		if(i<=mid&&(j>r||pot[i].y<pot[j].y))
			pp[k]=pot[i++];
		else
			pp[k]=pot[j++];
	}
	for(int k=l;k<=r;k++)
		pot[k]=pp[k];
}
ll dist(node pp,node qq) {
	return sqr(pp.x-qq.x)+sqr(pp.y-qq.y);
}
ll sqr(ll x) {
	return x*x;
}
ll Abs(ll x) {
	return x<0?-x:x;
}
