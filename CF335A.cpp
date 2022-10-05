#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int len,n;
char s[1005];
int cnt[30];
int wwx=-1;
int main() {
	int i,j,k;
	int oo,pp,qq;
	scanf("%s%d",s+1,&n);
	len=strlen(s+1);
	memset(cnt,0,sizeof cnt);
	for(i=1;i<=len;i++)
		cnt[s[i]-'a'+1]++;
	for(i=len;i>=1;i--) {
		oo=0;
		for(j=1;j<=26;j++)
			oo+=(cnt[j]+i-1)/i;
//		cout<<i<<" "<<oo<<endl;
		if(oo<=n)
			wwx=i;
		else
			break;
	} 
	printf("%d\n",wwx);
	if(wwx==-1)
		return 0;
	int jyl=0; 
	for(i=1;i<=26;i++) {
//		cout<<i<<' '<<(cnt[i]+wwx-1)/wwx<<endl;
		for(j=1;j<=(cnt[i]+wwx-1)/wwx;j++) {
			printf("%c",'a'+i-1);
			jyl++;
		}
	}
	while(jyl<n) {
		printf("%c",'a');
		jyl++;
	}
	printf("\n");
    return 0;
}
