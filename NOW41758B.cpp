#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
struct node {
	ll num[5];
	ll sz;
}wwx[1005];
char s1[1005];
ll s[1005];
void solve(int t1);
char calc(ll oo);
int main() {
	int i,T;
	scanf("%d",&T);
	for(i=1;i<=T;i++)
		solve(i);
    return 0;
}
void solve(int t1) {
	int i,j,k;
	int oo,pp,qq;
	scanf("%s",s1);
	for(i=0;i<128;i++)
		s[i]=s1[i]-'0';
	oo=0;
	for(i=0;i<128;i+=16) {
		pp=0;
		wwx[oo].sz=0;
		for(j=i;j<i+16;j+=4) {
			wwx[oo].num[pp]=s[j]*8+s[j+1]*4+s[j+2]*2+s[j+3];
			wwx[oo].sz=wwx[oo].sz*16+wwx[oo].num[pp];
			pp++;
		}
		oo++;
	}
	oo=pp=0;
	int l1=-1,r1=-1,l11,r11;
	for(i=0;i<8;i++) {
		if(wwx[i].sz==0)
			pp++;
		else {
			if(pp>=oo) {
				l1=i-pp;
				r1=i-1;
				oo=pp;
			}
			pp=0;
		}
	}
	if(pp>oo||pp==oo&&l1==0) {
		oo=pp;
		l1=7-pp+1;
		r1=7;
	}
	printf("Case #%d: ",t1);
	if(l1==0&&oo>1)
		printf(":");
	for(i=0;i<8;i++) {
		if(i==l1&&oo>=2) {
			printf(":");
			i=r1;
			continue;
		}
		for(j=0;j<3;j++)
			if(wwx[i].num[j]!=0)
				break;
		for(;j<4;j++)
			printf("%c",calc(wwx[i].num[j]));
		if(i!=7)
			printf(":");
	}
	printf("\n");
}
char calc(ll oo) {
	if(oo<=9)
		return (char)('0'+oo);
	else
		return (char)('a'+oo-10);
}
