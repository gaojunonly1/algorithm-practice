#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n,m;
string s;
vector<int>wwx(26,0);
bool mdzs(char o);
int main() {
	int i,j,k;
	cin>>m;
	cin>>s;
	n=(int)s.size();
	if(m>=n) {
		char ch='z';
		for(i=0;i<n;i++)
			ch=min(ch,s[i]);
		cout<<ch<<endl;
		return 0;
	}
	for(char o='a';o<='z';o++) {
		bool jyl=mdzs(o);
		if(1==jyl) {
			for(i=0;i<26;i++)
				while(wwx[i]--)
					cout<<(char)('a'+i);
			break;
		}
	}
    return 0;
}
bool mdzs(char o) {
	int i;
	for(i=0;i<26;i++)
		wwx[i]=0;
	int o_pos=-1,las=-1;
	for(i=0;i<n;i++) {
		if(o>s[i]) {
			wwx[s[i]-'a']++;
			las=i;
		}
		else if(o==s[i])
			o_pos=i;
		if(i-las>=m) {
			if(-1!=o_pos&&i-o_pos<m) {
				las=o_pos;
				wwx[o-'a']++;
				continue;
			}
			else
				return false;
		}
	}
	return true;
}
