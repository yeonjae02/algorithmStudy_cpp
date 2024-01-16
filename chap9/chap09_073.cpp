#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
// BOJ 11505

typedef long long ll;
#define MOD 1000000007 
vector<ll> tree;

ll getMul(int s, int e) {
	ll partMul = 1;
	while (s <= e) {
		if (s % 2 == 1) {
			partMul = partMul * tree[s] % MOD;
			s++;
		}
		if (e % 2 == 0) {
			partMul = partMul * tree[e] % MOD;
			e--;
		}
		s /= 2;
		e /= 2;
	}
	return partMul;
}

void changeValue(int idx, ll v) {
	tree[idx] = v;
	while (idx > 1) {
		idx /= 2;
		tree[idx] = tree[idx * 2] % MOD * tree[idx * 2 + 1] % MOD;
	}
}

void setTree(int i) {
	while (i != 1) {
		tree[i / 2] = tree[i / 2] * tree[i] % MOD;
		i--;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	int treeHeight = 0, length = n;
	while (length != 0) {
		length /= 2;
		treeHeight++;
	}

	int treeSize = int(pow(2, treeHeight + 1));
	int startIdx = treeSize / 2 - 1;
	tree.resize(treeSize + 1);
	fill(tree.begin(), tree.end(), 1);

	for (int i = startIdx + 1; i <= startIdx + n; i++) cin >> tree[i];
	setTree(treeSize - 1);

	for (int i = 0; i < m + k; i++) {
		ll a, s, e;
		cin >> a >> s >> e;

		if (a == 1) changeValue(startIdx + s, e);
		else if (a == 2) {
			s += startIdx;
			e += startIdx;
			cout << getMul(s, e) << "\n";
		}
	}

	return 0;
}