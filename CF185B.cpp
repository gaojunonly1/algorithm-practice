#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
#define iinf INT_MAX
const double eps=1e-9;
double S,a,b,c;
double x,y,z;
int main() {
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	scanf("%lf%lf%lf%lf",&S,&a,&b,&c);
	if(a<eps&&b<eps&&c<eps) {
		printf("0.0 0.0 0.0\n");
		return 0;
	}
	x=S*a/(a+b+c);
	y=S*b/(a+b+c);
	z=S*c/(a+b+c);
	printf("%.12lf %.12lf %.12lf\n",x,y,z);
    return 0;
}
