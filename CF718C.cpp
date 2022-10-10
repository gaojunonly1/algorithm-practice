#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const ll Mod=1000000007;
const ll inv2=500000004;
const ll inv5=400000003;
const int Base=32768;
int n,m;
ll a[100005]; 
struct comp { //the type of a+b*sqrt(5)
	ll a,b;
	comp operator+(const comp &t)const {
		return (comp){(a+t.a)%Mod,(b+t.b)%Mod};
	}
	comp operator-(const comp &t)const {
		return (comp){(a-t.a+Mod)%Mod,(b-t.b+Mod)%Mod};
	}
	comp operator*(const comp &t)const {
		return (comp){(a*t.a%Mod+5*b*t.b%Mod)%Mod,(a*t.b%Mod+b*t.a%Mod)%Mod};
	}
}pw0[2][Base+5],pw1[2][Base+5];
const comp ds[2]={{inv2,inv2},{inv2,Mod-inv2}};
void makepw();
comp gsm(int n,int o);
ll feibo(int n);
struct Node {
	ll s1,s2;
	Node operator+(const Node &tmp)const {
		return (Node){(s1+tmp.s1)%Mod,(s2+tmp.s2)%Mod};
	}
	bool operator!=(const Node &tmp)const {
		return (s1==tmp.s1&&s2==tmp.s2)?0:1;
	}
};
Node NodeAdd(Node pp,Node qq) { //n,n+1 and m,m+1
	Node jyl;
	jyl.s1=(pp.s1*qq.s2+(pp.s2-pp.s1)*qq.s1)%Mod;
	jyl.s1=(jyl.s1+Mod)%Mod;
	jyl.s2=(pp.s1*qq.s1+pp.s2*qq.s2)%Mod;
	return jyl;
}
struct SegmentTree {
	Node s[100005<<2],tag[100005<<2];
	void PushUp(int x) {
		s[x]=s[x<<1]+s[x<<1|1];
		return;
	}
	void Update(int x,Node oo) {
		s[x]=NodeAdd(s[x],oo);
		tag[x]=NodeAdd(tag[x],oo);
	}
	void PushDown(int x) {
		if(tag[x]!=(Node){0,1}) {
			Update(x<<1,tag[x]);
			Update(x<<1|1,tag[x]);
			tag[x]=(Node){0,1};
		}
	}
	void Build(int x,int l,int r) {
		tag[x]=Node{0,1};
		if(l==r) {
			s[x]=(Node){feibo(a[l]),feibo(a[l]+1)};
			return;
		}
		int mid=(l+r)>>1;
		Build(x<<1,l,mid);
		Build(x<<1|1,mid+1,r);
		PushUp(x);
	}
	void ModifyAdd(int x,int l,int r,int l1,int r1,Node oo) {
		if(l>=l1&&r<=r1) {
			Update(x,oo);
			return;
		}
		int mid=(l+r)>>1;
		PushDown(x);
		if(l1<=mid)
			ModifyAdd(x<<1,l,mid,l1,r1,oo);
		if(r1>mid)
			ModifyAdd(x<<1|1,mid+1,r,l1,r1,oo);
		PushUp(x);
	}
	ll Query(int x,int l,int r,int l1,int r1){
		if(l>=l1&&r<=r1) {
			return s[x].s1;
		}
		PushDown(x);
		int mid=(l+r)>>1;
		ll jyl=0;
		if(l1<=mid)
			(jyl+=Query(x<<1,l,mid,l1,r1))%=Mod;
		if(r1>mid)
			(jyl+=Query(x<<1|1,mid+1,r,l1,r1))%=Mod;
		return jyl;
	}
}T;
int main() {
	int i,j,k;
	int oo,pp,qq,jyl;
	scanf("%d%d",&n,&m);
	makepw();
	for(i=1;i<=n;i++) {
		scanf("%lld",a+i);
	}
	T.Build(1,1,n);
	for(i=1;i<=m;i++) {
		scanf("%d%d%d",&oo,&pp,&qq);
		if(1==oo) {
			scanf("%d",&jyl);
			T.ModifyAdd(1,1,n,pp,qq,(Node){feibo(jyl),feibo(jyl+1)});
		}
		else {
			printf("%lld\n",T.Query(1,1,n,pp,qq));
		}
	}
    return 0;
}
void makepw() {
	int i,j;
	pw0[0][0]=pw0[1][0]=pw1[0][0]=pw1[1][0]=(comp){1,0};
	for(i=1;i<=32768;i++) {
		for(j=0;j<2;j++) {
			pw0[j][i]=pw0[j][i-1]*ds[j];
		}
	}
	for(i=1;i<=32767;i++) {
		for(j=0;j<2;j++) {
			pw1[j][i]=pw1[j][i-1]*pw0[j][Base];
		}
	}
}
comp gsm(int n,int o) {
	return pw1[o][(n>>15)&32767]*pw0[o][n&32767];
}
ll feibo(int n) {
	comp div={0,inv5};
	comp tmp=div*(gsm(n,0)-gsm(n,1));
	return tmp.a;
}
