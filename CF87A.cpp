#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int main() {
	ll a,b,gg;
	cin>>a>>b;
	gg=__gcd(a,b);
	if(1==abs(a/gg-b/gg))
		cout<<"Equal"<<endl;
	else if(a<b)
		cout<<"Dasha"<<endl;
	else
		cout<<"Masha"<<endl; 
    return 0;
}
