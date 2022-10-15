#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const ll Mod=1000000007;
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
		void Add(int x,ll z) {
			for(int i=x;i<=n;i+=lowbit(i))
				(s[i]+=z)%=Mod;
		}
		ll Ask(int x) {
			int jyl=0;
			for(int i=x;i>0;i-=lowbit(i))
				(jyl+=s[i])%=Mod;
			return jyl;
		}
	private:
		int n;
		ll s[1000005];
};
Tree T(1000000);
int n;
int a[100005];
ll dp[100005];
int jyl[1000005];
int main() {
	int i,j,k;
	ll oo,pp,qq;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=1;i<=n;i++) {
		dp[i]=(T.Ask(a[i])+1)*a[i]%Mod;
		T.Add(a[i],dp[i]);
		if(jyl[a[i]]) {
			T.Add(a[i],(-dp[jyl[a[i]]]+Mod)%Mod);
			dp[jyl[a[i]]]=0;
		}
		jyl[a[i]]=i;
	}
	ll wwx=0;
	for(i=1;i<=n;i++)
		(wwx+=dp[i])%=Mod;
    printf("%lld\n",(wwx+Mod)%Mod);
	return 0;
}
