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

map<pair<char,char>,bool>syf;

int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int oo,pp,qq;
	ll o,p,q;
	
	int n;
	scanf("%d\n",&n);
	string s;
	bool gj=1;
	fz1(i,n) {
		char a=' ',b=' ';
		while(a==' ')
			a=getchar();
		while(b==' ')
			b=getchar();
//		cout<<a<<" "<<b<<endl;
		getchar();
		if(a!='H'&&a!='D'&&a!='C'&&a!='S') {
			gj=0;
		}
		if(b!='A'&&b!='2'&&b!='3'&&b!='4'&&b!='5'&&b!='6'&&b!='7'&&b!='8'&&b!='9'&&b!='T'&&b!='J'&&b!='Q'&&b!='K') {
			gj=0;
		}
		if(syf[mp(a,b)]) {
			gj=0;
		}
		syf[mp(a,b)]=1;
	}
	if(gj==1) {
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}

    return 0;
}
