#include <bits/stdc++.h>
using namespace std;

string read(int k) {
	if (k==0) return "zero";
	int hun=k/100,ten=(k%100)/10,uni=k%10;
	string s="";
	switch(hun) {
		case 1: s=s+"one"+"hundred"; break;
		case 2: s=s+"two"+"hundred"; break;
		case 3: s=s+"three"+"hundred"; break;
		case 4: s=s+"four"+"hundred"; break;
		case 5: s=s+"five"+"hundred"; break; break;
		case 6: s=s+"six"+"hundred"; break;
		case 7: s=s+"seven"+"hundred"; break;
		case 8: s=s+"eight"+"hundred"; break;
		case 9: s=s+"nine"+"hundred"; break;
		default: s=s; break;
	}
	if (ten==1) {
		switch(k%100) {
			case 10: s=s+"ten"; break;
			case 11: s=s+"eleven"; break;
			case 12: s=s+"twelve"; break;
			case 13: s=s+"thirteen"; break;
			case 14: s=s+"fourteen"; break;
			case 15: s=s+"fifteen"; break;
			case 16: s=s+"sixteen"; break;
			case 17: s=s+"seventeen"; break;
			case 18: s=s+"eighteen"; break;
			case 19: s=s+"nineteen"; break;
			default: s=s; break;
		}
	} else {
		switch(ten) {
			case 2: s=s+"twenty"; break;
			case 3: s=s+"thirty"; break;
			case 4: s=s+"forty"; break;
			case 5: s=s+"fifty"; break;
			case 6: s=s+"sixty"; break;
			case 7: s=s+"seventy"; break;
			case 8: s=s+"eighty"; break;
			case 9: s=s+"ninety"; break;
			default: s=s; break;
		}
		switch(uni) {
			case 1: s=s+"one"; break;
			case 2: s=s+"two"; break;
			case 3: s=s+"three"; break;
			case 4: s=s+"four"; break;
			case 5: s=s+"five"; break;
			case 6: s=s+"six"; break;
			case 7: s=s+"seven"; break;
			case 8: s=s+"eight"; break;
			case 9: s=s+"nine"; break;
			default: s=s; break;
		}
	}
	return s;
}

int main() {
	string sp,s;
	int t,n,sl=0;
	vector<string> a;
	cin >> t;
	while (t--) {
		a.clear(); sl=0;
		cin >> n; getline(cin,sp);
		for (int i=0; i<n; i++) {
			getline(cin,s); a.push_back(s);
			if (s!="$") sl+=s.size();
		}
		for (int i=1; i<=1000; i++) {
			string t=read(i);
			if (t.size()+sl==i) {
				for (int j=0; j<n; j++) {
					if (a[j]!="$") cout << a[j]; else cout << t;
					if (j<n-1) cout << " "; else cout << endl;
				}
				break;
			}
		}
	}
}