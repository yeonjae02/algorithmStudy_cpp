#include <iostream>
#include <vector>
using namespace std;
// BOJ 1016

typedef long long ll;
bool v[1000001] = {false,};

int main()
{
	ll minv, maxv,tmp;
	cin >> minv >> maxv;


	for (ll i = 2; i * i <= maxv; i++) {
		tmp = minv / (i * i);
		if (minv % (i * i)) tmp++;

		while (tmp * i * i <= maxv) {
			v[tmp * i * i - minv] = true;
			tmp++;
		}
	}

	int cnt = 0;
	for (int i = 0; i <= maxv - minv; i++) if (!v[i]) cnt++;
	cout << cnt << "\n";
	return 0;
}

// https://restudycafe.tistory.com/355