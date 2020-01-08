#include <bits/stdc++.h>
using namespace std;

main(){
	int n, test = 0;
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	while (cin >> n && n)
	{
		test++;
		int a[n];
		int ans = 0;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			sum += a[i];
		}
		sum /= n;
		for (int i = 0; i < n; i++)
			if (a[i] < sum) ans += (sum - a[i]);
		cout << "Set #" << test << endl;
		cout << "The minimum number of moves is " << ans << "." << endl;
		cout << endl;
		
	}
}
