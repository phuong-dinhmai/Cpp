#include <bits/stdc++.h>
using namespace std;

int examRush(int t, std::vector<int> tm)
{
    int res = 0;
    sort(tm.begin(), tm.end());
    for (int i = 0; i < tm.size(); ++i)
        if (t - tm[i] >= 0) {
            ++ res;
            t -= tm[i];
        } else return res;
    return res;
}

main(){
    int n;
    cin >> n;
    cout << n << endl;
}
