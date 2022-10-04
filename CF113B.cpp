#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,n1,n2;
char t[2005],s1[2005],s2[2005];
int cnt=0;
vector<pair<ll,ll>>wwx;
struct hash {
	ll base1=31;
	ll base2=37;
	ll Mod1=1000000007;
	ll Mod2=998244353;
	int n;
	pair<ll,ll> has[2005],bin[2005];
	hash() {
		n=0;
		memset(has,0,sizeof has);
		return;
	}
	void pre(char *s) {
		n=strlen(s+1);
		bin[0].fi=bin[0].se=1ll; has[0].fi=has[0].se=0;
		for(int i=1;i<=n;i++) {
			bin[i].fi=bin[i-1].fi*base1%Mod1;
			bin[i].se=bin[i-1].se*base2%Mod2;
			has[i].fi=(has[i-1].fi*base1%Mod1+(s[i]-'a'+1))%Mod1;
			has[i].se=(has[i-1].se*base2%Mod2+(s[i]-'a'+1))%Mod2;
		}
	}
	pair<ll,ll> get(int l,int r) {
		pair<ll,ll> jyl;
		jyl.fi=has[r].fi;
		jyl.fi-=has[l-1].fi*bin[r-l+1].fi%Mod1;
		(jyl.fi+=Mod1)%=Mod1;
		jyl.se=has[r].se;
		jyl.se-=has[l-1].se*bin[r-l+1].se%Mod2;
		(jyl.se+=Mod2)%=Mod2;
		return jyl;
	}
}jyl,tou,wei;
int main() {
	int i,j;
	scanf("%s%s%s",t+1,s1+1,s2+1);
	n=strlen(t+1);
	n1=strlen(s1+1);
	n2=strlen(s2+1);
	jyl.pre(t);
	tou.pre(s1);
	wei.pre(s2);
	vector<int>ptou,pwei;
	for(i=1;i<=n;i++) {
		if(i+n1-1<=n&&jyl.get(i,i+n1-1)==tou.has[n1])
			ptou.pb(i);
		if(i+n2-1<=n&&jyl.get(i,i+n2-1)==wei.has[n2])
			pwei.pb(i);
	}
	for(i=0;i<ptou.size();i++) {
		for(j=0;j<pwei.size();j++) {
			if(ptou[i]<=pwei[j]&&ptou[i]+n1-1<=pwei[j]+n2-1) {
				wwx.pb(jyl.get(ptou[i],pwei[j]+n2-1));
			}
		}
	}
	sort(wwx.begin(),wwx.end());
	int lwj=wwx.size()?1:0;
	for(i=1;i<wwx.size();i++)
		if(wwx[i]!=wwx[i-1])
			lwj++;
	printf("%d\n",lwj);
    return 0;
}
