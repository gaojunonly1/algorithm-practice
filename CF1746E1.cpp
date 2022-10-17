#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
#define fafa fflush(stdout)
int n;
char s[15];
void solve(vector<int> &jyl);
bool getans();
int main() {
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	scanf("%d",&n);
	vector<int>jyl(0);
	for(i=1;i<=n;i++)
		jyl.pb(i);
	solve(jyl);
    return 0;
}
void solve(vector<int> &jyl) {
	if(jyl.size()<3) {
		printf("! %d\n",jyl[0]);
		fafa;
		scanf("%s",s+1);
		if(s[2]==')')
			return;
		printf("! %d\n",jyl[1]);
		fafa;
	}
	else if(jyl.size()==3) {
		bool o1,o2,o3,o4;
		printf("? 1 %d\n",jyl[0]);
		fafa;
		o1=getans();
		printf("? 1 %d\n",jyl[1]);
		fafa;
		o2=getans();
		printf("? 1 %d\n",jyl[1]);
		fafa;
		o3=getans();
		printf("? 1 %d\n",jyl[0]);
		fafa;
		o4=getans();
		vector<int>wwx(0);
		if(o2==o3) {
			if(o2==1) {
				wwx.pb(jyl[1]);
			}
			else {
				wwx.pb(jyl[0]);
				wwx.pb(jyl[2]);
			}
		}
		else {
			if((o1==1&&o2==1)||(o3==1&&o4==1)) {
				wwx.pb(jyl[0]);
				wwx.pb(jyl[1]);
			}
			else if((o1==1&&o2==0)||(o3==0&&o4==1)) {
				wwx.pb(jyl[0]);
				wwx.pb(jyl[2]);
			}
			else {
				wwx.pb(jyl[1]);
				wwx.pb(jyl[2]);
			}
		}
		solve(wwx);
	}
	else {
		cout<<endl;
		bool o1,o2;
		vector<int>jc[2];
		jc[0].resize(0);
		jc[1].resize(0);
		for(int i=0;i<(int)jyl.size();i++) {
			if((i+1)%4==1) {
				jc[0].pb(jyl[i]);
				jc[1].pb(jyl[i]);
			}
			else if((i+1)%4==2) {
				jc[0].pb(jyl[i]);
			}
			else if((i+1)%4==3) {
				jc[1].pb(jyl[i]);
			}
		}
		printf("? %d",jc[0].size());
		for(auto oo:jc[0])
			printf(" %d",oo);
		printf("\n");
		fafa;
		o1=getans();
		printf("? %d",jc[1].size());
		for(auto oo:jc[1])
			printf(" %d",oo);
		printf("\n");
		fafa;
		o2=getans();
		int lwj=-1;
		if(o1==0&&o2==0) {
			lwj=1;
		}
		else if(o1==0&&o2==1) {
			lwj=2;
		}
		else if(o1==1&&o2==0) {
			lwj=3;
		}
		else if(o1==1&&o2==1) {
			lwj=0;
		}
		vector<int>wwx(0);
		for(int i=0;i<(int)jyl.size();i++) {
			if((i+1)%4!=lwj) {
				wwx.pb(jyl[i]);
			}
		}
		solve(wwx);
	}
}
bool getans() {
	scanf("%s",s+1);
	return (s[1]=='Y')?1:0;
}
