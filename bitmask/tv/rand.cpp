#include <iostream>
#include <random>
using namespace std;

random_device rd;

int main() {
	int n = 3 + rd() % 18, k = rd() % n + 1;
	cout << n << ' ' << k << endl;
	for (int i = 0; i < n; ++i) {
		int rf = rd() % (1 << n); if (rf & (1 << i)) rf ^= (1 << i);
		cout << __builtin_popcount(rf) << ' ';
		for (int j = 0; j < n; ++j) if (rf & (1 << j)) cout << j + 1 << ' '; cout << endl;
	} 
	for (int i = 0; i < n; ++i) cout << rd()%2 << ' '; cout << endl; 
}