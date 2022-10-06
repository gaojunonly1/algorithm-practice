#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
char s[100005];
int top;
char jyl[100005];
int wwx;
int main() {
	int i,j,k;
	int oo,pp,qq;
	scanf("%s",s+1);
	n=strlen(s+1);
	top=0;
	wwx=0;
	for(i=1;i<=n;i++) {
		jyl[++top]=s[i];
		while(top>=3) {
			if(jyl[top]==jyl[top-1]&&jyl[top-1]==jyl[top-2]) {
				wwx++;
				top-=3;
			}
			else
				break;
		}
	}
	printf("%d\n",wwx);
    return 0;
}
