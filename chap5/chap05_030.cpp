#include <iostream>
#include <vector>
using namespace std;

// BOJ 2343

int main()
{
	int n, m, right = 0, left = 0, sum, cnt;
	cin >> n >> m;
	vector <int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		right += v[i];
		if (left < v[i]) left = v[i];
	}

	while (left <= right)
	{
		int mid = (left + right) / 2;
		sum = 0, cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (sum + v[i] > mid) {
				sum = 0;
				cnt++;
			}
			sum += v[i];
		}

		if (sum != 0) cnt++;

		if (cnt > m) left = mid + 1;
		else right = mid - 1;
	}
	cout << left;
	return 0;
}