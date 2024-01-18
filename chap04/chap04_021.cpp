#include <iostream>
#include <vector>
using namespace std;

void merge_sort(int s, int e);
static vector<int> v;
static vector<int> tmp;
static long result;

// BOJ 1517

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	v = vector <int>(n + 1);
	tmp = vector<int>(n + 1);

	for (int i = 1; i <= n; i++) cin >> v[i];

	result = 0;
	merge_sort(1, n);
	cout << result << "\n";
	return 0;
}

void merge_sort(int s, int e) {
	if (e - s < 1) return;

	int m = s + (e - s) / 2;
	merge_sort(s, m);
	merge_sort(m + 1, e);

	for (int i = s; i <= e; i++) tmp[i] = v[i];

	int k = s;
	int idx1 = s;
	int idx2 = m + 1;

	while (idx1 <= m && idx2 <= e) {
		if (tmp[idx1] > tmp[idx2]) {
			v[k] = tmp[idx2];
			result += (idx2 - k);
			k++;
			idx2++;
		}
		else {
			v[k] = tmp[idx1];
			k++;
			idx1++;
		}
	}

	while (idx1 <= m) {
		v[k] = tmp[idx1];
		k++;
		idx1++;
	}

	while (idx2 <= e) {
		v[k] = tmp[idx2];
		k++;
		idx2++;
	}
}