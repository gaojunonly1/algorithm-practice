#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
#define fi first
#define se second
#define pb push_back
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int i;
	cin>>n;
	vector<pli>a(n);
	for(i=0;i<n;i++)
		cin>>a[i].fi;
	for(i=0;i<n;i++)
		cin>>a[i].se;
	sort(a.begin(),a.end());
	ll gg=a[0].fi;
	for(i=1;i<n;i++)
		gg=__gcd(gg,a[i].fi);
	if(1!=gg) {
		cout<<"-1"<<endl;
		return 0;
	}
	map<ll,int> dp;
	dp.clear();
	dp[0]=0;
	for(auto oo:a)
		for(auto it=dp.begin();it!=dp.end();it++) {
			ll pp=__gcd(it->fi,oo.fi);
			int qq=it->se+oo.se;
			if(0==dp.count(pp)||dp[pp]>qq)
				dp[pp]=qq;
		}
	cout<<dp[1]<<endl;
    return 0;
}
