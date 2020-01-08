#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxN = 5e4+7;
const ll inf = 1e18+7;

struct Node{
    ll left, right, ans, sum;
    Node(): left(0LL), right(0LL), sum(0LL), ans(0LL){};
    Node(ll lf, ll ri, ll s, ll a) {
        left = lf; right = ri; sum = s; ans = a;
    }
};


Node IT[4*maxN];

void change(int &id, ll x) {
    IT[id].left = x;
    IT[id].right = x;
    IT[id].ans = x;
    IT[id].sum = x;
}

void update(int id, int l, int r, int u, int v, ll val) {
    if (r < u || l > v || l > r) return;
    if (u <= l && r <= v) {
        change(id, val);
        return;
    }

    int mid = (l+r) >> 1;
    update(id << 1, l, mid, u, v, val);
    update(id << 1 ^ 1, mid+1, r, u, v, val);

    IT[id].left = max(IT[id << 1].left, IT[id << 1].sum + IT[id << 1 ^ 1].left);
    IT[id].right = max(IT[id << 1 ^ 1].right, IT[id << 1 ^ 1].sum + IT[id << 1].right);
    IT[id].sum = IT[id << 1].sum + IT[id << 1 ^ 1].sum;
    IT[id].ans = max(max(max(IT[id].left, IT[id].right), max(IT[id << 1].ans, IT[id << 1 ^ 1].ans)),
                     IT[id << 1].right + IT[id << 1 ^ 1].left);
    return;
}

Node query(int id, int l, int r, int u, int v) {
    if (l > v || r < u || l > r) {
            //cout << l  << " " << r << " " << u << " " << v << endl;
            return Node(-inf, -inf, 0, -inf);
    }
    if (l >= u && r <= v) return IT[id];

    int mid = (l + r) >> 1;
    Node lft = query(id << 1, l, mid, u, v);
    Node rght = query(id << 1 ^ 1, mid+1, r, u, v);
    Node res;
    res.sum = 0;
    res.left = max(lft.left, lft.sum + rght.left);
    res.right = max(rght.right, rght.sum + lft.right);
    res.sum = lft.sum + rght.sum;
    res.ans = max(max(max(res.left, res.right), max(lft.ans, rght.ans)), lft.right + rght.left);
    return res;
}

main(){
    freopen("in.inp","r", stdin);
    memset(IT, 0, sizeof(IT));
    int n, m;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        update(1, 1, n, i+1, i+1, x);
    }

    cin >> m;
    while(m--) {
        int type, x, y;
        cin >> type >> x >> y;
        if (type) {
            Node res = query(1, 1, n, x, y);
            cout << res.ans << endl;
        } else {
            //Node res = query(1, 1, n, x, x);
            //cout << res.sum << endl;
            update(1, 1, n, x, x, y);
        }

    }
}
