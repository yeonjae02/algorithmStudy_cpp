#include <iostream>
#include <vector>
using namespace std;

// BOJ 11004

void quickSort(vector<int>& v, int s, int e, int k);
int partition(vector<int>& v, int s, int e);
void swap(vector<int>& v, int i, int j);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	quickSort(v, 0, n - 1, k - 1);
	cout << v[k - 1];
	return 0;
}

void quickSort(vector<int>& v, int s, int e, int k)
{
	int pivot = partition(v, s, e);
	if (pivot == k) return;
	else if (k < pivot) quickSort(v, s, pivot - 1, k);
	else quickSort(v, pivot+1, e, k);
}

int partition(vector<int>& v, int s, int e)
{
	if (s + 1 == e) {
		if (v[s] > v[e]) swap(v, s, e);
		return e;
	}
	
	int m = (s + e) / 2;
	swap(v, s, m);
	int pivot = v[s];
	int i = s + 1, j = e;

	while (i <= j) {
		while (pivot < v[j] && j > 0)j--;
		while (pivot > v[i] && i < v.size() - 1) i++;
		if (i <= j) swap(v, i++, j--);
	}

	v[s] = v[j];
	v[j] = pivot;
	return j;
}

void swap(vector<int>& v, int i, int j)
{
	int tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}