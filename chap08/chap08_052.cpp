#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// BOJ 1043

static vector<int> parent;
static vector<int> truep;
static vector<vector<int>> party;
static int result;

int find(int a) {
	if (a == parent[a]) return a;
	else return parent[a] = find(parent[a]);
}

void unionfunc(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) parent[b] = a;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, t;
	cin >> n >> m >> t;

	truep.resize(t);
	for (int i = 0; i < t; i++) cin >> truep[i];

	party.resize(m);
	for (int i = 0, partySize; i < m; i++) {
		cin >> partySize;
		for (int j = 0, tmp; j < partySize; j++) {
			cin >> tmp;
			party[i].push_back(tmp);
		}
	}

	parent.resize(n + 1);
	for (int i = 0; i <= n; i++) parent[i] = i;

	for (int i = 0; i < m; i++) {
		int first = party[i][0];
		for (int j = 1; j < party[i].size(); j++)
			unionfunc(first, party[i][j]);
	}

	for (int i = 0; i < m; i++) {
		bool isok = true;
		int current = party[i][0];
		for (int j = 0; j < t; j++) {
			if (find(current) == find(truep[j])) {
				isok = false;
				break;
			}
		}
		if (isok) result++;
	}
	cout << result;
	return 0;
}