#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
char s[2005],t[35];
map<char,char>jyl;
map<char,int>wwx;
void solve(int t1);
int main() {
	int i,T;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
		solve(i);
    return 0;
}
void solve(int t1) {
	int i,j,k;
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%s",t+1);
	for(i=1;i<=26;i++)
		jyl[(char)('a'+i-1)]=t[i];
	wwx.clear();
	for(i=1;i<=n;i++)
		wwx[jyl[s[i]]]++;
	if(wwx['h']*4>=n)
		printf("Case #%d: Harmful\n",t1);
	else if(wwx['h']*10<=n)
		printf("Case #%d: Recyclable\n",t1);
	else if(wwx['d']>=wwx['w']*2)
		printf("Case #%d: Dry\n",t1);
	else
		printf("Case #%d: Wet\n",t1);
}
