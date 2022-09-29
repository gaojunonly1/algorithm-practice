#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,c;
int cnt[105];
void solve();
int main() {
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
    return 0;
}
void solve() {
	int i,j,k;
	int oo;
	scanf("%d%d",&n,&c);
	memset(cnt,0,sizeof cnt);
	for(i=1;i<=n;i++) {
		scanf("%d",&oo);
		cnt[oo]++;
	}
	int wwx=0;
	for(i=1;i<=100;i++)
		wwx+=min(cnt[i],c);
	printf("%d\n",wwx);
}
