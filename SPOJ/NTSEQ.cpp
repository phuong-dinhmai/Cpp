#include <bits/stdc++.h>
#define data pair <int, ll>
#define len first
#define sum  second
#define ll long long
#define vi vector <int>
using namespace std;

const int N = 1e5+7;
const ll mod = 1e9+7;

int n;
ll ans = 0;
data tree[N];
vi a, b;

void update(int pos, data val)
{
	while(pos <= N)
	{
		if (tree[pos].len < val.len) tree[pos] = val;
		else if (tree[pos].len == val.len)
		{
			tree[pos].sum = (tree[pos].sum + val.sum + mod) % mod;
		}
		pos += (pos & -pos);
	}
}

data get(int pos)
{
	data s = data(0, 0LL);
	while(pos > 0)
	{
		if (tree[pos].len > s.len) s = tree[pos];
		else if (tree[pos].len == s.len)
		{
			s.sum = (s.sum + tree[pos].sum + mod) % mod;
		}
		pos -= (pos & -pos);
	}
	s.len++;
	if (s.sum == 0) s.sum = 1;
	return s;
}

main(){
	//freopen("in.inp","r",stdin);
	cin >> n;
	memset(tree, 0, sizeof(tree));
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}
	b = a;
	sort(a.begin(), a.end());
	int pos = unique(a.begin(), a.end()) - a.begin();
	for (int i = 0; i < n; i++)
	{
		b[i] = lower_bound(a.begin(), a.begin() + pos, b[i]) - a.begin() + 1;
	}
	//for (int i = 0; i < n; i++) cout << b[i] << " "; cout << endl;
	
	for (int i = 0; i < n; i++)
	{
		data num = get(b[i] - 1);
		update(b[i], num);
	}
	
	data num = get(n);
	//for (int i = 0; i <= n; i++) cout << tree[i].len << " " << tree[i].sum << "     "; cout << endl;
	cout << num.sum << endl;
}
