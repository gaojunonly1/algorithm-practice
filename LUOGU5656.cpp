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

void solve();
ll exgcd(ll a,ll b,ll &x,ll &y);

int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	
	int T;
	scanf("%d",&T);
	while(T--) {
		solve();
	} 

    return 0;
}

void solve() {
	ll a,b,c,X,Y;
	scanf("%lld%lld%lld",&a,&b,&c);
	ll d=exgcd(a,b,X,Y);
	if(c%d!=0) {
		printf("-1\n");
		return;
	}
	X*=c/d;
	Y*=c/d;
//	cout<<"X="<<X<<" "<<"Y="<<Y<<endl;
	ll pp=b/d,qq=a/d;
//	cout<<"pp="<<pp<<" "<<"qq="<<qq<<endl;
	if(X<=0) {
		ll oo=ceil((1.-X)/pp);
		X+=oo*pp;
		Y-=oo*qq;
	}
	else if(X>0) {
		ll oo=(X-1)/pp;
		X-=oo*pp;
		Y+=oo*qq;
	}
	if(Y>0) {
		printf("%lld ",(Y-1)/qq+1);
		printf("%lld ",X);
		printf("%lld ",(Y-1)%qq+1);
		printf("%lld ",X+(Y-1)/qq*pp);
		printf("%lld\n",Y);
	}
	else {
		printf("%lld ",X);
		Y+=qq*ceil((1.-Y)/qq);
		printf("%lld\n",Y);
	}
}

ll exgcd(ll a,ll b,ll &x,ll &y) {
	ll oo=a;
	if(b==0) {
		x=1;
		y=0;
	}
	else {
		oo=exgcd(b,a%b,y,x);
		y-=a/b*x;
	}
	return oo;
}
/*
1
2 11 100
*/
