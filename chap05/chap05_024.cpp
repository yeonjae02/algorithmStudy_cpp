#include <iostream>
using namespace std; 

// BOJ 2023

int n, result;

bool isPrime(int n) {
	for (int i = 2; i <= n / 2; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void dfs(int v, int l)
{
	if (l == n) {
		if (isPrime(v)) cout << v << "\n";
		return;
	}

	for (int i = 1; i < 10; i += 2) {
		if (isPrime(v * 10 + i)) {
			dfs(v * 10 + i, l + 1);
		}
	}
}

int main()
{
	cin >> n;
	dfs(2, 1);
	dfs(3, 1);
	dfs(5, 1);
	dfs(7, 1);
	return 0;
}