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
const int N1=300005;
class Tree {
	#define lowbit(x) ((x)&(-x))
	public:
		Tree() {
			memset(s,0,sizeof s);
		}
		Tree(int n1) {
			n=n1;
			memset(s,0,sizeof s);
		}
		void Init(int n1) {
			n=n1;
			memset(s,0,sizeof s);
		}
		void Add(int x,int z) {
			for(int i=x;i<=n;i+=lowbit(i))
				s[i]+=z;
		}
		int Ask(int x) {
			int jyl=0;
			for(int i=x;i>0;i-=lowbit(i))
				jyl+=s[i];
			return jyl;
		}
		int AskLR(int l,int r) {
			return Ask(r)-Ask(l-1);
		}
	private:
		int n;
		int s[N1];
}T[35];
int n,m;
int a[N1];
ll seed[35];
ll getrand();
int main() {
	srand(time(NULL));
	int i,j,k;
	int o,p,q,mod;
	ll oo,pp,qq;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) {
		scanf("%d",&a[i]);
	}
	for(i=0;i<30;i++) {
		seed[i]=getrand();
		T[i].Init(n);
	}
	for(i=1;i<=n;i++) {
		for(j=0;j<30;j++) {
			if(((1ll*a[i]*seed[j])>>40ll)&1) {
				T[j].Add(i,1);
			}
		}
	}
	while(m--) {
		scanf("%d%d%d",&o,&p,&q);
		if(o==1) {
			for(j=0;j<30;j++) {
				int tmp=0;
				if(((1ll*a[p]*seed[j])>>40ll)&1)
					tmp--;
				if(((1ll*q*seed[j])>>40ll)&1)
					tmp++;
				if(tmp!=0)
					T[j].Add(p,tmp);
			}
			a[p]=q;
		}
		else {
			scanf("%d",&mod);
			bool wwx=((q-p+1)%mod==0)?1:0;
			for(j=0;j<30&&wwx;j++) {
				if(T[j].AskLR(p,q)%mod!=0) {
					wwx=0;
				}
			}
			wwx?printf("YES\n"):printf("NO\n");
		}
	}
    return 0;
}
ll getrand() {
	return ((1ll<<34)^rand())*((1ll<<47)^rand());
}
