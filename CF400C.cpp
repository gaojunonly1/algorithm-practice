#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,m;
pii play1(pii now,int jyl);
pii play2(pii now,int jyl);
pii play3(pii now,int jyl);
int main() {
	int nn,mm,x,y,z,p;
	int i,j,k;
	int a,b;
	cin>>nn>>mm>>x>>y>>z>>p;
	for(i=0;i<p;i++) {
		cin>>a>>b;
		auto wwx=mp(a,b);
		n=nn; m=mm;
		wwx=play1(wwx,x%4);
		wwx=play2(wwx,y%2);
		wwx=play3(wwx,z%4);
		cout<<wwx.fi<<" "<<wwx.se<<endl;
	}
    return 0;
}
pii play1(pii now,int jyl) {
	while(jyl--) {
		auto oo=now;
		now.fi=oo.se;
		now.se=n-oo.fi+1;
		swap(n,m);
	}
	return now;
}
pii play2(pii now,int jyl) {
	while(jyl--)
		now.se=m-now.se+1;
	return now;
}
pii play3(pii now,int jyl) {
	while(jyl--) {
		auto oo=now;
		now.se=oo.fi;
		now.fi=m-oo.se+1;
		swap(n,m);
	}
	return now;
}
