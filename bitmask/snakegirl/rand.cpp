#include <iostream>
#include <random>
using namespace std;

random_device rd;

int main() {
	int n = rd()%2000 + 1; if (rd()%100 == 0) n = 1;
	int m = rd()%10 + 1; 
	cout << n << ' ' << m << endl;
	cerr << n << ' ' << m << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int k = rd()%21;
			if (k == 10) cout << 'x'; else if (k == 20) cout << 'o'; else cout << '.';
		}
		cout << endl;
	}
}