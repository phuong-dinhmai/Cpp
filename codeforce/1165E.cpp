#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;
vector <ll> a, b;

const ll mod = 998244353;

ll add(ll x, ll y){
    return ((x % mod)*(y % mod))% mod;
}

main(){
    cin >> n;
    a.resize(n); b.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = a[i]*(i+1)*(n-i);
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; ++i) cin >> b[i];

    sort(b.begin(), b.end(), greater <ll> ());

    ll ans = 0;
    for (int i = 0; i < n; ++i){
        ans += add(a[i], b[i]);
        ans = ans % mod;
    }
    cout << ans << endl;
}
