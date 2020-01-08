#include <bits/stdc++.h>
#define ll long long
#define maxN (ll) (1e5+1)
#define inf (ll) (1e9+7)
using namespace std;

multiset <ll> tree[17*maxN];
ll arr[maxN];
ll n, k, m;

multiset <ll> init(multiset <ll> x, multiset<ll> y)
{
	multiset<ll> res;
	res.insert(x.begin(), x.end());
	res.insert(y.begin(), y.end());
	return res;
}

void reset(multiset <ll> &a, ll old, ll ne)
{
	a.erase(a.lower_bound(old));
	a.insert(ne);
}

void build_tree(ll node, ll a, ll b)
{
	if (a == b)
	{
		tree[node].insert(arr[a]);
		return;
	}
	if (a > b) return;
	ll mid = (a + b)/2;
	build_tree(2*node, a, mid);
	build_tree(2*node+1, mid+1, b);
	tree[node] = init(tree[2*node], tree[2*node+1]);
}

void update(ll node, ll l, ll rr, ll pos, ll val, ll old)
{
	if (l > rr || pos < l || pos > rr) return;
	reset(tree[node], old, val);
	if (l == rr)
	{
		return;
	}
	else
	{
		ll mid = (l + rr)/2;
		update(2*node, l, mid, pos, val, old);
		update(2*node+1, mid+1, rr, pos, val, old);
		//tree[node] = init(tree[2*node], tree[2*node+1]);
	}
}

ll query(ll node, ll l, ll rr, ll a, ll b, ll k)
{
	if (rr < l || a > rr || b < l) return inf;
	if (a <= l && rr <= b)
	{
		multiset <ll> :: iterator it = tree[node].lower_bound(k);
		if (it == tree[node].end()) return inf; 
		else 
		{
			//cout << node << " " << tree[node].size() << "    ";
			//for (multiset <ll> :: iterator i = tree[node].begin(); i != tree[node].end(); i++) cout << *i << " ";
			//cout << endl;
			return *it;
		}
	}
	ll mid = (l + rr)/2;
	ll chil_left = query(2*node, l, mid, a, b, k);
	ll chil_right = query(2*node+1, mid+1, rr, a, b, k);
	return min(chil_left, chil_right);
}

main(){
	//freopen("in.inp","r",stdin);
	ios_base :: sync_with_stdio(false);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) cin >> arr[i];
	build_tree(1, 1, n);
	for (ll i = 0; i < m; i++)
	{
		ll type, u, v, L, R, k;
		cin >> type;
		if (type == 1)
		{
			cin >> u >> v;
			ll old = arr[u];
			arr[u] = v;
			update(1, 1, n, u, v, old);
		}
		else
		{
			cin >> L >> R >> k;
			ll num = query(1, 1, n, L, R, k);
			if (num == inf) printf("-1\n"); else printf("%lld\n", num); 
		}
	}
}
