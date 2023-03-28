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

const int N1=100005;

struct BIT {
	#define lowbit(x) ((x)&(-x))
	int s[N1];
	void init();
	void add(int,int);
	int get(int);
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("test.in","r",stdin);
#endif

	int Q;
	cin>>Q;
	stack<int>jyl;
	BIT* t1=new BIT;
	t1->init();
	while(Q--) {
		char s[15];
		scanf("%s",s+1);
		int oo;
		if(s[2]=='u') {
			cin>>oo;
			jyl.push(oo);
			t1->add(oo,1);
		}
		else if(s[2]=='o') {
			if(jyl.empty()) {
				cout<<"Invalid"<<al;
			}
			else {
				oo=jyl.top();
				jyl.pop();
				t1->add(oo,-1);
				cout<<oo<<al;
			}
		}
		else {
			if(jyl.empty()) {
				cout<<"Invalid"<<al;
			}
			else {
				int l1=1,r1=100000,mid,wwx=0;
				while(l1<=r1) {
					int mid=(l1+r1)>>1;
					if(t1->get(mid)>=(jyl.size()+1)/2) {
						wwx=mid;
						r1=mid-1;
					}
					else {
						l1=mid+1;
					}
				}
				cout<<wwx<<al;
			}
		}
	}

    return 0;
}

void BIT::init() {
	memset(s,0,sizeof s);
}

void BIT::add(int x,int v) {
	while(x<=100000) {
		s[x]+=v;
		x+=lowbit(x);
	}
}

int BIT::get(int x) {
	int jyl=0;
	while(x>0) {
		jyl+=s[x];
		x-=lowbit(x);
	}
	return jyl;
}
