#include <iostream>
using namespace std;

// BOJ 11047

int main()
{
	int n, k, coin[11], cnt = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> coin[i];
	for (int i = n - 1; i >= 0; i--)
	{
		cnt += k / coin[i];
		k %= coin[i];
	}
	cout << cnt;
	return 0;
}