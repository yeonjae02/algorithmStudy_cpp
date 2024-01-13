#include <iostream>
using namespace std;
// BOJ 1934

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	int t;
	cin >> t;
	for (int i = 0,a, b,result; i < t; i++) {
		cin >> a >> b;
		result = a * b / gcd(a, b);
		cout << result << "\n";
	}
	return 0;
}