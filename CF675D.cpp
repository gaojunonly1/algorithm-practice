#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i;
	ll oo,mn;
	vector<ll>wwx;
	map<ll,ll>jyl;
	cin>>n;
	cin>>oo;
	mn=oo;
	jyl[oo]=1;
	jyl[-1]=0;
	for(i=1;i<n;i++) {
		cin>>oo;
		auto it=jyl.upper_bound(oo);
		auto it1=it;
		it1--;
		if(it==jyl.end())
			wwx.pb(it1->fi);
		else if(it1==jyl.begin())
			wwx.pb(it->fi);
		else if(it->se>it1->se)
			wwx.pb(it->fi);
		else
			wwx.pb(it1->fi);
		jyl[oo]=i+1;
	}
	for(auto tmp:wwx)
		cout<<tmp<<" ";
	return 0;
}
/*
10
991309218 517452607 870021923 978357992 136426010 10601767 302627526 883615372 163475700 600546765
10
10 5 7 9 2  1  4 8 3 6
*/
