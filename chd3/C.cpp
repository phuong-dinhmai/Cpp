#include <iostream>
using namespace std;

int main() {
	long long n;
	while (cin >> n) {
		if (n==3) cout << "C" << endl;
		else if (n%2==1) cout << "B" << endl; else {
			int p=0;
			while (n%2==0) { n/=2; p++; }
			if (p%2==0)	cout << "B" << endl; else cout << "A" << endl;
		}
	}
}