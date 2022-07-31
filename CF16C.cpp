#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int main() {
	ll a,b,x,y;
	cin>>a>>b>>x>>y;
	ll gg=__gcd(x,y);
	x/=gg;
	y/=gg;
	if(a<x||b<y)
		cout<<0<<" "<<0<<endl;
	else if(a*y<b*x)
		cout<<a/x*x<<" "<<a/x*y<<endl;
	else if(a*y>b*x)
		cout<<b/y*x<<" "<<b/y*y<<endl;
	else
		cout<<a<<" "<<b<<endl;
    return 0;
}
