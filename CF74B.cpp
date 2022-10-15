#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,m,K;
int len;
char s[15];
int main() {
	int i,j,k;
	ll oo,pp,qq;
	int bo;
	scanf("%d%d%d",&n,&K,&m);
	scanf("\nto %s",s+1);
	bo=(s[1]=='h')?-1:1;
	scanf("%s",s+1);
	K=(K<m)?-1:1;
	len=strlen(s+1);
	for(i=1;i<=len;i++) {
		if(s[i]=='1')
			K=-bo;
		m+=bo;
		if(m==n||m==1) {
			if(K==-1&&m==1||K==1&&m==n) {
				printf("Controller %d\n",i);
				return 0;
			}
			bo=-bo;
		}
	}
	printf("Stowaway\n");
    return 0;
}
