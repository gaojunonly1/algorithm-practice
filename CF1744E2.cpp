#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
int cnt=0;
ll wwx=-1,wwy=-1;
struct node {
	ll num;
	int tot;
	ll bin[105];
	node() {
		tot=0;
	}
	void Init() {
		bin[0]=1;
		for(int i=1;i<=tot;i++)
			bin[i]=bin[i-1]*num;
	}
}jyl[1005];
ll a,b,c,d;
void solve();
void dfs(int cur,ll x,ll y);
int main() {
	freopen("test.in","r",stdin);
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
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	ll a1=a,b1=b;
	map<ll,int>jc;
	for(ll i=2;i*i<=a1;i++) {
		if(a1%i==0) {
			while(a1%i==0) {
				jc[i]++;
				a1/=i;
			}
		}
	}
	if(a1>1)
		jc[a1]++;
	for(ll i=2;i*i<=b1;i++) {
		if(b1%i==0) {
			while(b1%i==0) {
				jc[i]++;
				b1/=i;
			}
		}
	}
	if(b1>1)
		jc[b1]++;
	cnt=0;
	for(auto oo:jc) {
		jyl[++cnt].num=oo.fi;
		jyl[cnt].tot=oo.se;
		jyl[cnt].Init();
	}
	wwx=-1; wwy=-1;
	dfs(1,1,1);
	printf("%lld %lld\n",wwx,wwy);
}
void dfs(int cur,ll x,ll y) {
	if(cur>cnt) {
		x=(a/x+1)*x;
		y=(b/y+1)*y;
		if(x<=c&&y<=d) {
			wwx=x;
			wwy=y;
		}
		return;
	}
	for(int i=0;i<=jyl[cur].tot;i++) {
		dfs(cur+1,x*jyl[cur].bin[i],y*jyl[cur].bin[jyl[cur].tot-i]);
	}
}
