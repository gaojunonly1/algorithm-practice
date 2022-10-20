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
int main() {
	freopen("test.in","r",stdin);
	int i,j,L;
	int o,p,q;
	ll oo,pp,qq;
	
	int n,k,a,b;
	char s[205];
	int dp[205][205];
	scanf("%d%d%d",&k,&a,&b);
	scanf("%s",s+1);
	n=strlen(s+1);
	memset(dp,0,sizeof dp);
	for(i=a;i<=b;i++)
		dp[i][1]=i;
	for(i=a*2;i<=n;i++) {
		for(j=2;j<=k;j++) {
			for(L=a;L<=b;L++) {
				if(i>L&&dp[i-L][j-1]) {
					dp[i][j]=L;
					break;
				}
			}
		}
	}
	if(!dp[n][k]) {
		printf("No solution\n");
		return 0;
	}
	int now=n;
	vector<string>jyl;
	while(now>0) {
		string jc="";
		for(i=now-dp[now][k]+1;i<=now;i++) {
			jc.pb(s[i]);
		}
		now-=dp[now][k];
		k--;
		jyl.pb(jc);
	}
	reverse(jyl.begin(),jyl.end());
	for(auto oo:jyl)
		cout<<oo<<endl;
    return 0;
}
