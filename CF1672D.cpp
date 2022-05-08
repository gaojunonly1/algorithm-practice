#include <bits/stdc++.h>
using namespace std;
int T,n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	cin>>T;
	while(T--) {
		cin>>n;
		map<int,int>jyl;
		vector<int>a(n),b(n);
		for(i=0;i<n;i++)
			cin>>a[i];
		for(i=0;i<n;i++)
			cin>>b[i];
		i=j=0;
		while(true) {
			if(i==n||j==n) {
				if(i==n&&j==n)
					puts("YES");
				else
					puts("NO");
				break;
			}
			if(i<n&&a[i]!=b[j]) {
				jyl[a[i]]++;
				i++;
				continue;
			}
			if(jyl[b[j]]) {
				jyl[b[j]]--;
				j++;
			}
			else {
				i++;
				j++;
			}
		}
	}
	return 0;
}
