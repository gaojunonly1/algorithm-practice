#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
typedef pair<int,int> pii;
int n,m,s,f;
map<int,pii>jyl;
void whlw(int st,int en,char ch,int step);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>s>>f;
	for(int i=1;i<=m;i++) {
		int o,p,q;
		cin>>o>>p>>q;
		jyl[o]=make_pair(p,q);
	}
	if(s<f)
		whlw(s,f,'R',1);
	else
		whlw(s,f,'L',-1);
	return 0;
}
void whlw(int st,int en,char ch,int step) {
	int tim=1;
	vector<char>wwx;
	while(st^en) {
		if(1==jyl.count(tim)) {
			if(st>=jyl[tim].fi&&st<=jyl[tim].se||st+step>=jyl[tim].fi&&st+step<=jyl[tim].se)
				wwx.pb('X');
			else {
				wwx.pb(ch);
				st+=step;
			}
		}
		else {
			wwx.pb(ch);
			st+=step;
		}
		tim++;
	}
	for(auto oo:wwx)
		cout<<oo;
	return;
}
