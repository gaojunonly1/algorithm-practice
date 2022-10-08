#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,m;
int t,T;
ll x,cost;
ll wwx=0;
int main() {
	int i,j,k;
	ll oo,pp,qq;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) {
		scanf("%d%d%lld%lld",&t,&T,&x,&cost);
		if(T<=t)
			wwx+=m*x+cost;
		else if(t+m<=T)
			wwx+=cost;
		else
			wwx+=min(x*m+cost,(ll)ceil(m*1.0/(T-t))*cost);
	}
	printf("%lld\n",wwx);
    return 0;
}
