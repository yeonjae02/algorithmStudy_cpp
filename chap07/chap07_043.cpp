#include <iostream>
using namespace std;
// BOJ 1850

typedef long long ll;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	ll a, b, result;
	cin >> a >> b;
	result = gcd(a, b);

	while (result > 0) {
		cout << 1;
		result--;
	}
	return 0;
}