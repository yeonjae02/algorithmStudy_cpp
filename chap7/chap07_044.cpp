#include <iostream>
#include <vector>
using namespace std;

vector<bool> isvisited(11);

struct s{
	int value = 1;
	vector<int> v;
}arr[11];

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

void dfs(int c, int v) {
	isvisited[c] = true;
	arr[c].value *= v;

	for (auto i : arr[c].v) {
		if (!isvisited[i]) dfs(i, v);
	}
}

int main()
{
	int n, cgcd, amod, bmod, a, b, p, q;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> p >> q;
		cgcd = gcd(p, q);
		amod = arr[b].value * p / cgcd;
		bmod = arr[a].value * q / cgcd;

		cgcd = gcd(amod, bmod);

		fill(isvisited.begin(), isvisited.end(), false);
		dfs(a, amod / cgcd);
		dfs(b, bmod / cgcd);

		arr[a].v.push_back(b);
		arr[b].v.push_back(a);
	}

	for (int i = 0; i < n; i++) cout << arr[i].value << " ";
	return 0;
}