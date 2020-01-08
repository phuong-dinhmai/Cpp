#include <bits/stdc++.h>
#define ll long long
#define ii pair <ll, ll>
#define maxN 100000
#define x first
#define y second
using namespace std;

const ll mod = 1e9+7;

ll tree[4*maxN+6];
ii lazy[4*maxN+6];
ll n, k;

void trueval(ll node, ll lft, ll rght)
{
	if (lazy[node].x + lazy[node].y == 0) return;
	ll c = rght - lft + 1;
	tree[node] += (c*lazy[node].y % mod + c*(c-1)/2*lazy[node].x % mod);
	if (lft != rght)
	{
		ll mid = (lft +rght)/2;
		lazy[2*node].x = (lazy[node].x + lazy[2*node].x) % mod;
		lazy[2*node].y = (lazy[node].y + lazy[2*node].y) % mod;
		lazy[2*node+1].x = (lazy[node].x + lazy[2*node+1].x) % mod;
		lazy[2*node+1].y = (lazy[node].y + lazy[2*node+1].y + (mid + 1 - lft)*lazy[node].x) % mod;
	}
	//cout << lazy[node].x << " " << lazy[node].y << endl;
	lazy[node].x = lazy[node].y = 0;
	return;
}

ll query(ll node, ll lft, ll rght, ll a, ll b)
{
	trueval(node, lft, rght);
	if (b < lft || a > rght || lft > rght) return 0;
	if (a <= lft && rght <= b) return (tree[node] % mod);
	ll mid = (lft + rght)/2;
	ll chil_left = query(2*node, lft, mid, a, b);
	ll chil_right = query(2*node+1, mid+1, rght, a, b);
	return (chil_left % mod + chil_right % mod) % mod;
}

void update(ll node, ll lft, ll rght, ll a, ll b, ll A, ll B)
{
	trueval(node, lft, rght);
	if (lft > b || rght < a || lft > rght) return;
	ll c = rght - lft +1;
	ll val = (c*((lft - a)*A + B) % mod + c*(c-1)/2*A % mod) % mod;
	if (a <= lft && rght <= b)
	{
		ll mid = (lft +rght)/2;
		tree[node] += val;
		if (lft == rght) return;
		lazy[2*node].x = (A + lazy[2*node].x) % mod;
		lazy[2*node].y = (B + A*(lft - a)% mod + lazy[2*node].y) % mod;
		lazy[2*node+1].x = (A + lazy[2*node+1].x) % mod;
		lazy[2*node+1].y = (B + (mid - a + 1)*A%mod + lazy[2*node+1].y) % mod;
	}
	else
	{
		ll mid = (lft + rght)/2;
		update(2*node, lft, mid, a, b, A, B);
		update(2*node+1, mid+1, rght, a, b, A, B);
		tree[node] = (tree[2*node] % mod + tree[2*node+1] % mod) % mod;
	}
}

main(){
	//freopen("in.inp","r",stdin);
	cin >> n >> k;
	for (ll i = 0; i < k; i++)
	{
		ll type, L, R, A, B;
		cin >> type;
		if (type == 1)
		{
			cin >> L >> R >> A >> B;
			update(1, 1, n, L, R, A, B);
		}
		else
		{
			cin >> L >> R;
			cout << query(1, 1, n, L, R) << endl;
			//for (ll i = 1; i <= 33; i++) cout << tree[i] << " ";
			//cout << endl;
		}
	}
}
