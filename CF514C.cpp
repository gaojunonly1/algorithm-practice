#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
string s;
vector<bool>bo(3000005,0);
struct TrieNode {
	TrieNode *son[3];
	bool jyl;
	TrieNode() {
		for(int i=0;i<3;i++)
			son[i]=NULL;
		jyl=0;
	}
};
void Trie_insert(string s,TrieNode &rt);
bool wwx;
void Trie_dfs(TrieNode *u,bool changed,int now,int len);
int main() {
	int n,m;
	int i,j,k;
	cin>>n>>m;
	TrieNode rt;
	for(i=1;i<=n;i++) {
		cin>>s;
		bo[(int)s.size()]=1;
		Trie_insert(s,rt);
	}
	for(i=1;i<=m;i++) {
		cin>>s;
		if(0==bo[(int)s.size()]) {
			cout<<"NO"<<endl;
			continue;
		}
		wwx=0;
		Trie_dfs(&rt,0,0,(int)s.size());
		if(1==wwx)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
    return 0;
}
void Trie_insert(string s,TrieNode &rt) {
	TrieNode *p=&rt;
	for(auto o:s) {
		int oo=o-'a';
		if(NULL==p->son[oo])
			p->son[oo]=new TrieNode();
		p=p->son[oo];
	}
	p->jyl=1;
}
void Trie_dfs(TrieNode *u,bool changed,int now,int len) {
	if(now==len) {
		if(1==changed&&1==u->jyl)
			wwx=1;
		return;
	}
	for(int i=0;i<3;i++) {
		if(NULL!=u->son[i]) {
			if(i==(int)s[now]-'a')
				Trie_dfs(u->son[i],changed,now+1,len);
			else {
				if(1==changed)
					continue;
				Trie_dfs(u->son[i],1,now+1,len);
			}
		}
	}
}
