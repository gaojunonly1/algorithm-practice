#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int main() {
	int n,m,a,b,c,d;
	int i,j,k;
	cin>>n>>m;
	cin>>a>>b>>c>>d;
	if(m<n+1||4==n) {
		cout<<"-1"<<endl;
		return 0;
	}
	cout<<a<<" "<<c<<" ";
	vector<int>jyl;
	for(i=1;i<=n;i++)
		if(a!=i&&b!=i&&c!=i&&d!=i) {
			cout<<i<<" ";
			jyl.pb(i);
		}
	cout<<d<<" "<<b<<endl;
	cout<<c<<" "<<a<<" ";
	for(auto oo:jyl)
		cout<<oo<<" ";
	cout<<b<<" "<<d<<endl;
    return 0;
}
