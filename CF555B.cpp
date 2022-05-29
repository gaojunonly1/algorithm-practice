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
	int n,m;
	int i,j;
	cin>>n>>m;
	vector<pair<ll,ll>>island(n);
	for(i=0;i<n;i++)
		cin>>island[i].fi>>island[i].se;
	struct node {
		ll mn,mx;
		int id;
		bool operator<(const node &tmp)const {
			return (mx!=tmp.mx)?mx<tmp.mx:mn<tmp.mn;
		}
	};
	vector<node>jyl;
	for(i=1;i<n;i++)
		jyl.pb((node){island[i].fi-island[i-1].se,
			island[i].se-island[i-1].fi,i});
	sort(jyl.begin(),jyl.end());
	multiset<pair<ll,int>>s;
	for(i=0;i<m;i++) {
		ll oo;
		cin>>oo;
		s.insert(mp(oo,i));
	}
	vector<int>wwx(n);
	for(i=0;i<(size_t)jyl.size();i++) {
		auto it=s.lower_bound({jyl[i].mn,0});
		if(s.end()==it||it->fi>jyl[i].mx) {
			cout<<"No";
			return 0;
		}
		wwx[jyl[i].id]=it->se;
		s.erase(it);
	}
	cout<<"Yes"<<endl;
	for(i=1;i<n;i++)
		cout<<wwx[i]+1<<" ";
    return 0;
}
