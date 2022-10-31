#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
#define iinf INT_MAX

const double eps=1e-9;

struct pot {
	double x,y;
	pot() {
		return;
	}
	pot(double xx,double yy) {
		x=xx;
		y=yy;
	}
	void Init(double xx,double yy) {
		x=xx;
		y=yy;
	}
	bool operator==(const pot tmp)const {
		return fabs(x-tmp.x)<eps&&fabs(y-tmp.y)<eps;
	}
}jyl[5],syf;

double dist(pot pp,pot qq);

struct vec {
	double vx,vy;
	void Init(pot pp,pot qq) {
		vx=pp.x-qq.x;
		vy=pp.y-qq.y;
	}
	bool operator==(const vec tmp)const {
		return fabs(vx-tmp.vx)<eps&&fabs(vy-tmp.vy)<eps;
	}
}gj[5];

double cj(vec pp,vec qq);

double sqr(double oo);

void solve();

int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	
	int T;
	scanf("%d",&T);
	while(T--) {
		solve();
	}

    return 0;
}

void solve() {
	int i;
	double p,q;
	fz1(i,3) {
		scanf("%lf%lf",&p,&q);
		jyl[i].Init(p,q);
	}
	scanf("%lf%lf",&p,&q);
	syf.Init(p,q);
	if(syf==jyl[1]) {
		printf("%.12lf %.12lf\n",(jyl[2].x+jyl[3].x)/2.,(jyl[2].y+jyl[3].y)/2.);
		return;
	}
	else if(syf==jyl[2]) {
		printf("%.12lf %.12lf\n",(jyl[1].x+jyl[3].x)/2.,(jyl[1].y+jyl[3].y)/2.);
		return;
	}
	else if(syf==jyl[3]) {
		printf("%.12lf %.12lf\n",(jyl[1].x+jyl[2].x)/2.,(jyl[1].y+jyl[2].y)/2.);
		return;
	}
	fz1(i,3) {
		gj[i].Init(syf,jyl[i]);
	}
	if(cj(gj[1],gj[2])<eps&&max(dist(syf,jyl[1]),dist(syf,jyl[2]))+eps<dist(jyl[1],jyl[2])) {
	}
	else if(cj(gj[1],gj[3])<eps&&max(dist(syf,jyl[1]),dist(syf,jyl[3]))+eps<dist(jyl[1],jyl[3])) {
		swap(gj[2],gj[3]);
		swap(jyl[2],jyl[3]);
	}
	else if(cj(gj[2],gj[3])<eps&&max(dist(syf,jyl[2]),dist(syf,jyl[3]))+eps<dist(jyl[2],jyl[3])) {
		swap(gj[1],gj[3]);
		swap(jyl[1],jyl[3]);
	}
	else {
		printf("-1\n");
		return;
	}
	double bl;
	bl=dist(syf,jyl[1])/dist(jyl[1],jyl[2]);
	if(bl<0.5) {
		bl=1.-bl;
		swap(jyl[1],jyl[2]);
		swap(gj[1],gj[2]);
	}
	bl=0.5/bl;
	printf("%.12lf %.12lf\n",jyl[1].x*(1.-bl)+jyl[3].x*bl,jyl[1].y*(1.-bl)+jyl[3].y*bl);
}

double cj(vec pp,vec qq) {
	return fabs(pp.vx*qq.vy-pp.vy*qq.vx);
}

double dist(pot pp,pot qq) {
	return sqrt(sqr(pp.x-qq.x)+sqr(pp.y-qq.y));
}

double sqr(double oo) {
	return (double)oo*oo;
}

/*
1
0 0 1 0 1 1 0.5 0.5
*/
