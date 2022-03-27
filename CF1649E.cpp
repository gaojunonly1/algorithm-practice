#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <typename T>
class Tree {
	#define lowbit(x) ((x)&(-x))
	public:
		Tree(int all_size) {
			jyl.resize(all_size+5);
			sz=all_size;
		}
		~Tree() {
			jyl.resize(0);
			sz=0;
		}
		void Tadd(int x,T y) {
			while(x<=sz) {
				jyl[x]+=y;
				x+=lowbit(x);
			}
		}
		T Tquery(int x) {
			T oo=0;
			while(x) {
				oo+=jyl[x];
				x-=lowbit(x);
			}
			return oo;
		}
	private:
		vector<T> jyl;
		size_t sz;
};

int n,m,nn,a[200005],na[200005],b[200005];
Tree<ll> T(200000);
ll fac[200005];

ll jyl,wwx=0;

ll ksm(ll x,ll y);

ll inv(ll pp);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i;
	ll oo;
	cin>>n>>m;
	for(i=1;i<=n;i++) {
		cin>>a[i];
		T.Tadd(a[i],1);
		na[a[i]]++;
	}
	for(i=1;i<=m;i++)
		cin>>b[i];
	for(fac[0]=1,i=1;i<=200000;i++)
		fac[i]=fac[i-1]*i%998244353;
	jyl=fac[n];
	for(i=1;i<=200000;i++)
		if(na[i])
			jyl=jyl*inv(fac[na[i]])%998244353;
	nn=n;
	for(i=1;i<=min(n,m);i++) {
		oo=jyl*inv(nn)%998244353
			*T.Tquery(b[i]-1)%998244353;
		(wwx+=oo)%=998244353;
		jyl=jyl*inv(nn)%998244353
			*na[b[i]]%998244353;
		nn--;
		na[b[i]]--;
		T.Tadd(b[i],-1);
	}
	if(n<m) {
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		bool bobo=0;
		for(i=1;i<=n&&(!bobo);i++)
			if(a[i]!=b[i])
				bobo=1;
		if(!bobo)
			wwx=(wwx+1)%998244353;
	}
	cout<<wwx<<endl;
	return 0;
}

ll ksm(ll x,ll y) {
	ll jyl=1;
	while(y) {
		if(y&1)
			jyl=jyl*x%998244353;
		x=x*x%998244353;
		y>>=1;
	}
	return jyl;
}

ll inv(ll pp) {
	return ksm(pp,998244351);
}
