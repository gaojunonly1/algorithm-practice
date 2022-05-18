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
	int n,m;
	int i;
	double oo;
	cin>>n>>m;
	vector<int>a(n);
	for(i=0;i<n;i++)
		cin>>a[i]>>oo;
	vector<int>b;
	for(i=0;i<n;i++) {
		if(0==b.size()||a[i]>=*b.rbegin())
			b.pb(a[i]);
		else {
			auto it=upper_bound(b.begin(),b.end(),a[i]);
			*it=a[i];
		}
	}
	cout<<n-b.size()<<endl;
    return 0;
}
