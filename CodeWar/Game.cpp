#include <bits/stdc++.h>
using namespace std;

int f[51][101][2];
const int inf = 1000000;

int PlayGame(int n, string s){
    int cnt = 0;
    for (int i = 0; i < s.size(); ++i) if (s[i] == 'T') ++cnt;
    if (cnt <= n) return (s.size() - ((n - cnt)%2 == 1? 1: 0));
    s = "0" + s;
    for (int i = 0; i < 51; ++i)
        for (int j = 0; j < 101; ++j) f[i][j][0] = f[i][j][1] = -inf;

    for (int i = 0; i <= n; ++i) f[i][0][1] = f[i][0][0] = 0;
    for (int i = 1; i < s.size(); ++i) {
        if (s[i] == 'F') {
            if (f[0][i-1][1] != -inf) f[0][i][1] = f[0][i-1][1] + 1;
            if (f[0][i-1][0] != -inf && f[0][i-1][0] != 0) f[0][i][0] = f[0][i-1][0] - 1;
            if (f[0][i-1][0] == 0) f[0][i][1] = 1;
        } else {
            if (f[0][i-1][1] != -inf) f[0][i][0] = f[0][i-1][1];
            if (f[0][i-1][0] != -inf && f[0][i-1][0] != 0) f[0][i][1] = f[0][i-1][0];
            if (f[0][i-1][0] == 0) f[0][i][1] = 0;
        }
    }
    if (n > 0) {
        for (int i = 1; i <= n; ++i) {
            //f[i][1][0] = 0;
            f[i][1][1] = (s[i] == 'F'? (i % 2 == 0? 1: 0): (i % 2 == 1? 1: 0));
            //cout << i << " " << 1 << " " << f[i][1][0] << " " << f[i][1][1] << endl;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 2; j < s.size(); ++j){
            if (s[j] == 'F') {
                f[i][j][0] = max(f[i][j-1][0] - 1, f[i-1][j-1][1]);
            } else {
                f[i][j][0] = max(f[i][j-1][1], f[i-1][j-1][0] - 1);
            }
            if (s[j] == 'F') f[i][j][1] = max(f[i][j-1][1] + 1, f[i-1][j-1][0]);
            else f[i][j][1] = max(f[i][j-1][0], f[i-1][j-1][1] + 1);
            //cout << i << " " << j << " " << f[i][j][0] << " " << f[i][j][1] << endl;
        }
    }
    /*for (int i = 0; i <= n; ++i){
        for (int j = 0; j < s.size(); ++j) cout << i << " " << j << " " << f[i][j][0] << " " << f[i][j][1] << endl;
    }*/
    return max(f[n][s.size()-1][0], f[n][s.size()-1][1]);
}


main(){
    //freopen("in.inp", "r", stdin);
    int n;
    string s;
    cin >> n;
    cin >> s;
    cout << PlayGame(n, s) << endl;
}
