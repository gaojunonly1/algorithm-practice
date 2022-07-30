#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
inline int rd(){
	int x=0;char c=getchar();bool f=0;
	while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f?-x:x;
}
int n,a[500005],b[500005];
int x[500005],y[500005];
void solve();
bool whlw();
bool check(int xx,int yy);
bool pd(int x,int y);
int main() {
	int T;
	cin>>T;
	while(T--)
		solve();
    return 0;
}
void solve() {
	int i,j,k;
	n=rd();
	for(i=1;i<=n;i++) {
		a[i]=rd();
		b[i]=rd();
	}
	for(i=1;i<=n;i++) {
		x[i]=a[i];
		y[i]=b[i];
	}
	if(whlw()) {
		cout<<"YES"<<endl;
		return;
	}
	for(i=1;i<=n;i++) {
		x[i]=b[i];
		y[i]=a[i];
	}
	if(whlw()) {
		cout<<"YES"<<endl;
		return;
	}
	for(i=1;i<=n;i++) {
		x[i]=a[i]+b[i];
		y[i]=a[i]-b[i];
	}
	if(whlw()) {
		cout<<"YES"<<endl;
		return;
	}
	for(i=1;i<=n;i++) {
		x[i]=a[i]-b[i];
		y[i]=a[i]+b[i];
	}
	if(whlw()) {
		cout<<"YES"<<endl;
		return;
	}
	cout<<"NO"<<endl;
}
bool whlw() {
	int i;
	bool bo=1;
	for(i=2;i<=n;i++) {
		if(x[i]==x[1])
			continue;
		bo=0;
		if(check(x[1],y[i]))
			return 1;
		if(check(x[1],y[i]+(x[i]-x[1])))
			return 1;
		if(check(x[1],y[i]-(x[i]-x[1])))
			return 1;
		break;
	}
	if(bo)
		return 1;
	return 0;
}
bool check(int xx,int yy) {
	int i;
	for(i=1;i<=n;i++)
		if(!pd(xx-x[i],yy-y[i]))
			return 0;
	return 1;
}
bool pd(int x,int y) {
	if(0==x||0==y||x==y||0==x+y)
		return 1;
	return 0;
}
