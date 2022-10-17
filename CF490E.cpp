#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
int n;
char s[100005][15];
struct node {
	int tot;
	int num[15];
	int sz;
}a[100005];
int main() {
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%s",s[i]+1);
		a[i].tot=strlen(s[i]+1);
	}
	for(i=2;i<=n;i++) {
		if(a[i].tot<a[i-1].tot) {
			printf("NO\n");
			return 0;
		}
	}
	for(i=1;i<=a[1].tot;i++) {
		if(s[1][i]=='?') {
			a[1].num[i]=(i==1)?1:0;
		}
		else {
			a[1].num[i]=s[1][i]-'0';
		}
	}
	for(i=2;i<=n;i++) {
		if(a[i].tot>a[i-1].tot) {
			for(j=1;j<=a[i].tot-a[i-1].tot;j++) {
				if(s[i][j]=='?') {
					a[i].num[j]=(j==1)?1:0;
				}
				else {
					a[i].num[j]=s[i][j]-'0';
				}
			}
			for(j=a[i].tot-a[i-1].tot+1;j<=a[i].tot;j++) {
				if(s[i][j]=='?') {
					a[i].num[j]=0;
				}
				else {
					a[i].num[j]=s[i][j]-'0';
				}
			}
		}
		else {
			bool bo=0;
			int pos=-1;
			for(j=1;j<=a[i].tot;j++) {
				if(s[i][j]=='?') {
					if(bo) {
						a[i].num[j]=0;
					}
					else {
						a[i].num[j]=a[i-1].num[j];
					}
					if(a[i].num[j]!=9)
						pos=j;
				}
				else {
					a[i].num[j]=s[i][j]-'0';
					if(a[i].num[j]<a[i-1].num[j]&&(!bo)) {
						if(pos!=-1) {
							a[i].num[pos]++;
							for(k=pos+1;k<=j;k++) {
								if(s[i][k]=='?') {
									a[i].num[k]=0;
								}
							}
							bo=1;
						}
						else {
							printf("NO\n");
							return 0;
						}
					}
					else if(a[i].num[j]>a[i-1].num[j]) {
						bo=1;
					}
				}
			}
			if(!bo) {
				if(pos==-1) {
					printf("NO\n");
					return 0;
				}
				else {
					a[i].num[pos]++;
					for(j=pos+1;j<=a[i].tot;j++) {
						if(s[i][j]=='?') {
							a[i].num[j]=0;
						}
					}
				}
			}
		}
	}
	for(i=1;i<=n;i++) {
		a[i].sz=0;
		for(j=1;j<=a[i].tot;j++) {
			a[i].sz=a[i].sz*10+a[i].num[j];
		}
	}
	for(i=1;i<n;i++) {
		if(a[i].sz>a[i+1].sz) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for(i=1;i<=n;i++)
		printf("%d\n",a[i].sz);
    return 0;
}
