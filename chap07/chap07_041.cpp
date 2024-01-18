#include <iostream>
#include <cmath>
using namespace std;

// BOJ 11689
typedef long long ll;

int main() 
{
	ll n; 
	cin >> n;
	ll result = n;

	for (ll p = 2; p <= sqrt(n); p++) {
		if (n % p == 0) {
			result -= result / p;
			while (n % p == 0) n /= p;
		}
	}

	if (n > 1) result -= result / n;
	cout << result << "\n";
	return 0;
}