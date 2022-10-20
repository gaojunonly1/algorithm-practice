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
const double eps=1e-7;
const int N1=100005;
int n,m;
char s[N1],t[N1];
double a[N1];
int main() {
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	scanf("%s",s+1);
	scanf("%s",t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	for(i=1;i<=n;i++)
		a[100000-n+i]=(s[i]-'0');
	for(i=1;i<=m;i++)
		a[100000-m+i]-=(t[i]-'0');
//	for(i=99998;i<=100000;i++)
//		cout<<a[i]<<" ";
//	putchar('\n');
	for(i=100000-max(n,m)+1;i<=99998;i++) {
//		cout<<"i="<<i<<" "<<"ai="<<a[i]<<endl;
		a[i+1]+=a[i];
		a[i+2]+=a[i];
	}
	if(a[99999]>0&&a[100000]>0) {
		printf(">\n");
	}
	else if(a[99999]<0&&a[100000]<0) {
		printf("<\n");
	}
	else if(a[99999]==0&&a[100000]==0) {
		printf("=\n");
	}
	else {
//		cout<<a[99999]<<" "<<a[100000]<<endl;
		double wwx=a[99999]*(1+sqrt(5))/2+a[100000];
//		printf("wwx=%.6lf\n",wwx);
		if(wwx<0) {
			printf("<\n");
		}
		else {
			printf(">\n");
		}
	}
    return 0;
}
