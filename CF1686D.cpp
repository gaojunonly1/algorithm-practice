#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,len;
char s[200005];
int a,b,ab,ba;
int cnta,cntb;
void solve();
int main() {
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
    return 0;
}
void solve() {
	int i;
	int oo,pp,qq;
	int jyl,cntab,cntba;
	scanf("%d%d%d%d",&a,&b,&ab,&ba);
	scanf("%s",s+1);
	n=strlen(s+1);
	cnta=cntb=0;
	for(i=1;i<=n;i++) {
		cnta+=(s[i]=='A');
		cntb+=(s[i]=='B');
	}
	if(cnta!=a+ab+ba||cntb!=b+ab+ba) {
		printf("NO\n");
		return;
	}
	oo=1;
	jyl=0;
	cntab=cntba=0;
	vector<int>AB,BA;
	for(i=2;i<=n;i++) {
		if(s[i]!=s[i-1]) {
			oo++;
			continue;
		}
		else {
			if(s[i-oo]==s[i-1])
				jyl+=oo/2;
			else if(s[i-oo]=='A') {
				cntab+=oo/2;
				AB.pb(oo/2);
			}
			else {
				cntba+=oo/2;
				BA.pb(oo/2);
			}
			oo=1;
		}
	}
	if(s[n]==s[n-oo+1])
		jyl+=oo/2;
	else if(s[n-oo+1]=='A') {
		cntab+=oo/2;
		AB.pb(oo/2);
	}
	else {
		cntba+=oo/2;
		BA.pb(oo/2);
	}
	sort(AB.begin(),AB.end());
	reverse(AB.begin(),AB.end());
	sort(BA.begin(),BA.end());
	reverse(BA.begin(),BA.end());
//	cout<<"@@@@@@@@@   "<<cntab<<" "<<cntba<<" "<<jyl<<endl;
	if(cntab+cntba+jyl<ab+ba) {
		printf("NO\n");
		return;
	}
//	puts("2333333");
	if(cntab<ab) {
		oo=min(jyl,ab-cntab);
		cntab+=oo;
		jyl-=oo;
	}
	if(cntba<ba) {
		oo=min(jyl,ba-cntba);
		cntba+=oo;
		jyl-=oo;
	}
	for(auto tmp:AB) {
		if(cntab-2<ab)
			break;
		oo=min(cntab-ab,tmp);
//		cout<<"oo="<<oo<<endl;
		cntab-=oo;
		cntba+=oo-1;
	}
	for(auto tmp:BA) {
		if(cntba-2<ba)
			break;
		oo=min(cntba-ba,tmp);
		cntba-=oo;
		cntab+=oo-1;
	}
	if(cntab>=ab&&cntba>=ba)
		printf("YES\n");
	else
		printf("NO\n");
}
