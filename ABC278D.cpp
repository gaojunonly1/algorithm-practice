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

const int N1=200005;

int n;
ll a[N1];
ll b[N1];
vector<ll> qzh[N1];
vector<ll> jyl[N1];

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
#endif
	int i,j,k;
	int oo,pp,qq;
	ll o,p,q;
	
	scanf("%d",&n);
	fz1(i,n) {
		scanf("%lld",&a[i]);
		qzh[i].pb(0);
		jyl[i].pb(0);
	}
	int Q;
	scanf("%d",&Q);
	ll num=-1,pos=-1;
	fz1(i,Q) {
		scanf("%d",&oo);
		if(oo==1) {
			scanf("%lld",&o);
			num=o;
			pos=i;
		}
		else if(oo==2) {
			scanf("%d%lld",&pp,&o);
			ll tmp=*qzh[pp].rbegin();
			qzh[pp].pb(tmp+o);
			jyl[pp].pb(i);
		}
		else if(oo==3) {
			scanf("%d",&pp);
			ll syf;
			if(pos==-1) {
				syf=a[pp];
				syf+=(*qzh[pp].rbegin());
			}
			else {
				syf=num;
				int itr=lower_bound(jyl[pp].begin(),jyl[pp].end(),pos)-jyl[pp].begin()-1;
				syf+=(*qzh[pp].rbegin());
				syf-=qzh[pp][itr];
			}
			printf("%lld\n",syf);
		}
	}

    return 0;
}
