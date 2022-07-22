#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const ll Mod=1000000007;
ll ksm(ll x,ll y);
int main() {
	int T;
	ll n,m;
	cin>>T;
	ll jyl;
	jyl=ksm(2,Mod-2);
	while(T--) {
		cin>>n>>m;
		n-=m;
		cout<<n*jyl%Mod<<endl;
	}
    return 0;
}
ll ksm(ll x,ll y) {
	ll wwx=1;
	while(y) {
		if(y&1)
			wwx=wwx*x%Mod;
		x=x*x%Mod;
		y>>=1;
	}
	return wwx;
}
