#include <iostream>
#include <vector>
using namespace std; 

// BOJ 10986

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,m,tmp;
	cin >> n >> m;
	vector<long> arr(n, 0);
	vector<long> re(m, 0);

	long ans = 0;
	cin >> arr[0];
	for (int i = 1; i < n; i++)
	{
		cin >> tmp;
		arr[i] = arr[i - 1] + tmp;
	}

	for (int i = 0; i < n; i++)
	{
		int r = arr[i] % m;
		if (r == 0) ans++;
		re[r]++;
	}

	for (int i = 0; i < m; i++) {
		if (re[i] > 1)
			ans += (arr[i] * arr[i - 1] / 2);
	}

	cout << ans << "\n";
	return 0;
}