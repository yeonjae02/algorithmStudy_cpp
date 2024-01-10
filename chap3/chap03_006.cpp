#include <iostream>
using namespace std;

// BOJ 2018

int main()
{
	int n, cnt=1, start=1, end=1, sum=1;
	cin >> n;

	while (end != n) {
		if (sum == n) {
			cnt++;
			end++;
			sum += end;
		}
		else if (sum > n) {
			sum -= start;
			start++;
		}
		else {
			end++;
			sum += end;
		}
	}

	cout << cnt << "\n";

	return 0;
}