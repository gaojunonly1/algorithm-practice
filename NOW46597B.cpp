#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
#define iinf INT_MAX

const int N1=100005;
char s1[N1],s2[N1];

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
#endif
	int i,j,k;
	int oo,pp,qq;
	ll o,p,q;
	scanf("%s",s1+1);
	scanf("%s",s2+1);
	pp=(int)(s1[strlen(s1+1)]-'0');
	qq=(int)(s2[1]-'0');
	bool flg=0,ff=0;
	fz1(i,strlen(s2+1)) {
		if(s2[i]!='0') {
			flg=1;
		}
	}
	fz(i,2,strlen(s2+1)) {
		if(s2[i]!='0') {
			ff=1;
		}
	}
	if(qq<5) {
		if(flg==0) {
			printf("PLMM\n");
		}
		else {
			printf("Happy birthday to YXGG\n");
		}
	}
	else if(qq==5&&ff==0) {
		if(pp&1) {
			printf("Happy birthday to MFGG\n");
		}
		else {
			printf("Happy birthday to YXGG\n");
		}
	}
	else {
		printf("Happy birthday to MFGG\n");
	}
    return 0;
}
