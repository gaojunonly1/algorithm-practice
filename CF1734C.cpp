#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
bool bo[1000005];
bool vis[1000005];
char t[1000005];
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
	scanf("%s",t+1);
	for(i=1;i<=n;i++) {
		bo[i]=(t[i]-'0');
		vis[i]=0;
	}
	ll wwx=0;
	for(i=1;i<=n;i++) {
		for(j=i;j<=n;j+=i) {
			if(!bo[j]) {
				if(!vis[j]) {
					wwx+=i;
					vis[j]=1;
				}
			}
			else
				break;
		}
	}
	printf("%lld\n",wwx);
}
