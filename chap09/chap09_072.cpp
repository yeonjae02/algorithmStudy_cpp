#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// BOJ 10868

typedef long long ll;
#define INF (~0U>>2)
vector<ll> tree;

void getMin(int s, int e) {
	ll result = INF;

	while (s <= e) {
		if (s % 2 == 1) {
			result = min(result, tree[s]);
			s++;
		}
		if (e % 2 == 0) {
			result = min(result, tree[e]);
			e--;
		}
		s /= 2;
		e /= 2;
	}
	cout << result << "\n";
}


void setTree(int i) {
	while (i != 1) {
		if (tree[i/2] > tree[i])
			tree[i / 2] = tree[i];
		i--;
	}
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int treeHeight = 0, length = n;
	while (length != 0) {
		length /= 2;
		treeHeight++;
	}

	int treeSize = int(pow(2, treeHeight + 1));
	int startIdx = treeSize / 2 - 1;
	tree.resize(treeSize + 1);
	fill(tree.begin(), tree.end(), INF);

	for (int i = startIdx + 1; i <= startIdx + n; i++) cin >> tree[i];

	setTree(treeSize - 1);
	for (int i = 0; i < m; i++) {
		ll a, b;
		cin >> a >> b;
		a += startIdx;
		b += startIdx;
		getMin(a, b);
	}

	return 0;
}