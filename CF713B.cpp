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

#define FF fflush(stdout);

struct rec {
	int x1,y1,x2,y2;
	void print() {
		printf("%d %d %d %d ",x1,y1,x2,y2);
	}
}syf;

void solve(rec &r);

int ask(int a,int b,int c,int d);


int main() {
//	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	
	int n;
	scanf("%d",&n);	
	rec r1,r2;
	
	int l1=1,rr=n;
	bool flg=0;
	while(l1<=rr) {
		int mid=(l1+rr)>>1;
		if(mid==n)
			break;
		p=ask(1,1,mid,n);
		q=ask(mid+1,1,n,n);
		if(p&&q) {
			flg=1;
			r1=(rec){1,1,mid,n};
			r2=(rec){mid+1,1,n,n};
			break;
		}
		else if(p) {
			rr=mid-1;
		}
		else {
			l1=mid+1;
		}
	}
	if(!flg) {
		l1=1;
		rr=n;
		while(l1<=rr) {
			int mid=(l1+rr)>>1;
			p=ask(1,1,n,mid);
			q=ask(1,mid+1,n,n);
			if(p&&q) {
				flg=1;
				r1=(rec){1,1,n,mid};
				r2=(rec){1,mid+1,n,n};
				break;
			}
			else if(p) {
				rr=mid-1;
			}
			else {
				l1=mid+1;
			}
		}
	}
	solve(r1);
	solve(r2);
	printf("! ");
	r1.print();
	r2.print();
	printf("\n");
	FF
    return 0;
}

void solve(rec &r) {
	int l1,r1,mid,o;
	l1=r.x1;
	r1=r.x2;
	while(l1<=r1) {
		mid=(l1+r1)>>1;
		o=ask(mid,r.y1,r.x2,r.y2);
		if(o==0) {
			r1=mid-1;
		}
		else {
			r.x1=mid;
			l1=mid+1;
		}
	}
	
	l1=r.x1;
	r1=r.x2;
	while(l1<=r1) {
		mid=(l1+r1)>>1;
		o=ask(r.x1,r.y1,mid,r.y2);
		if(o==0) {
			l1=mid+1;
		}
		else {
			r.x2=mid;
			r1=mid-1;
		}
	}
	
	l1=r.y1;
	r1=r.y2;
	while(l1<=r1) {
		mid=(l1+r1)>>1;
		o=ask(r.x1,mid,r.x2,r.y2);
		if(o==0) {
			r1=mid-1;
		}
		else {
			r.y1=mid;
			l1=mid+1;
		}
	}
	
	l1=r.y1;
	r1=r.y2;
	while(l1<=r1) {
		mid=(l1+r1)>>1;
		o=ask(r.x1,r.y1,r.x2,mid);
		if(o==0) {
			l1=mid+1;
		}
		else {
			r.y2=mid;
			r1=mid-1;
		}
	}
	
//	cout<<"r="<<r.x1<<" "<<r.y1<<" "<<r.x2<<" "<<r.y2<<endl;
}

int ask(int a,int b,int c,int d) {
	int oo;
	printf("? %d %d %d %d\n",a,b,c,d);
	FF
	scanf("%d",&oo);
	FF
	return oo;
}
