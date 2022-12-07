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

const ll Mod=1000000007;

const int N1=100005;
int a[N1],b[N1],c[N1];
vector<int>jyl[N1];
int syf[N1];
ll wwx[N1];
ll fac[N1];

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
#endif
	int i,j,k;
	int oo,pp,qq;
	ll o,p,q;
	
	int n,m;
	scanf("%d%d",&n,&m);
	fz1(i,m) {
		scanf("%d",&a[i]);
		jyl[a[i]].pb(i);
	}
	fz1(i,m) {
		scanf("%d",&b[i]);
		jyl[b[i]].pb(i);
	}
	fz1(i,m) {
		scanf("%d",&c[i]);
		jyl[c[i]].pb(i);
	}
	int l1,r1=0,gj=0;
	fz1(l1,n) {
		if(l1>r1) {
			ff(jyl[l1],itr) {
				syf[*itr]++;
				if(syf[*itr]==1) {
					gj++;
				}
			}
			r1=l1;
		}
		while(r1<n&&gj!=m) {
			r1++;
			ff(jyl[r1],itr) {
				syf[*itr]++;
				if(syf[*itr]==1) {
					gj++;
				}
			}
		}
//		cout<<"!!! "<<l1<<" "<<r1<<" "<<gj<<endl;
		if(gj==m) {
			wwx[r1-l1+1]++;
			wwx[n-l1+2]--;
			ff(jyl[l1],itr) {
				syf[*itr]--;
				if(syf[*itr]==0) {
					gj--;
				}
			}
		}
		else {
			break;
		}
	}
	fz(i,2,n) {
		wwx[i]=wwx[i]+wwx[i-1];
	}
	fac[0]=1ll;
	fz1(i,n) {
		fac[i]=fac[i-1]*i%Mod;
	}
	fz1(i,n) {
//		cout<<"@@@  "<<i<<" "<<wwx[i]<<endl;
		printf("%lld ",fac[i]*wwx[i]%Mod);
	}
    return 0;
}
