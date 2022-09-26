#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int T;
int n,a[100005],b[100005],c[100005];
void solve();
int main() {
	scanf("%d",&T);
	while(T--)
		solve();
    return 0;
}
void solve() {
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int jyl=0;
	for(i=1;i<=n;i++) {
		scanf("%d",&b[i]);
		c[i]=b[i]-a[i];
		jyl+=c[i]>=0;
	}
	sort(c+1,c+n+1);
	int oo=1,pp=n;
	int wwx=0;
	while(c[oo]<0&&c[pp]>=0) {
		if(c[oo]+c[pp]>=0) {
			wwx++;
			jyl--;
			pp--;
			oo++;
		}
		else
			oo++;
	}
	wwx+=jyl/2;
	printf("%d\n",wwx);
}
