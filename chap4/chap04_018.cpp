#include <iostream>
#include <vector>
using namespace std;

// BOJ 11399

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> sum(n);

	for (int i = 0; i < n; i++) cin >> v[i];

	for (int i = 1; i < n; i++) {
		int insert_idx = i;
		int insert_value = v[i];

		for (int j = i - 1; j >= 0; j--) {
			if (v[j] < v[i])
			{
				insert_idx = j + 1;
				break;
			}
			if (j == 0) insert_idx = 0;
		}
		for (int j = i; j > insert_idx; j--) v[j] = v[j - 1];
		v[insert_idx] = insert_value;
	}

	sum[0] = v[0];
	int result = 0;
	for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + v[i];
	for (int i = 0; i < n; i++) result += sum[i];
	cout << result;
	return 0;
}