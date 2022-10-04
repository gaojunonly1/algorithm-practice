#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
ll d;
ll a[100005],b[100005];
int id[100005];
int dp[100005];
int pre[100005];
int tot=0;
map<ll,int>jyl;
ll p[100005];
ll dat[100005];
int wwx,jc;
struct Tree1 {
	int n;
	pii s[100005];
	#define lowbit(x) ((x)&(-x))
	Tree1(int oo) {
		n=oo;
	}
	void Add(int x,pii z) {
		while(x<=n) {
			s[x]=max(s[x],z);
			x+=lowbit(x);
		}
	}
	pii Ask(int x) {
		pii jyl=mp(-1,-1);
		while(x>0) {
			jyl=max(jyl,s[x]);
			x-=lowbit(x);
		}
		return jyl;
	}
};
struct Tree2 {
	int n;
	pii s[100005];
	#define lowbit(x) ((x)&(-x))
	Tree2(int oo) {
		n=oo;
		memset(s,0,sizeof s);
	}
	void Add(int x,pii z) {
		while(x>0) {
			s[x]=max(s[x],z);
			x-=lowbit(x);
		}
	}
	pii Ask(int x) {
		pii jyl=mp(-1,-1);
		while(x<=n) {
			jyl=max(jyl,s[x]);
			x+=lowbit(x);
		}
		return jyl;
	}
};
int main() {
	int i;
	int oo;
	ll pp,qq;
	scanf("%d%lld",&n,&d);
	for(i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	p[tot=1]=b[1]; jyl[p[1]]=1;
	for(i=2;i<=n;i++)
		if(b[i]!=b[i-1]) {
			p[++tot]=b[i];
			jyl[p[tot]]=tot;
		}
	for(i=1;i<=n;i++)
		id[i]=jyl[a[i]];
	dp[0]=0;
	dp[1]=1;
	Tree1 T1=Tree1(tot);
	Tree2 T2=Tree2(tot);
	T1.Add(id[1],mp(1,1));
	T2.Add(id[1],mp(1,1));
	wwx=1;
	jc=1;
	pre[1]=1;
	for(i=2;i<=n;i++) {
		dp[i]=1;
		pre[i]=i;
		pp=a[i]-d;
		if(pp>=p[1]) {
			oo=upper_bound(p+1,p+tot+1,pp)-p-1;
			auto tmp=T1.Ask(oo);
			if(tmp.fi+1>dp[i]) {
				dp[i]=tmp.fi+1;
				pre[i]=tmp.se;
			}
		}
		qq=a[i]+d;
		if(qq<=p[tot]) {
			oo=lower_bound(p+1,p+tot+1,qq)-p;
			auto tmp=T2.Ask(oo);
			if(tmp.fi+1>dp[i]) {
				dp[i]=tmp.fi+1;
				pre[i]=tmp.se;
			}
		}
		T1.Add(id[i],mp(dp[i],i));
		T2.Add(id[i],mp(dp[i],i));
		if(dp[i]>wwx) {
			wwx=dp[i];
			jc=i;
		}
	}
	printf("%d\n",wwx);
	vector<int>jfm;
	jfm.pb(jc);
	while(pre[jc]!=jc) {
		jc=pre[jc];
		jfm.pb(jc);
	}
	reverse(jfm.begin(),jfm.end());
	for(auto yzy:jfm)
		printf("%d ",yzy);
	printf("\n");
    return 0;
}
