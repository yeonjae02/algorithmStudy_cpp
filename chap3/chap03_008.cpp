#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// BOJ 1253

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, result = 0;
	cin >> n;
	vector<int>v(n);

	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		long finds = v[i];
		int start = 0, end = n - 1;

		while (start < end) {
			if (v[start] + v[end] == finds) {
				if (start != i && end != i) { // 서로 다른 두 수의 합
					result++;
					break;
				}
				else if (start == i) start++;
				else if (end == i)  end--;
			}
			else if (v[start] + v[end] > finds) end--;
			else start++;
		}
	}

	cout << result;
	return 0;
}