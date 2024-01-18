#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// BOJ 1940

int main()
{
	int n, m;
	cin >> n >> m;
	vector <int> arr(n, 0);

	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr.begin(), arr.end());

	int start = 0, end = n - 1, cnt=0;
	while (start < end) {
		if (arr[start] + arr[end] == m) {
			cnt++;
			start++;
			end--;
		}
		else if (arr[start] + arr[end] > m) end--;
		else start++;
	}

	cout << cnt << "\n";
	return 0;
}