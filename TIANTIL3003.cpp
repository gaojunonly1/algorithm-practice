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

const int N1=1005;

bitset<1000>a[N1];

struct Bingcj {
	int fa[N1],sz[N1];
	void chush(int n);
	int getfa(int x);
	void heb(int x,int y);
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
#endif

	int i,j;
	int n;
	cin>>n;
	fz1(i,n) {
		int m,oo;
		cin>>m;
		char ch=' ';
		while(ch!=':') {
			ch=getchar();
		}
		fz1(j,m) {
			cin>>oo;
			a[i][oo]=1;
		}
	}
	Bingcj *b1=new Bingcj;
	b1->chush(n);
	fz1(i,n-1) {
		fz(j,i+1,n) {
			if((a[i]&a[j])!=0) {
//				cout<<i<<" "<<j<<" "<<(a[i]&a[j])<<al;
				b1->heb(i,j);
			}
		}
	}
	vector<int>wwx;
	fz1(i,n) {
		if(b1->sz[i]) {
			wwx.pb(b1->sz[i]);
		}
	}
	sort(wwx.begin(),wwx.end());
	reverse(wwx.begin(),wwx.end());
	cout<<wwx.size()<<al;
	fz0k(i,wwx.size()) {
		cout<<wwx[i];
		if(i!=wwx.size()-1) {
			cout<<" ";
		}
	}
    return 0;
}

void Bingcj::chush(int n) {
	int i;
	for(i=1;i<=n;i++) {
		fa[i]=i;
		sz[i]=1;
	}
}

int Bingcj::getfa(int x) {
	if(x==fa[x]) {
		return x;
	}
	else {
		return fa[x]=getfa(fa[x]);
	}
}

void Bingcj::heb(int x,int y) {
	int fx=getfa(x),fy=getfa(y);
	if(fx==fy) {
		return;
	}
	fa[fx]=fy;
	sz[fy]+=sz[fx];
	sz[fx]=0;
}
