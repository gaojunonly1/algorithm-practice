#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
string s;
int main() {
	int i,j,k;
	cin>>s;
	n=(int)s.size();
	int wwx=0;
	for(i=0;i<n;) {
		for(j=i+1;j<n;j++)
			if(s[j]!='0')
				break;
		if(j-i>i||j-i==i&&s[i]>s[0])
			wwx=1;
		else
			wwx++;
		i=j;
	}
	cout<<wwx<<endl;
    return 0;
}
