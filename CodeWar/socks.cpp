#include <bits/stdc++.h>
using namespace std;

int numberOfSocks(std::vector<std::string> socks){
    map <string, int> mp;
    int ans = 0;
    for (int i = 0; i < socks.size(); ++i) {
        if (socks[i][0] == 'L') mp[socks[i].substr(1)]++;
        //cout << socks[i].substr(1) << endl;
    }
    for (int i = 0; i < socks.size(); ++i) {
        if (socks[i][0] == 'R') {
            if (mp[socks[i].substr(1)] != 0) {
                ans += 1;
                mp[socks[i].substr(1)] -= 1;
            }
        }
    }
    return ans;
}

main(){
    int n;
    vector <string> socks;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        socks.push_back(s);
    }
    cout << numberOfSocks(socks) << endl;
}
