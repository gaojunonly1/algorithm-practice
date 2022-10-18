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
void solve();
int main() {
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
    return 0;
}
void solve() {
	int n,m;
	scanf("%d%d",&n,&m);
	if(n>m)
		swap(n,m);
	if(n==1&&m==1) {
		printf("0\n");
	}
	else if(n==1) {
		printf("1\n");
	}
	else {
		printf("2\n");
	}
}
