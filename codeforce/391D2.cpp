#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9+7;

int n, m;

struct ver
{
	int lo, hi, x;
}; 
struct hor
{
	int y, left, right;
};
vector <ver> vectical;
vector <hor> horizontal;

struct data{
	int type, pos, low, high;
	data()
	{
		pos = 0; low = 0; high = 0;
	}
	data(int _type, int _pos, int _low, int _high)
	{
		type = _type; pos = _pos; low = _low; high = _high;
	}
	
	bool operator < (const data &other) const
	{
		return (pos < other.pos || (pos == other.pos && type > other.type));
	}
};

vector <data> Y;
vector <int> cnt;

struct BIT
{
	vector <int> t;
	
	void init(int num)
	{
		t.assign(num, 0);
	}
	
	void update(int pos, int val)
	{
		while (pos < t.size())
		{
			t[pos] += val;
			pos += (pos & (-pos));
		}
	}
	
	int get(int pos)
	{
		int res = 0;
		while (pos > 0)
		{
			res += t[pos];
			pos -= (pos & (-pos));
		}
		return res;
	}
} tree;

int prepare(int num)
{
	Y.clear(); cnt.clear();
	for (int i = 0; i < n; i++)
	{
		if (vectical[i].lo + num <= vectical[i].hi - num)
		{
			Y.push_back(data(1, vectical[i].lo+num, vectical[i].x, 1));
			Y.push_back(data(-1, vectical[i].hi-num, vectical[i].x, -1));
			cnt.push_back(vectical[i].x);
		}
	}
	
	for (int i = 0; i < m; i++)
	{
		if (horizontal[i].left + num <= horizontal[i].right - num)
		{
			Y.push_back(data(0, horizontal[i].y, horizontal[i].left + num, horizontal[i].right - num));
		}
	}
	
	sort(Y.begin(), Y.end());
	sort(cnt.begin(), cnt.end());
	cnt.resize(unique(cnt.begin(), cnt.end()) - cnt.begin());
}

int get (int l, int r)
{
	if (l > r) return 0;
	else return tree.get(r) - tree.get(l-1);
}

bool check(int num)
{
	if (num == 0) return true;
	prepare(num);
	tree.init(cnt.size() + 10);
	for (int i = 0; i < Y.size(); i++)
	{
		if (Y[i].type == 0)
		{
			int lo = lower_bound(cnt.begin(), cnt.end(), Y[i].low) - cnt.begin() + 1;
			int hi = upper_bound(cnt.begin(), cnt.end(), Y[i].high) - cnt.begin();
			if (get(lo, hi)) return true;
		}
		else
		{
			int lo = lower_bound(cnt.begin(), cnt.end(), Y[i].low) - cnt.begin() + 1;
			tree.update(lo, Y[i].high);
		}
	}
	return false;
}

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false); cin.tie(0);
	
	cin >> n >> m;
	vectical.assign(n+1, ver());
	for (int i = 0; i < n; i++) 
	{
		cin >> vectical[i].x >> vectical[i].lo >> vectical[i].hi;
		vectical[i].hi += vectical[i].lo;
	}
	horizontal.assign(m+1, hor());
	for (int i = 0; i < m; i++)
	{
		cin >> horizontal[i].left >> horizontal[i].y >> horizontal[i].right;
		horizontal[i].right += horizontal[i].left;
	}
	
	int lo = 0;
	int hi = inf;
	while (lo < hi)
	{
		int mid = (lo + hi) >> 1;
		if (check(mid)) lo = mid; else hi = mid-1;
		if(lo + 1 == hi) break;
	}
	while (check(lo)) lo++;
	printf("%d\n", lo-1);
}
