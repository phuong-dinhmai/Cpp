#include <bits/stdc++.h>
using namespace std;

int test;
long long x1, x2, y, y2, n, k;

main(){
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	scanf("%d", &test);
	while (test--)
	{
		scanf("%lld%lld%lld%lld%lld%lld", &n, &k, &x1, &y, &x2, &y2);
		if (n < k) swap(n, k);
		int t1 = abs(x1 - x2);
		int t2 = abs(y - y2);
		int div = __gcd(n, k);
		if (t2 % div != 0 || t1 % div != 0) 
		{
			printf("NIE\n");	
		} 
		else
		{
			//cout << test << endl;
			if (k != 0)
			{
				bool flag = false;
				for (int i = 0; i < 2; i++)
					for (int j = 0; j < 2; j++)
					{
						long long h1, h2;
						if (i == 1 && j == 1)
						{
							h1 = t1 + n + k;
							h2 = t2 + n + k;
						}
						if (i == 0 && j == 1)
						{
							h1 = t1 + k;
							h2 = t2 + n;
						}
						if (i == 1 && j == 0)
						{
							h1 = t1 + n;
							h2 = t2 + k;	
						}
						if (i == 0 && j == 0) h1 = t1, h2 = t2;
						if (h1 % (2*div) == 0 && h2 % (2*div) == 0) flag = true;
					}
				if (flag) printf("TAK\n"); else printf("NIE\n");
			}
			else printf("TAK\n");
		}
	}
}
