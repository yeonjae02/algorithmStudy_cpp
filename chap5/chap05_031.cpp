#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
	ll n, k;
	cin >> n >> k;
	ll left = 1, right = k,ans=0, mid, cnt;

	while (left <= right) {
		mid = (left + right) / 2;
		cnt = 0;

		for (int i = 1; i <= n; i++) {
			cnt += min(mid / i, n);
		}

		if (cnt < k) left = mid + 1;
		else {
			ans = mid;
			right = mid - 1;
		}

	}
	cout << ans;
	return 0;
}