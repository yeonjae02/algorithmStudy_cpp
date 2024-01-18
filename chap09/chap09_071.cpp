#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// BOJ 2042
typedef long long ll;
vector<ll>tree;

ll getSum(int s, int e) {
	ll partSum = 0;
	while (s <= e) {
		if (s % 2 == 1) {
			partSum += tree[s];
			s++;
		}
		if (e % 2 == 0) {
			partSum += tree[e];
			e--;
		}
		s /= 2;
		e /= 2;
	}
	return partSum;
}

void changeValue(int idx, ll val) {
	ll dif = val - tree[idx];
	while (idx > 0) {
		tree[idx] += dif;
		idx /= 2;
	}
}

void setTree(int i) {
	while (i != 1) {
		tree[i / 2] += tree[i];
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

	int treeHeight=0, length = n;
	while (length != 0) {
		length /= 2;
		treeHeight++;
	}

	int treeSize = int(pow(2, treeHeight + 1));
	int startIdx = treeSize / 2 - 1;
	tree.resize(treeSize+1);

	for (int i = startIdx + 1; i <= startIdx + n; i++)cin >> tree[i];
	setTree(treeSize - 1);

	for (int i = 0; i < m + k; i++) {
		ll a, s, e;
		cin >> a >> s >> e;

		if (a == 1)
			changeValue(startIdx + s, e);
		else if (a == 2) {
			s += startIdx;
			e += startIdx;
			cout << getSum(s, e) << "\n";
		}
	}
	return 0;
}