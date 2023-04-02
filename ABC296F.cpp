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

//单点修改+单点查询
class Tree {
	#define lowbit(x) ((x)&(-x))
	public:
		Tree() {
			memset(s,0,sizeof s);
		}
		Tree(int n1) {
			n=n1;
			memset(s,0,sizeof s);
		}
		void Add(int x,int z) {
			for(int i=x;i>0;i-=lowbit(i))
				s[i]+=z;
		}
		int Ask(int x) {
			int jyl=0;
			for(int i=x;i<=n;i+=lowbit(i))
				jyl+=s[i];
			return jyl;
		}
	private:
		int n;
		int s[200005];
};

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("test.in","r",stdin);
//#endif

	int i;
	int N;
	cin>>N;
	int A[200005],B[200005];
	Tree *ta=new Tree(N);
	Tree *tb=new Tree(N);
	int jyl=0;
	fz1(i,N) {
		cin>>A[i];
		jyl+=ta->Ask(A[i]+1);
		ta->Add(A[i],1);
	}
	fz1(i,N) {
		cin>>B[i];
		jyl+=tb->Ask(B[i]+1);
		tb->Add(B[i],1);
	}
	sort(A+1,A+N+1);
	sort(B+1,B+N+1);
	bool wwx=0;
	fz1(i,N) {
		if(A[i]!=B[i]) {
			puts("No");
			return 0;
		}
		else if(i!=1&&A[i-1]==A[i]) {
			wwx=1;
		}
	}
	if(1==wwx) {
		puts("Yes");
	}
	else {
		(jyl&1)?puts("No"):puts("Yes");
	}

    return 0;
}
