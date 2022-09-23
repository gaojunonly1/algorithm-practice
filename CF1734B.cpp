#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
void solve();
int main() {
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
    return 0;
}
void solve() {
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++,putchar('\n'))
		for(j=1;j<=i;j++,putchar(' '))
			(j==1||j==i)?putchar('1'):putchar('0');
}
