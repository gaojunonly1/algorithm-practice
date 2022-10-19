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
int n,K;
ll S;
ll a[35],fac[35];
map<pair<ll,int>,ll>jyl;
ll wwx=0;
void dfs1(int now,int r,int cnt,ll num);
void dfs2(int now,int r,int cnt,ll num);
int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	scanf("%d%d%lld",&n,&K,&S);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	fac[0]=1;
	for(i=1;i<=20;i++) {
		fac[i]=fac[i-1]*i;
//		cout<<i<<' '<<fac[i]<<endl;
	}
	if(n<=13) {
		dfs1(1,n,0,0);
		for(i=0;i<=K;i++)
			wwx+=jyl[mp(S,i)];
	}
	else {
		dfs1(1,13,0,0);
		dfs2(14,n,0,0);
	}
	printf("%lld\n",wwx);
    return 0;
}
void dfs1(int now,int r,int cnt,ll num) {
	if(now>r) {
		jyl[mp(num,cnt)]++;
		return;
	}
	dfs1(now+1,r,cnt,num);
	if(num+a[now]<=S)
		dfs1(now+1,r,cnt,num+a[now]);
	if(a[now]<=20&&num+fac[a[now]]<=S)
		dfs1(now+1,r,cnt+1,num+fac[a[now]]);
}
void dfs2(int now,int r,int cnt,ll num) {
	if(now>r) {
		if(num<=S) {
			for(int i=0;i<=K-cnt;i++) {
				wwx+=jyl[mp(S-num,i)];
			}
		}
		return;
	}
	dfs2(now+1,r,cnt,num);
	if(num+a[now]<=S)
		dfs2(now+1,r,cnt,num+a[now]);
	if(a[now]<=20&&num+fac[a[now]]<=S)
		dfs2(now+1,r,cnt+1,num+fac[a[now]]);
}
