#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
#define pb push_back
typedef pair<int,int> pii;
#define fi first
#define se second
vector<pii>jyl[100005];
bool cmp(pii pp,pii qq);
ll wwx;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j,oo;
	ll jfm,yzy;
	cin>>n>>m;
	for(i=1;i<=n;i++) {
		for(j=1;j<=m;j++) {
			cin>>oo;
			jyl[oo].pb(pii(i,j));
		}
	}
	for(i=1;i<=100000;i++)
		if(jyl[i].size()>1) {
			sort(jyl[i].begin(),jyl[i].end());
			jfm=yzy=0;
			for(j=0;j<(int)jyl[i].size();j++) {
				if(j!=0)
					wwx+=yzy*jyl[i][j].fi-jfm;
				jfm+=jyl[i][j].fi;
				yzy++;
			}
			sort(jyl[i].begin(),jyl[i].end(),cmp);
			jfm=yzy=0;
			for(j=0;j<(int)jyl[i].size();j++) {
				if(j!=0)
					wwx+=yzy*jyl[i][j].se-jfm;
				jfm+=jyl[i][j].se;
				yzy++;
			}
		}
	cout<<wwx<<endl;
	return 0;
}
bool cmp(pii pp,pii qq) {
	return pp.se<qq.se;
}
