#include <iostream>
using namespace std;

// BOJ 1929

int arr[1000001] = { 0, };

int main()
{
	int n, m;
	cin >> n >> m;

	arr[1] = 1;
	for (int i = 2; i <= m; i++)
	{
		if (arr[i] == 1) continue;
		else for (int j = i * 2; j <= m; j += i) arr[j] = 1;
	}

	for (int i = n; i <= m; i++) if (arr[i] == 0) cout << i << "\n";

	return 0;
}