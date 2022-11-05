#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mp make_pair
#define inf LLONG_MAX
#define iinf INT_MAX

const int N1=1005;

vector<int>syf[2][N1];
int jfm=0;
vector<int>jyl[N1];

int main() {
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	
	int n;
	scanf("%d",&n);
	int pre=0,now=1;
	int cnt=1;
	syf[pre][cnt].clear();
	fz1(i,n) {
		syf[pre][cnt].pb(i);
	}
	bool gj=1;
	while(gj) {
		gj=0;
		int tot=0;
		fz1(i,cnt) {
			if(syf[pre][i].size()>1) {
				tot++;
				syf[now][tot].clear();
				fz0k(j,syf[pre][i].size()/2) {
					syf[now][tot].pb(syf[pre][i][j]);
				}
				tot++;
				syf[now][tot].clear();
				fz(j,syf[pre][i].size()/2,syf[pre][i].size()-1) {
					syf[now][tot].pb(syf[pre][i][j]);
				}
			}
			else {
				tot++;
				syf[now][tot].clear();
				ff(syf[pre][i],itr) {
					syf[now][tot].pb(*itr);
				}
			}
		}
		jfm++;
		fz1(i,tot) {
			gj|=syf[now][i].size()>1;
			if(i&1) {
				ff(syf[now][i],itr) {
					jyl[jfm].pb(*itr);
				}
			}
		}
		cnt=tot;
		swap(pre,now);
	}
	printf("%d\n",jfm);
	fz1(i,jfm) {
		printf("%d ",jyl[i].size());
		ff(jyl[i],itr) {
			printf("%d ",(*itr));
		}
		printf("\n");
	}
    return 0;
}
