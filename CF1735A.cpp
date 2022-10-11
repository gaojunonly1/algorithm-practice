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
	int i,j,k;
	ll oo,pp,qq;
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
    return 0;
}
void solve() {
	scanf("%d",&n);
	n-=3;
	printf("%d\n",(n-3)/3);
}
