#include <bits/stdc++.h>
#define ll long long
using namespace std;

const double c2 = 1.414213562373095048801688;
const double c6 = 2.449489742783178098197284;

ll i, k, s;
double a, b, x, y;
double ans;

double power(double x, ll n)
{
	if (n == 1) return x;
	if (n == 0) return 1.00;
	double k = power(x, n/2);
	if (n & 1)	return k*k*x;
	else return k*k;
}

main(){
	//freopen("in.inp","r",stdin);
	cin >> i >> k >> s;
	cin >> a >> b;
	if (i <= k)
	{
		if ((k - i) % 2 == 0)
		{
			s -= 4*(k-i)/2;
			if (s < 0) ans = (a + b)*power(2.00, -s); else ans = (a + b)/power(2.00, s);
		} 
		else
		{
			x = c2*(a+b) - c6*(a-b);
			y = c2*(a-b) + c6*(a+b);
			s -= 4*(k-i-1)/2;
			if (s < 0) ans = (x + y)*power(2.00, -s); else ans = (x + y)/power(2.00, s);
		}
	} 
	else
	{
		if ((i - k) % 2 == 0)
		{
			s += 4*(i - k)/2;
			if (s < 0) ans = (a + b)*power(2.00, -s); else ans = (a + b)/power(2.00, s);
		} 
		else
		{
			x = c2*(a+b) - c6*(a-b);
			y = c2*(a-b) + c6*(a+b);
			s += 4*(i + 1 - k)/2;
			if (s < 0) ans = (x + y)*power(2.00, -s); else ans = (x + y)/power(2.00, s);
		}
	}
	printf("%.10lf\n", ans);
}
