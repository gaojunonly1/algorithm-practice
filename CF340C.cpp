#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<ll>a(n);
	int i;
	ll jyl=0,wwx=0;
	for(i=0;i<n;i++) {
		cin>>a[i];
		wwx+=a[i];
	}
	sort(a.begin(),a.end());
	for(i=0;i<n-1;i++) {
		jyl+=(a[i+1]-a[i])*(i+1);
		wwx+=jyl*2;
	}
	ll gg=__gcd(wwx,1ll*n);
	cout<<wwx/gg<<" "<<n/gg;
    return 0;
}
