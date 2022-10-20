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
int main() {
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	double n,m;
	scanf("%lf%lf",&n,&m);
	if(n==1&&m==1) {
		printf("1\n");
		return 0;
	}
	double wwx=1./n;
	wwx+=(n-1)*(m-1)/n/(n*m-1);
	printf("%.12lf\n",wwx);
    return 0;
}
