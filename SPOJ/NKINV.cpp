#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 6e5+7;

int n;
int ans;
int tree[N];

void update(int pos)
{
	while (pos > 0)
	{
		//cout << tree[pos] << endl;
		tree[pos]++;
		pos -= (pos & (-pos));
	}
}

int get(int pos)
{
	int res = 0;
	while (pos < N)
	{
		
		res += tree[pos];
		pos += (pos & (-pos));
	}
	return res;
}

main(){
	//freopen("in.inp","r",stdin);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		ans += get(x+1);
		update(x);
	}
	cout << ans << endl;
}
