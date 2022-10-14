#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
ll a[100005];
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
	private:
		int n;
		int s[100005];
};
int main() {
	int i,j,k;
	ll oo,pp,qq;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	Tree T(n);
	T.Add(n,1);
	ll jyl=a[n];
	for(i=n-1;i>=1;i--) {
		jyl-=a[i];
		if(jyl>=0)
			T.Add(i,2);
		else {
			jyl=-jyl;
			T.Add(i,1);
		}
	}
	for(i=1;i<=n;i++) {
		if(T.Ask(i)&1)
			putchar('+');
		else
			putchar('-');
	}
    return 0;
}
