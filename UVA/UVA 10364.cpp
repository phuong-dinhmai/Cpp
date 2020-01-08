#include <bits/stdc++.h>
#define maxN 25
using namespace std;

bool vis[maxN];
int n, k;
int a[maxN];

bool back_track(int i, int cnt, int sum)
{
	if (cnt == 0) return true;
	else if (sum == k) return back_track(0, cnt - 1, 0);
	else if (cnt < 0 || sum > k || i == n || sum < 0) return false;
	else
	{
		if (sum < k && !vis[i])
			{
				vis[i] = true;
				if (back_track(i+1, cnt, sum + a[i])) return true;
				vis[i] = false;
			}
		if (back_track(i+1, cnt, sum)) return true;
	}
	return false;
}
main()
{
	//freopen("in.inp","r",stdin);
	//freopen("out.out","w",stdout);
	
	int test;
	cin >> test;
	while (test--)
	{
		cin >> n;
		int t = 0;
		for (int i = 0; i < n; i++) 
		{
			cin >> a[i];
			vis[i] = false;
			t += a[i];
		}
		k = t/4;
		if (t % 4 != 0) cout << "no" << endl;
		else
		if (back_track(0, 4, 0)) cout << "yes" << endl; else cout << "no" << endl;
	}
}
