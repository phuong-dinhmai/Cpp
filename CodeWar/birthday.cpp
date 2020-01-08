#include <bits/stdc++.h>
using namespace std;

std::vector<std::string> birthdayList(std::vector<std::string> students, int month)
{
    vector <pair <string, string> > l;
    vector <string> res;
    string m = to_string(month);
    if (m.size() < 2) m = "0" + m;
    for (int i = 0; i < students.size(); ++i){
        if (students[i].substr(students[i].size()-2) == m) {
            string x = students[i].substr(0,students[i].size()-4 );
        for (int j = 0; j < x.size(); ++j) x[j] = tolower(x[j]);
        x[0] = toupper(x[0]);
        //cout << x << endl;
            l.push_back(make_pair (students[i].substr(students[i].size()-4), x));
        }
        //cout << students[i].substr(students[i].size()-4) << endl;
    }
    for (int i = 0; i < l.size(); ++i){
        for (int j = i+1; j < l.size(); ++j) {
            if (l[i].first > l[j].first) swap(l[i], l[j]);
            else if (l[i].first == l[j].first){
                if (l[i].second > l[j].second) swap(l[i], l[j]);
            }
        }
        //cout << l[i].first << endl;
    }
    for (int i = 0; i < l.size(); ++i) {
        res.push_back(l[i].second);
        cout << l[i].second << endl;
    }
    return res;
}

main(){
    int n;
    vector <string> day;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        day.push_back(s);
    }
    day = birthdayList(day, 12);
}
