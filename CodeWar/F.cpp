#include <bits/stdc++.h>
using namespace std;

#define val first
#define type second

vector <pair <int, int> > a;

int Case1(){// 1 bo 4 va 1 day 5
    int cnt = 0, up = 0, down = 0;
    int res = 10;
    for (int i = 1; i < 4; ++i)
            if (a[0].val != a[i].val) ++cnt;
    if (a[4].val - a[0].val >= 5) {
        for (int i = 5; i < 9; ++i){
            if (a[i].val != a[4].val + (i-4) || a[i].type != a[4].type) ++up;
        }
        res = min(res, cnt+up);
    }
    if (a[0].val - a[4].val >= 5) {
        for (int i = 5; i < 9; ++i){
            if (a[i].val != a[4].val - (i-4) || a[i].type != a[4].type) ++down;
        }
        res = min(res, cnt+down);
    }

    return res;
}

int Case2() { // 3 bo 3
    int cnt = 0;
    if (a[0].val != a[3].val && a[0].val != a[6].val && a[3].val != a[6].val){
        for (int i = 0; i < a.size(); ++i){
            int x = i/3;
            if (a[i].val != a[x * 3].val) ++cnt;
        }

    } else cnt = 10;
    return cnt;
}

int chain(int pos, int type) {
    int cnt2 = 0;
    cnt2 += (a[pos].type == a[pos+1].type && a[pos].val + type*1 == a[pos+1].val)? 0: 1;
    cnt2 += (a[pos].type == a[pos+2].type && a[pos].val + type*2 == a[pos+2].val)? 0: 1;
    return cnt2;
}

int Case3(){// 1 day va 2 bo 3
    int cnt = 0, cnt2 = 0;

    // up
    cnt = chain(0, 1);
    for (int i = 3; i < a.size(); ++i){
        int x = i/3;
        if (a[i].val != a[x * 3].val ||
           (i % 3 != 0 && a[i].val == a[x * 3].val && a[i].type == a[0].type && a[i].val < a[0].val + 3 && a[i].val > a[0].val)) ++cnt;
    }

    // down
    cnt2 = chain(0, -1);
    for (int i = 3; i < a.size(); ++i){
        int x = i/3;
        if (a[i].val != a[x * 3].val ||
           (i % 3 != 0 && a[i].val == a[x * 3].val && a[i].type == a[0].type && a[0].val < a[i].val + 3 && a[i].val < a[0].val)) ++cnt2;
    }
    return min(cnt, cnt2);
}

int Case4() { //2 bo day va 1 bo 3
    int dd, uu, du;
    bool t[4] = {0, 0, 0, 0};
    dd = chain(0, -1);
    if ((a[3].val != a[0].val-1 && a[3].val != a[0].val-2) || a[3].type != a[0].type) dd += chain(3, -1);
    else dd = 10;
    uu = chain(0, 1);
    if ((a[3].val != a[0].val+1 && a[3].val != a[0].val+2) || a[3].type != a[0].type) uu += chain(3, 1);
    else uu = 10;
    du = chain(0, -1);
    if ((a[3].val != a[0].val-1 && a[3].val != a[0].val-2) || a[3].type != a[0].type) du += chain(3, 1);
    else du = 10;

    bool noup1, noup2, nodn1, nodn2;
    if (a[0].val < a[6].val && a[6].val < a[0].val +3) noup1 = true; else noup1 = false;
    if (a[3].val < a[6].val && a[6].val < a[3].val +3) noup2 = true; else noup2 = false;
    if (a[0].val > a[6].val && a[6].val > a[0].val -3) nodn1 = true; else nodn1 = false;
    if (a[0].val > a[6].val && a[6].val > a[0].val -3) nodn1 = true; else nodn1 = false;

    int cnt = 0;
    for (int i = 6; i < a.size(); ++i){
            if (a[i].val != a[i/3 * 3].val) {
                ++cnt;
                if (a[i].type == 0) t[0] = 1;
                else if (a[i].type == 1) t[1] = 1;
                else if (a[i].type == 2) t[2] = 1;
                else t[3] = 1;
            }
        }

    int res = 10;
    if (noup1 && noup2) uu = 10;
    else if ((noup1 || noup2) && t[a[6].type]) res = min(res, cnt + uu + 1);
    if (nodn1 && nodn2) dd = 10;
    else if ((nodn1 || nodn2) && t[a[6].type]) res = min(res, cnt + dd + 1);
    if (noup1 && noup2) du = 10;
    else if ((nodn1 || noup2) && t[a[6].type]) res = min(res, cnt + du + 1);
    return res;
}

int Case5(){ // 3 bo day
    return 10;
}

int cardGroupNumber(std::string s)
{
    int num = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            num = num*10 + s[i] - '0';
        } else {
            int x;
            switch(s[i]){
                case 'B': {x = 0; break;}
                case 'T': {x = 1; break;}
                case 'R': {x = 2; break;}
                case 'C': {x = 3; break;}
            }
            a.push_back(make_pair(num, x));
            num = 0;
        }
    }

    int res = 10;
    do {
        res = min(min(min(Case1(), Case2()), min(Case4(), Case5())), min(res, Case3()));
        //cout << Case1() << " " << Case2() << " " << Case3() << " " << Case4() << " " << Case5() << endl;
    } while (next_permutation(a.begin(), a.end()));
    //cout << Case3() << endl;
    return res;
}

main(){
    freopen("in.inp","r",stdin);
    string s;;
    cin >> s;
    cout << cardGroupNumber(s) << endl;
}
