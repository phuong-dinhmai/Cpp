#include <bits/stdc++.h>
#define inf (int) (1e9+7)
#define vi vector <int>
using namespace std;

main(){
	//freopen("in.inp","r",stdin);
	int test, n;
	cin >> test;
	while (test--)
	{
		vi a;
		cin >> n;
		a.push_back(0);
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			a.push_back(x);
		}
		a.push_back(0);
		stack <int> st;
		vi right(n + 1, 0);
		vi left(n + 1, 0);
		st.push(0);
		for (int i = 1; i <= n; i++)
		{
			while(1)
			{
				int x = st.top();
				if (a[x] < a[i]) break;
				st.pop();
			}
			left[i] = st.top() + 1;
			st.push(i);
		}
		while (!st.empty()) st.pop();
		st.push(n+1);
		for (int i = n; i > 0; i--)
		{
			while(1)
			{
				int x = st.top();
				if (a[x] < a[i]) break;
				st.pop();
			}
			right[i] = st.top() - 1;
			st.push(i);
		}
		int ans = -inf;
		int best;
		for (int i = 1; i <= n; i++)
		{
			int x = a[i]*(right[i] - left[i] + 1);
			if (x > ans || (x == ans && (left[i] < left[best])))
			{
				ans = x;
				best = i;
			}
		}
		cout << ans << " " << left[best] << " " << right[best] << endl;
	}
}
