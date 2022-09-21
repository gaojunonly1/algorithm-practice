#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
ll a[100005];
ll wwx;
struct TrieNode {
	TrieNode *son[2];
	TrieNode() {
		son[0]=son[1]=nullptr;
	}
};
TrieNode *root=new TrieNode();
void Trie_Add(ll num);
ll Trie_Query(ll num);
int main() {
	int i;
	scanf("%d",&n);
	ll hz=0,qz=0;
	for(i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		hz^=a[i];
	}
	wwx=0;
	for(i=1;i<=n+1;i++) {
		Trie_Add(qz);
		wwx=max(wwx,Trie_Query(hz));
		qz^=a[i];
		hz^=a[i];
	}
	Trie_Add(qz);
	wwx=max(wwx,Trie_Query(hz));
	printf("%lld\n",wwx);
    return 0;
}
void Trie_Add(ll num) {
	TrieNode *p=root;
	for(int i=40;i>=0;i--) {
		int oo=(num>>i)&1;
		if(nullptr==p->son[oo])
			p->son[oo]=new TrieNode();
		p=p->son[oo];
	}
}
ll Trie_Query(ll num) {
	TrieNode *p=root;
	ll abld=0; //¼ÇÂ¼´ð°¸ 
	for(int i=40;i>=0;i--) {
		int oo=(num>>i)&1;
		if(p->son[oo^1]) {
			abld|=(1ll<<i);
			oo^=1;
		}
		p=p->son[oo];
	}
	return abld;
}
/*
5
2 19 4 9 24
*/
