#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	cout<<(5+(n-1)*6)*k<<endl;
	int i;
	for(i=0;i<n;i++)
		cout<<(1+i*6)*k<<" "<<(2+i*6)*k<<" "<<(3+i*6)*k<<" "<<(5+i*6)*k<<endl;
    return 0;
}
