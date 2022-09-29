#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int l1,r1;
int a[11];
int dp[15][15][2][2];
int calc(int num);
int dfs(int pos,int las,bool qd0,bool limit);
int main() {
	int i,j,k;
	scanf("%d%d",&l1,&r1);
	printf("%d\n",calc(r1)-calc(l1-1));
    return 0;
}
int calc(int num) {
	*a=0;
	while(num) {
		a[++*a]=num%10;
		num/=10;
	}
	memset(dp,-1,sizeof dp);
	return dfs(*a,11,1,1);
}
int dfs(int pos,int las,bool qd0,bool limit) {
	if(pos<1)
		return 1;
	if(~dp[pos][las][qd0][limit])
		return dp[pos][las][qd0][limit];
	int i;
	int jyl=0;
	for(i=0;i<=9;i++) {
		if((i<=a[pos]||0==limit)&&(2<=abs(i-las)||qd0))
			jyl+=dfs(pos-1,i,qd0&&(0==i),limit&&(a[pos]==i));
	}
	return dp[pos][las][qd0][limit]=jyl;
}
