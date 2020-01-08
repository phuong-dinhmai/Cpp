#include <bits/stdc++.h>
using namespace std;

string m (string x){
    string res = "";
    bool cnt[26];
    for (int i = 0; i < 26; ++i) cnt[i] = false;
    for (int i = 0; i < x.size(); ++i) {
        cnt[tolower(x[i]) - 'a'] = true;
    }
    for (int i = 0; i < 26; ++i) {
        if (cnt[i]) res += "1"; else res += "0";
    }
    return res;
}

int stringGroupNumber(std::vector<std::string> arr){
    map <string, int> mp;
    for (int i = 0; i < arr.size(); ++i) mp[m(arr[i])] += 1;
    return mp.size();
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
    cout << stringGroupNumber(socks) << endl;
}
