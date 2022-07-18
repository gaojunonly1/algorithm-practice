#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int main() {
	ll a,b,k;
	cin>>k>>a>>b;
	ll wwx=0;
	if(0>=a&&0>=b) {
		swap(a,b);
		a*=-1;
		b*=-1;
	}
	if(0>=a&&0<=b)
		wwx=-a/k+b/k+1;
	else
		wwx=b/k-(a-1)/k;
	cout<<wwx<<endl;
    return 0;
}
