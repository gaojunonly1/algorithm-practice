#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
/*
	dp[i][j]价值异或和是i,体积是j的方案是否存在
*/
bitset<1050>dp[1050],dp1[1050];
int main() {
	int T,n,m;
	int i,j,k;
	cin>>T;
	while(T--) {
		cin>>n>>m;
		for(i=0;i<1024;i++)
			dp[i].reset();
		dp[0][0]=1;
		int v,w;
		for(i=1;i<=n;i++) {
			cin>>v>>w;
			for(j=0;j<1024;j++) {
				dp1[j]=dp[j];
				dp1[j]<<=v;
			}
			for(j=0;j<1024;j++)
				dp[j]|=dp1[j^w];
		}
		int wwx=-1;
		for(i=1023;i>=0;i--)
			if(dp[i][m]) {
				wwx=i;
				break;
			}
		cout<<wwx<<endl;
	}
    return 0;
}
