#include <iostream>
#include <algorithm>
using namespace std;

// BOJ 1920

int a[100001], b[100001], n, m;

int binsearch(int find)
{
	int left = 0, right = n - 1, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (find == a[mid]) return 1;
		else if (find > a[mid]) left = mid + 1;
		else right = mid - 1;
	}
	return 0;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cin >> m;
	for (int i = 0; i < m; i++) cin >> b[i];
	sort(a, a + n);
	for (int i = 0; i < m; i++) cout << binsearch(b[i]) << "\n";
	return 0;
}