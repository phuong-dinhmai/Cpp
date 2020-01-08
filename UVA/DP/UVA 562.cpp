#include <bits/stdc++.h>
using namespace std;

main(){
	int test;
	bool ok[25001];
	int a[101];
	int n, m;
	//freopen ("in.inp", "r", stdin);
	//freopen("out.out","w",stdout);
	scanf("%d", &test);
	while (test--)
	{
		scanf ("%d", &n);
		int sum = 0;
		for (int i = 0; i < n; i++) 
		{
			scanf ("%d", &a[i]);
			sum += a[i];
		}
		m = sum / 2;
		for (int i = 0; i <= m; i++) ok[i] = false;
		ok[0] = true;
		for (int i = 0; i < n; i++)
			for (int j = m; j > 0; j--)
				if (!ok[j])
					ok[j] = (j < a[i])? false : (ok[j - a[i]]);
		int i;
		for (i = m; i >= 0; i--) 
			if (ok[i]) break;
		printf("%d\n", (sum - i * 2));
		
	}
}
