#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
#define iinf INT_MAX

ll prim[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};

int n;
ll wwx=inf;
void dfs(ll num,int cur,int mx,int cnt);
int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	
	scanf("%d",&n);
	dfs(1ll,0,64,1);
	printf("%lld\n",wwx);

    return 0;
}
void dfs(ll num,int cur,int mx,int cnt) {
	if(cnt>n||cur>15) {
		return;
	}
	if(num>wwx||num<=0) {
		return;
	}
	if(cnt==n) {
		wwx=num;
		return;
	}
	ll oo=1;
	int i;
	fz0g(i,mx) {
		dfs(num*oo,cur+1,i,cnt*(i+1));
		oo*=prim[cur];
	}
}
