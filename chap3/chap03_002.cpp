#include <iostream>
using namespace std;

// BOJ 1546

int main()
{
	int n, arr[1000];
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	double sum=0, max=0;

	for (int i = 0; i < n; i++)
	{
		if (max < arr[i]) max = arr[i];
		sum += arr[i];
	}

	double result = sum * 100 / max / n;
	cout.precision(20);
	cout << result << "\n";
	return 0;
}