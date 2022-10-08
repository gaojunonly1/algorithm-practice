#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
ll m,K;
int tot=0;
int a[65];
ll dp[65][65];
ll dfs(int now,int num1,bool limit);
ll solve(ll x);
int main() {
	int i,j,k;
	ll oo,pp,qq;
	scanf("%lld%lld",&m,&K);
	ll l1=1,r1=1e18,mid;
	memset(dp,-1,sizeof dp);
	while(l1<=r1) {
		mid=(l1+r1)>>1;
//		cout<<l1<<" "<<mid<<" "<<r1<<endl;
		oo=solve(mid*2)-solve(mid);
//		cout<<solve(mid*2)<<" "<<solve(mid)<<endl;
		if(oo>=m) {
			r1=mid-1;
			if(oo==m) {
				printf("%lld\n",mid);
				return 0;
			}
		}
		else
			l1=mid+1;
	}
	printf("%lld\n",r1);
    return 0;
}
ll solve(ll x) {
	tot=0;
	while(x) {
		a[++tot]=x&1;
		x>>=1;
	}
	dfs(tot,0,1);
}
ll dfs(int now,int num1,bool limit) {
//	cout<<"now="<<now<<" "<<"num1="<<num1<<endl;
//	system("pause");
	if(now<1)
		return (num1==K)?1:0;
	if(0==limit&&-1!=dp[now][num1])
		return dp[now][num1];
	ll jyl=0;
	for(int i=0;i<=(limit?a[now]:1);i++) {
//		cout<<"i="<<i<<" "<<a[now]<<endl;
		if(num1+(i==1)<=K)
			jyl+=dfs(now-1,num1+(i==1),limit&&(i==a[now]));
	}
	if(!limit)
		dp[now][num1]=jyl;
	return jyl;
}
