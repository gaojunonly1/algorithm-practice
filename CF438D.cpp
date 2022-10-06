#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,Q;
ll a[100005];
struct SegmentTree {
	ll s[100005<<2],mx[100005<<2];
	void PushUp(int x) {
		s[x]=s[x<<1]+s[x<<1|1];
		mx[x]=max(mx[x<<1],mx[x<<1|1]);
	}
	void Build(int x,int l,int r) {
		if(l==r) {
			s[x]=mx[x]=a[l];
			return;
		}
		int mid=(l+r)>>1;
		Build(x<<1,l,mid);
		Build(x<<1|1,mid+1,r);
		PushUp(x);
	}
	void ModifyMod(int x,int l,int r,int l1,int r1,ll mod) {
		if(mx[x]<mod)
			return;
		if(l==r) {
			s[x]=mx[x]=s[x]%mod;
			return;
		}
		int mid=(l+r)>>1;
		if(l1<=mid)
			ModifyMod(x<<1,l,mid,l1,r1,mod);
		if(r1>mid)
			ModifyMod(x<<1|1,mid+1,r,l1,r1,mod);
		PushUp(x);
	}
	void ModifyPos(int x,int l,int r,int pos,ll val) {
		if(l==r) {
			s[x]=mx[x]=val;
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid)
			ModifyPos(x<<1,l,mid,pos,val);
		if(pos>mid)
			ModifyPos(x<<1|1,mid+1,r,pos,val);
		PushUp(x);
	}
	ll Query(int x,int l,int r,int l1,int r1) {
		if(l1<=l&&r1>=r)
			return s[x];
		int mid=(l+r)>>1;
		ll jyl=0;
		if(l1<=mid)
			jyl+=Query(x<<1,l,mid,l1,r1);
		if(r1>mid)
			jyl+=Query(x<<1|1,mid+1,r,l1,r1);
		return jyl;
	}
}T;
int main() {
	int i;
	int oo,l,r;
	ll m;
    scanf("%d%d",&n,&Q);
    for(i=1;i<=n;i++)
    	scanf("%lld",&a[i]);
    T.Build(1,1,n);
    while(Q--) {
//    	cout<<"ALL="<<T.Query(1,1,n,1,n)<<endl;
    	scanf("%d%d%d",&oo,&l,&r);
    	if(1==oo) {
    		printf("%lld\n",T.Query(1,1,n,l,r));
		}
		else if(2==oo) {
			scanf("%lld",&m);
			T.ModifyMod(1,1,n,l,r,m);
		}
		else
			T.ModifyPos(1,1,n,l,r);
	}
	return 0;
}
