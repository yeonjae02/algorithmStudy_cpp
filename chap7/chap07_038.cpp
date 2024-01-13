#include <iostream>
#include <cmath>
#define MAX 10000001
using namespace std;

// BOJ 1456

long minx, maxx, arr[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> minx >> maxx;

	for (int i = 2; i < MAX; i++) arr[i] = i;

	for (int i = 2; i < sqrt(MAX); i++) {
		if (arr[i] == 0) continue;
		for (int j = i + i; j < MAX; j += i) arr[j] = 0;
	}

	int cnt = 0;
	for (int i = 2; i < MAX; i++) {
		if (arr[i] != 0) {
			long temp = arr[i];
			while ((double)arr[i] <= (double)maxx / (double)temp) {
				if ((double)arr[i] >= (double)minx / (double)temp) cnt++;
				temp *= arr[i];
			}
		}
	}

	cout << cnt << '\n';
	return 0;
}