#include <bits/stdc++.h>
#define ll long long
#define maxN 100006LL
using namespace std;

ll tree[36][4*maxN];
ll lazy[36][4*maxN];
int test,m,n;
ll prime[36]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149};

ll power(ll a,ll n,ll mod) {
	ll res=1LL;
	ll mul=a;
	while (n > 0LL) {
		if (n & 1LL) res=(res*mul) % mod;
		mul=(mul*mul) % mod;
		n >>= 1LL;
	}
	return res;
}

void trueval(int node,int l,int r,ll pos) {
	if (lazy[pos][node]==0) return;
	tree[pos][node]+=(lazy[pos][node]* ((ll) (r-l+1)));
	if (l != r) {
		lazy[pos][node << 1LL]+=lazy[pos][node];
		lazy[pos][(node << 1LL)|1LL]+=lazy[pos][node];
	}
	lazy[pos][node]=0;
	return;
}

void update(int node,int l,int r,int a,int b,ll val,int pos) {
	trueval(node,l,r,pos);
	if (a > r || b < l || l > r) return;
	if (a<=l && r<=b) {
		tree[pos][node]+=val*((ll) (r-l+1));
		if (a != b) {
			lazy[pos][node << 1LL]+=val;
			lazy[pos][(node << 1LL)|1LL]+=val;
		}
		return;
	}
	ll mid=(l+r) >> 1LL;
	update(node << 1LL,l,mid,a,b,val,pos);
	update((node << 1LL)|1LL,mid+1LL,r,a,b,val,pos);
	//tree[pos][node]=tree[pos][node << 1LL]+tree[pos][(node << 1LL)|1LL];
	tree[pos][node]+=val*((ll) (min (b,r)-max (a,l)+1));
	return;
}

ll query(int node,int l,int r,int a,int b,int pos) {
	trueval(node,l,r,pos);
	if (a > r || b < l || l > r) return 0LL;
	if (a<=l && r<=b) return tree[pos][node];
	ll mid=(l+r) >> 1LL;
	ll lft=query(node << 1LL,l,mid,a,b,pos);
	ll rght=query((node << 1LL)|1LL,mid+1LL,r,a,b,pos);
	return (lft+rght);
}

int main () {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> test;
	while (test--) {
		cin >> n >> m;
		//for (ll i=0; i < 35; i++)
		//	for (ll j=0; j<=4*n; j++) lazy[i][j]=tree[i][j]=0;
		memset(lazy,0LL,sizeof(lazy));
		memset(tree,0LL,sizeof(tree));
		while (m--) {
			int type,l,r;
			ll X,mod;
			cin >> type;
			if (type==0) {
				cin >> l >> r >> mod;
				ll ans=1LL;
				for (ll j=0; j < 35; j++) {
					ll x;
					if (l<=r) x=query(1,1,n,l,r,j);
					else x=query(1,1,n,1,r,j)+query(1,1,n,l,n,j);
					if (x != 0) ans=(ans*power(prime[j],x,mod)) % mod;
				}
				cout << (ans % mod) << "\n";
			} else {
				cin >> l >> r >> X;
				for (ll j=0; j < 35 && X>1; j++) {
					ll cnt=0LL;
					while (X % prime[j]==0) cnt++,X /= prime[j];
					if (cnt != 0) {
						if (type==2) {
							if (l<=r) update(1,1,n,l,r,-cnt,j);
							else update(1,1,n,1,r,-cnt,j),update(1,1,n,l,n,-cnt,j);
						} else {
							if (l<=r) update(1,1,n,l,r,cnt,j);
							else update(1,1,n,1,r,cnt,j),update(1,1,n,l,n,cnt,j);
						}
					}
					if (X==1) break;
				}
			}
		}
	}
}
