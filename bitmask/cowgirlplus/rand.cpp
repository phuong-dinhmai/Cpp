#include <iostream>
#include <random>
using namespace std;

random_device rd;

int main() {
	int n = rd()%101 + 1900; if (rd()%100 == 0) n = 1;
	int m = rd()%3 + 8; 
	cout << 1 << endl;
	cout << n << ' ' << m << endl;
	cerr << n << ' ' << m << endl;
}