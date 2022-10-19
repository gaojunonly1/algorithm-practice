#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
#define iinf INT_MAX
const int N1=100005;
int n;
char s[N1];
int bj[N1];
ll solve(int l,int r);
int main() {
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	scanf("%s",s+1);
	n=strlen(s+1);
	vector<int>jyl;
	for(i=1;i<=n;i++) {
		if(s[i]=='*') {
			jyl.pb(i);
		}
	}
	ll wwx=solve(0,0);
	for(i=0;i<jyl.size();i++) {
		for(j=i+1;j<jyl.size();j++) {
			wwx=max(wwx,solve(jyl[i],jyl[j]));
		}
		wwx=max(wwx,solve(1,jyl[i]));
		wwx=max(wwx,solve(jyl[i],n));
	}
	printf("%lld\n",wwx);
    return 0;
}
ll solve(int l,int r) {
	int i;
	ll jyl=0,oo=1,jc=0;
	for(i=l;i<=r;i++) {
		if(isdigit(s[i])) {
			oo*=s[i]-'0';
		}
		else if(s[i]=='+') {
			jc+=oo;
			oo=1;
		}
	}
	jc+=oo;
	oo=1;
	for(i=1;i<=n;i++) {
		if(i==l) {
			oo*=jc;
			i=r;
			continue;
		}
		if(isdigit(s[i])) {
			oo*=s[i]-'0';
		}
		else if(s[i]=='+') {
			jyl+=oo;
			oo=1;
		}
	}
	jyl+=oo;
	return jyl;
}
