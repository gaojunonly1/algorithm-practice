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

const char al='\n';

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
#endif

	int i,j;
	int n;
	cin>>n;
	vector<double>a(n+5),b(n+5);
	int wwx=0;
	fz1(i,n) {
		cin>>a[i]>>b[i];
//		cout<<"i="<<i<<endl;
		bool cb=0;
		fz1(j,i-1) {
			if(a[j]==a[i]&&b[j]==b[i]) {
				cb=1;
				break;
			}
		}
		if(1==cb) {
			continue;
		}
		set<pair<double,double> >jyl;
		fz1(j,i-1) {
			if(a[j]==a[i]) {
				continue;
			}
			else {
				double xx=(b[j]-b[i])/(a[i]-a[j]);
				double yy=a[i]*xx+b[i];
				jyl.insert(mp(xx,yy));
			}
		}
		wwx+=jyl.size()+1;
	}
	cout<<wwx+1<<al;
    return 0;
}
