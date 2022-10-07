#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
double wwx=0;
const double eps=1e-6;
struct point {
	double x,y;
}a[305];
double cj(point oo,point pp,point qq);
int main() {
	int i,j,k;
	int oo,pp,qq;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%lf%lf",&a[i].x,&a[i].y);
	for(i=1;i<n;i++) {
		for(j=i+1;j<=n;j++) {
			double s1=0,s2=0;
			for(k=1;k<=n;k++) {
				if(k==i||k==j)
					continue;
				double s=cj(a[i],a[j],a[k]);
				if(s>0)
					s1=max(s1,s/2.);
				else
					s2=max(s2,-s/2.);
			}
			if(s1>eps&&s2>eps)
				wwx=max(wwx,s1+s2);
		}
	}
	printf("%.6lf\n",wwx);
    return 0;
}
double cj(point oo,point pp,point qq) {
	point A=(point){pp.x-oo.x,pp.y-oo.y};
	point B=(point){qq.x-oo.x,qq.y-oo.y};
	return A.x*B.y-A.y*B.x;
}
