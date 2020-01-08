#include <bits/stdc++.h>
using namespace std;

bool check(int day, int [] need){
    for (int i = 1; i <= day; ++i){
        if (date.size() != 0){

        }
    }
}

main(){
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) {
        cin >> date >> sale;
        date.push_back(sale);
    }

    while (l < r-1) {
        int mid = (l + r)/2;
        if (check(mid, a)) r = mid;
        else l = mid+1;
    }
    cout << check(l, a)? l: r << endl;
}
