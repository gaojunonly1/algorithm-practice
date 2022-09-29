#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
char s[65];
char wwx[20000005];
void solve(int &l,int &r);
int main() {
	int i;
	scanf("%d",&n);
	s[1]='a';
	s[27]='0';
	s[37]='A';
	for(i=2;i<=26;i++)
		s[i]=(char)(s[i-1]+1);
	for(i=28;i<=36;i++)
		s[i]=(char)(s[i-1]+1);
	for(i=38;i<=62;i++)
		s[i]=(char)(s[i-1]+1);
	int l1=1,r1=2e7;
	while(n--)
		solve(l1,r1);
	int abld=l1-1;
	for(i=r1+1;i<=2e7;i++) {
		wwx[l1]=wwx[i];
		l1++;
	}
	printf("%c",wwx[1]);
	for(i=100;i<l1;i+=100)
		printf("%c",wwx[i]);
	printf(" %d",abld);
    return 0;
}
void solve(int &l,int &r) {
	int i,j,k;
	int opt,len;
	scanf("%d%d",&opt,&len);
	if(opt==1) {
		for(i=1;i<=len;i++) {
			char oo=s[(i-1)%62+1];
			wwx[l]=oo;
			l++;
		}
	}
	else {
		for(i=1;i<=len;i++) {
			wwx[r]=wwx[l-1];
			l--;
			r--;
		}
	}
}
