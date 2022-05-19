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
	int i,j;
	cin>>n>>m;
	vector<int>a(n);
	for(i=0;i<n;i++)
		cin>>a[i];
	int pos=-1,tot;
	for(i=0;i<n;i++) {
		vector<int>b(n);
		int cnt=0;
		bool flg=0;
		for(j=0;j<n;j++) {
			b[j]=a[i]+(j-i)*m;
			if(0>=b[j]) {
				flg=1;
				break;
			}
			if(b[j]!=a[j])
				cnt++;
		}
		if(flg)
			continue;
		if(-1==pos||cnt<tot) {
			pos=i;
			tot=cnt;
		}
	}
	cout<<tot<<endl;
	for(i=0;i<n;i++) {
		int oo=a[pos]+(i-pos)*m;
		if(oo<a[i])
			cout<<"- "<<i+1<<" "<<a[i]-oo<<endl;
		else if(oo>a[i])
			cout<<"+ "<<i+1<<" "<<oo-a[i]<<endl;
	}
    return 0;
}
