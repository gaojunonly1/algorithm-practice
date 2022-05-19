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
	int n,m,k;
	int i,j;
	cin>>n>>m>>k;
	vector<int>a(n),b(m);
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a.begin(),a.end()); 
	for(i=0;i<m;i++)
		cin>>b[i];
	sort(b.begin(),b.end());
	vector<int>c,d;
	j=0;
	for(i=0;i<n;i++) {
		while(b[j]<a[i]&&j<(int)b.size()) {
			d.pb(b[j]);
			j++;
		}
		if(b[j]!=a[i])
			c.pb(a[i]);
		else
			j++;
	}
	for(;j<m;j++)
		d.pb(b[j]);
//	for(auto oo:c)
//		cout<<oo<<" ";
//	cout<<endl;
//	for(auto oo:d)
//		cout<<oo<<" ";
//	cout<<endl;
	if(0==c.size()&&0!=d.size()) {
		cout<<"NO"<<endl;
		return 0;
	}
	j=c.size()-1;
	for(i=(int)d.size()-1;i>=0&&j>=0;i--,j--)
		if(c[j]>d[i]) {
			cout<<"YES"<<endl;
			return 0;
		}
	if(j<0)
		cout<<"NO"<<endl;
	else
		cout<<"YES"<<endl;	
    return 0;
}
/*
15 15 10
4 5 9 1 4 6 4 1 4 3 7 9 9 2 6
6 6 7 7 2 9 1 6 10 9 7 10 7 10 9
*/
