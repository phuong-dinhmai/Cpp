#include <bits/stdc++.h>
using namespace std;

#define ll long long

pair <int, ll> numdig(ll n){
    ll cnt = 0, pre_cnt = 0;
    for(int i = 1; ;++i){
        pre_cnt = cnt;
        cnt += (ll)i*(pow(10, i)- pow(10, i-1));
        if (cnt >= n) return make_pair (i, n - pre_cnt);
    }
}

ll n;
pair <int, long long> res;

main(){
    cin >> n;
    if (n < 10) cout << n << endl; else {
        res = numdig(n);
        ll num = pow(10, res.first-1) + (ll)(res.second/res.first);
        if (res.second % res.first == 0) --num;
        string s = to_string(num);
        //cout << s << " " << s.size() << " " <<  res.second << " " << res.first << endl;
        if (res.second % res.first == 0) cout << s[s.size()-1] << endl;
        else cout << s[res.second % res.first - 1] << endl;
    }

}
