#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int main() {
	freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int ball,n=3;
    int a,b;
    cin>>ball;
    while(n--) {
    	cin>>a>>b;
    	if(ball==a)
    		ball=b;
    	else if(ball==b)
    		ball=a;
	}
	cout<<ball<<endl;
    return 0;
}
