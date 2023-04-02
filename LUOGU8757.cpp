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

const char al='\n';

const ll Mod=1000000007;

const int N1=1000005;

ll fac[N1],inv[N1],invf[N1];

ll C(ll,ll);

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
#endif

	ll i,j;
	int T;
	ll n;
	cin>>T;
	fac[0]=1;
	fz1(i,1000000) {
		fac[i]=fac[i-1]*i%Mod;
	}
	inv[0]=inv[1]=1;
	invf[0]=invf[1]=1;
	fz(i,2,1000000) {
		inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
		invf[i]=invf[i-1]*inv[i]%Mod;
	}
	while(T--) {
		cin>>n;
		if(n==1) {
			puts("1");
			continue;
		}
		fz0g(i,1000) {
			if((1ll<<i)>n) {
				break;
			}
		}
		i--;
		ll oo=i;
		ll wwx;
		if((1ll<<(oo-1))*3>n) {
			ll jyl=0;
			fz0g(i,oo) {
				jyl+=(1ll<<i);
			}
			wwx=C(n,(oo+1))*fac[n-oo-1]%Mod*jyl%Mod;
		}
		else {
			ll jyl=0;
			fz0g(i,oo) {
				jyl+=(1ll<<i);
			}
			ll yzy=0;
			fz0k(i,oo) {
				yzy+=(1ll<<i);
				ll jwy=0;
				fz(j,i+1,oo) {
					jwy+=(1ll<<(j-1))*3;
				}
				jyl+=jwy+yzy;
			}
			wwx=C(n,(oo+1))*fac[n-oo-1]%Mod*jyl%Mod;
		}
		cout<<wwx<<al;
	}
    return 0;
}

ll C(ll n,ll m) {
	return fac[n]*invf[m]%Mod*invf[n-m]%Mod;
}
