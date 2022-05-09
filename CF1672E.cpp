#include <bits/stdc++.h>
using namespace std;
int ask(int oo);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,jyl,wwx=40000000;
	int i,oo;
	cin>>n;
	int l1=1,r1=40000000,mid;
	while(l1<=r1) {
		mid=(l1+r1)>>1;
		if(ask(mid)==1) {
			jyl=mid;
			r1=mid-1;
		}
		else
			l1=mid+1;
	}
	for(i=1;i<=n;i++) {
		oo=ask(jyl/i);
		if(oo)
			wwx=min(wwx,jyl/i*oo);
	}
	cout<<"! "<<wwx<<endl;
	cout.flush();
	return 0;
}
int ask(int oo) {
	cout<<"? "<<oo<<endl;
	cout.flush();
	int pp;
	cin>>pp;
	return pp;
}
