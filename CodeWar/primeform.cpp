#include <bits/stdc++.h>
using namespace std;

const long long inf = 1e10+7;

long long res = inf;
int a[11], b[11];

bool prime(long n) {
    if (n < 2) return false;
    for (int i = 2; i*i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

void backtrack(int i, int k, string s, string str) {
    //cout << s << " " << str << endl;
    for(int j = a[i-1]+1; j<=10-k+i; j++) {
        a[i] = j ;
        if(i==k) {
            do {
                long long num = 0;
                /*for (int x = 1; x <= k; ++x) cout << a[x] << " ";
                cout << endl;*/
                for (int x = 0; x < str.size(); ++x) {
                    for (int y = 0; y < s.size(); ++y)
                        if (str[x] == s[y]) {
                            if (x == 0 && a[y+1] == 1) {num = inf; break;}
                            num = num*10 + (a[y+1] - 1);
                        }
                }
                //cout << num << endl;
                if (prime(num)) res = min(res, num);
            } while (next_permutation(a+1, a+k+1));
        }
        else {
            backtrack(i+1, k, s, str);
        }

    }
}

int primeForm(std::string str){
    int cnt[26];
    string s = "";
    for (int i = 0; i < 26; ++i) cnt[i] = 0;
    for (int i = 0; i < str.size(); ++i){
        cnt[str[i]-'a']++;
    }
    int n = 0;
    for (int i = 0; i < 26; ++i)
        if (cnt[i]) {
            ++n;
            char c = static_cast<char> (i + 97);
            s += c;
        }

    a[0] = 0;
    backtrack(1, n, s, str);
    if (res != inf) return res; else return -1;
}

main(){
    string s;
    cin >> s;
    cout << primeForm(s) << endl;
}
