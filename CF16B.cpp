#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
int n,m;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i;
	cin>>n>>m;
	vector<pii>jyl(m);
	for(i=0;i<m;i++)
		cin>>jyl[i].se>>jyl[i].fi;
	sort(jyl.begin(),jyl.end());
	reverse(jyl.begin(),jyl.end());
	ll wwx=0;
	for(i=0;i<m;i++) {
		if(n>=jyl[i].se) {
			n-=jyl[i].se;
			wwx+=1ll*jyl[i].fi*jyl[i].se;
		}
		else {
			wwx+=n*jyl[i].fi;
			break;
		}
	}
	cout<<wwx<<endl;
    return 0;
}
