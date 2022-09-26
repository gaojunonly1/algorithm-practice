#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int a[3];
void solve();
int main() {
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
    return 0;
}
void solve() {
	scanf("%d%d%d",&a[0],&a[1],&a[2]);
	sort(a,a+3);
	if(a[0]==a[1]||a[1]==a[2])
		printf("1\n");
	else {
		if(a[0]+a[1]==a[2]||a[0]*a[1]==a[2]||a[0]==1)
			printf("2\n");
		else if(a[1]-a[0]==a[0]||a[2]-a[1]==a[1]||a[2]-a[0]==a[0])
			printf("2\n");
		else
			printf("3\n");
	}
	return;
}
