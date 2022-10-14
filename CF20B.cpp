#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const double eps=1e-7;
double A,B,C;
int main() {
	int i,j,k;
	ll oo,pp,qq;
	scanf("%lf%lf%lf",&A,&B,&C);
	if(A==0&&B==0&&C==0) {
		printf("-1\n");
		return 0;
	}
	else if(A==0) {
		if(B==0) {
			printf("0\n");
		}
		else {
			printf("1\n");
			printf("%.9lf\n",-C/B);
		}
	}
	else {
		if(B*B-4*A*C<0) {
			printf("0\n");
		}
		else if(B*B-4*A*C<eps) {
			printf("1\n");
			printf("%.9lf\n",-B/A/2);
		}
		else {
			printf("2\n");
			double jyl=sqrt(B*B-4*A*C);
			if(A>0)
				printf("%.9lf\n%.9lf\n",(-B-jyl)/2/A,(-B+jyl)/2/A);
			else
				printf("%.9lf\n%.9lf\n",(-B+jyl)/2/A,(-B-jyl)/2/A);
		}
	}
    return 0;
}
