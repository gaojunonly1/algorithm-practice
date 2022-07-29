#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
int a[1000005];
void solve();
int main() {
	int T;
	cin>>T;
	while(T--)
		solve();
    return 0;
}
void solve() {
	int i,j,k;
	cin>>n;
	for(i=0;i<=n;i++)
		cin>>a[i];
	for(i=n-1;i>=0;i--)
		a[i]+=a[i+1]/2;
	if(a[0])
		puts("Alice");
	else
		puts("Bob");
}
