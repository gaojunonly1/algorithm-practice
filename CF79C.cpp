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
char s[N1];
int jyl[N1];
void solve(char *t,char *s);
int main() {
	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	int n,len;
	scanf("%s",s+1);
	len=strlen(s+1);
	memset(jyl,-1,sizeof jyl);
	scanf("%d",&n);
	char t[15];
	for(i=1;i<=n;i++) {
		scanf("%s",t+1);
		solve(t,s);
	}
	vector<pii>jc;
	int mn=len+1;
	for(i=len;i>=1;i--) {
		if(jyl[i]!=-1) {
			if(i+jyl[i]-1<mn) {
				jc.pb(mp(i,jyl[i]));
				mn=i+jyl[i]-1;
			}
		}
	}
	reverse(jc.begin(),jc.end());
	if(jc.size()==0) {
		printf("%d 0\n",len);
		return 0;
	}
	int wwx=0;
	int pos=1;
	if(jc[0].fi>1) {
		pos=1;
		wwx=jc[0].fi+jc[0].se-2;
	}
//	cout<<"wwx="<<wwx<<endl;
	if(jc.size()>1) {
		for(i=0;i<jc.size()-1;i++) {
			o=(jc[i+1].fi+jc[i+1].se-2)-(jc[i].fi+1)+1;
			if(o>wwx) {
				wwx=o;
				pos=jc[i].fi+1;
			}
		}
	}
	o=len-(jc[jc.size()-1].fi+1)+1;
	if(o>wwx) {
		wwx=o;
		pos=jc[jc.size()-1].fi+1;
	}
	printf("%d %d\n",wwx,pos-1);
    return 0;
}
void solve(char *t,char *s) {
	int fail[15];
	int n=strlen(t+1),len=strlen(s+1);
	fail[0]=fail[1]=0;
	int i,j=0;
	for(i=2;i<=n;i++) {
		while(j&&t[j+1]!=t[i]) {
			j=fail[j];
		}
		if(t[j+1]==t[i]) {
			j++;
		}
		fail[i]=j;
	}
	j=0;
	for(i=1;i<=len;i++) {
		while(j&&t[j+1]!=s[i]) {
			j=fail[j];
		}
		if(t[j+1]==s[i]) {
			j++;
		}
		if(j==n) {
			if(jyl[i-n+1]==-1) {
				jyl[i-n+1]=n; 
			}
			else {
				jyl[i-n+1]=min(jyl[i-n+1],n);
			}
		}
	}
}
