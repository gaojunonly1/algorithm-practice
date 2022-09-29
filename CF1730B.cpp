#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
double eps=1e-6;
struct node {
	double x;
	double t;
}a[100005];
double jyl;
void solve();
double check(double wwx);
int main() {
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
    return 0;
}
void solve() {
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%lf",&a[i].x);
	for(i=1;i<=n;i++)
		scanf("%lf",&a[i].t);
	double l1=0,r1=2e8;
	double wwx=-1;
	while(l1+eps<r1) {
		double mid=(l1+r1)/2;
		jyl=check(mid);
		if(-1!=jyl) {
			wwx=jyl;
			r1=mid;
		}
		else
			l1=mid;
	}
	printf("%.6lf\n",wwx);
}
double check(double wwx) {
	int i,j,k;
	double l1,r1;
	for(i=1;i<=n;i++) {
		if(wwx<a[i].t)
			return -1;
		double oo=wwx-a[i].t;
		if(i==1) {
			l1=a[i].x-oo;
			r1=a[i].x+oo;
		}
		else {
			l1=max(l1,a[i].x-oo);
			r1=min(r1,a[i].x+oo);
		}
	}
	if(l1-r1>eps)
		return -1;
	return l1+eps;
}
