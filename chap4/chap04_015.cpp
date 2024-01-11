#include <iostream>
#include <vector>
using namespace std;

// BOJ 2750

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) cin >> v[i];

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
			if (v[j] > v[j + 1]) swap(&v[j], &v[j + 1]);
	}

	for (int i = 0; i < n; i++) cout << v[i] << "\n";
	return 0;
}