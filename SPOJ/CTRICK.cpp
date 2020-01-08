#include <bits/stdc++.h>
#define maxN 100000
#define vi vector <int>
using namespace std;

int n;
int tree[maxN];

void update(int pos, int val, int n)
{
	while (pos <= n)
	{
		tree[pos] += val;
		pos += (pos & (-pos));
	}
}

int query(int pos)
{
	int ans = 0;
	while (pos)
	{
		ans += tree[pos];
		pos -= (pos & (-pos));
	}
	return ans;
}

int find(int num)
{
	int start = 1;
	int end = n;
	while (start <= end)
	{
		int mid = (start + end) >> 1;
		if (query(mid) < num) start = mid + 1;
		else end = mid - 1;
	}
	return start;
}

main(){
	int test;
	cin >> test;
	while (test--)
	{
		cin >> n;
		int ans[n+1];
		fill(tree, tree + n + 9, 0);
		for (int i = 1; i <= n; i++) update(i, 1, n + 9);
		int m = n;
		int num = 1;
		for (int i = 1; i <= n; i++)
		{
			num = (num + i) % m;
			if (num == 0) num = m;
			m--;
			int x = find(num);
			ans[x] = i;
			update(x, -1, n+9); 
		}
		for (int i = 1; i <= n; i++) cout << ans[i] << " ";
		cout << endl;
	}
}
