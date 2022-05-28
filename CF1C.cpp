#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
const double eps=1e-3;
double pow(double x,int y);
double gcd(double x,double y);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	pair<double,double> x,y,z;
	double a,b,c;
	cin>>x.fi>>x.se>>y.fi>>y.se>>z.fi>>z.se;
	a=sqrt((x.fi-y.fi)*(x.fi-y.fi)+(x.se-y.se)*(x.se-y.se));
	b=sqrt((x.fi-z.fi)*(x.fi-z.fi)+(x.se-z.se)*(x.se-z.se));
	c=sqrt((y.fi-z.fi)*(y.fi-z.fi)+(y.se-z.se)*(y.se-z.se));
	double p=(a+b+c)/2;
	double s=sqrt(p*(p-a)*(p-b)*(p-c));
	double R=a*b*c/(4*s);
	const double Pi=acos(-1);
	double A,B,C;
	A=acos((2*R*R-a*a)/(2*R*R));
	B=acos((2*R*R-b*b)/(2*R*R));
//	C=acos((2*R*R-c*C)/(2*R*R));
	C=2*Pi-A-B;
	double angle=gcd(A,gcd(B,C));
	double wwx=(2.*Pi/angle)*R*R*sin(angle)*0.5;
	cout<<fixed<<setprecision(6)<<wwx<<endl;
    return 0;
}
double pow(double x,int y) {
	double jyl=1.;
	for(;y;y>>=1) {
		if(y&1)
			jyl=jyl*x;
		x=x*x;
	}
	return jyl;
}
double gcd(double x,double y) {
	if(fabs(x)<eps)
		return y;
	if(fabs(y)<eps)
		return x;
	return gcd(y,fmod(x,y));
}
