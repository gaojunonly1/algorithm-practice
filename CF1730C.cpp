#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
char s[200005];
int a[200005];
int cnt[15];
void solve();
void dfs(int pos,int num);
void CSH();
int main() {
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
    return 0;
}
void solve() {
	CSH();
	int i,j,k;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++)
		a[i]=s[i]-'0';
	dfs(1,0);
	for(i=0;i<=9;i++)
		for(j=1;j<=cnt[i];j++)
			printf("%c",(char)(i+'0'));
	printf("\n");
}
void CSH() {
	fill(cnt,cnt+10,0);
	return;
}
void dfs(int pos,int num) {
	if(pos>n||num>9)
		return;
	int i,las=-1;
	for(i=n;i>=pos;i--)
		if(a[i]==num) {
			las=i;
			break;
		}
	if(las==-1) {
		dfs(pos,num+1);
		return;
	}
	for(i=pos;i<=las;i++) {
		if(a[i]==num)
			cnt[num]++;
		else
			cnt[min(a[i]+1,9)]++;
	}
	dfs(las+1,num+1);
}
