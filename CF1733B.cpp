#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,x,y;
void solve();
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		solve();
	}	
    return 0;
}
void solve() {
	int i,j;
	scanf("%d%d%d",&n,&x,&y);
	if(0!=x*y||x==0&&y==0) {
		printf("-1\n");
		return;
	}
	if(x>y)
		swap(x,y);
	if(0!=(n-1)%y) {
		printf("-1\n");
		return;
	}
	else {
		for(i=2;i<=n;i+=y)
			for(j=1;j<=y;j++)
				printf("%d ",i);
		printf("\n");
	}
}
