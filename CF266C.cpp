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

int syf[N1],gj[N1];
int bo[N1][N1];

struct opt {
	int o,x,y;
	void print() {
		printf("%d %d %d\n",o,x,y);
	}
};
vector<opt> jyl;

void play(int n);

int main() {
	freopen("test.in","r",stdin);
	int i,j,k;
	int o,p,q;
	ll oo,pp,qq;
	
	int n;
	scanf("%d",&n);
	fz1(i,n-1) {
		scanf("%d%d",&pp,&qq);
		bo[pp][qq]=1;
		syf[pp]++;
		gj[qq]++;
	}
	play(n);
	printf("%d\n",jyl.size());
	ff(jyl,itr) {
		(*itr).print();
	}
    return 0;
}

void play(int n) {
	if(n==1)
		return;
	int i,j,k;
	if(gj[n]!=0) {
		fz1(i,n) {
			if(gj[i]==0) {
				fz1(j,n) {
					swap(bo[j][i],bo[j][n]);
				}
				swap(gj[i],gj[n]);
				jyl.pb((opt){2,i,n});
				break;
			}
		}
	}
	if(syf[n]==0) {
		fz1(i,n) {
			if(syf[i]!=0) {
				fz1(j,n) {
					swap(bo[i][j],bo[n][j]);
				}
				swap(syf[i],syf[n]);
				jyl.pb((opt){1,i,n});
				break;
			}
		}
	}
	fz1(i,n) {
		if(bo[n][i]) {
			gj[i]--;
		}
	}
	play(n-1);
}
