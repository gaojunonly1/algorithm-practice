#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
bool jyl=1;
string s,wwx;
void dfs();
int main() {
	int i,j,k;
	ll oo,pp,qq;
	scanf("%d",&n);
	dfs();
	if(0==jyl)
		printf("Error occurred\n");
	else {
		if(cin>>s)
			printf("Error occurred\n");
		else
			printf("%s\n",wwx.c_str());
	}
    return 0;
}
void dfs() {
	if(0==jyl)
		return;
	if(cin>>s) {
		wwx+=s;
		if(s=="pair") {
			wwx+="<";
			dfs();
			wwx+=",";
			dfs();
			wwx+=">";
		}
	}
	else
		jyl=0;
}
