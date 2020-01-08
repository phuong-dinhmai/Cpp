#include <bits/stdc++.h>
using namespace std;

int check(int n, int m){
    int cnt [10];
    for (int i = 0; i < 10; ++i) cnt[i] = 0;
    string s = to_string(n);
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != s[s.size()-1-i]) return 0;
        ++cnt[s[i] - '0'];
    }
    int ans = 0;
    for (int i = 0; i < 10; ++i)
        ans += (cnt[i] > 0? 1: 0);
    //cout << s << endl;
    return (ans <= m? 1: 0);
}

int favouritePrimeNumber(int n, int m){
    if (m == 0) return 0;
    bool flag[n];
    memset(flag, 0, sizeof(flag));
    int res = 0;
    for (int i = 2; i <= n; ++i){
        if (!flag[i]) {
            res += check(i, m);
            for (int j = i ; j <= n; j += i) flag[j] = true;
        }
    }
    return res;
}

main(){
    int n, m;
    cin >> n >> m;
    cout << favouritePrimeNumber(n, m) << endl;
}
