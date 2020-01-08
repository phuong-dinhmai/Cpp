#include <bits/stdc++.h>
#define pi  2*acos(0.0)
using namespace std;

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	int test; 
	cin >> test;
	while (test--)
	{
		double x,y,a,b;
		cin >> y >> x;
		a = sqrt((x/2)*(x/2) - (y/2)*(y/2));
		b = x/2;
		printf("%.3lf\n",pi*a*b);
	}
}
