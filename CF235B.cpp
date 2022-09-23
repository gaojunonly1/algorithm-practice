#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
double a[100005],dp[100005];
int main() {
	int i;
	double wwx=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%lf",&a[i]);
		wwx+=a[i];
	}
	dp[0]=0;
	for(i=1;i<=n;i++) {
		dp[i]=(dp[i-1]+a[i-1])*a[i];
		wwx+=dp[i]*2;
	}
	printf("%.10lf\n",wwx);
    return 0;
}
