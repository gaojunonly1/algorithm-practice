#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	int i,j;
	cin>>n;
	vector<ll>a(n+5),b(n+5);
	for(i=0;i<=n;i++)
		cin>>a[i];
	for(i=0;i<=n;i++)
		cin>>b[i];
	ll wwx=0;
	for(i=n;i>=1;i--) {
		if(a[i]<b[i]) {
			int oo=(b[i]-a[i]+1)>>1;
			a[i-1]-=oo;
			wwx+=oo;
		}
	}
	if(a[0]>=b[0])
		cout<<wwx<<endl;
	else
		cout<<"-1"<<endl;
    return 0;
}
