#include <iostream>
using namespace std;
// BOJ 2166

typedef long long ll;
int n;
ll x[10001], y[10001];

int main() 
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

	x[n] = x[0];
	y[n] = y[0];

	double result = 0;
	for (int i = 0; i < n; i++) {
		result += (x[i] * y[i + 1]) - (x[i + 1] * y[i]);
	}

	cout << fixed;
	cout.precision(1);
	cout << abs(result) / 2;

	return 0;
}