#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BOJ 2252

int main()
{
	int n, m;
	vector<vector<int>>arr;
	vector<int> dg;
	queue<int>q;

	cin >> n >> m;
	arr.resize(n + 1);
	dg.resize(n + 1);

	for (int i = 0, s, e; i < m; i++) {
		cin >> s >> e;
		arr[s].push_back(e);
		dg[e]++;
	}

	for (int i = 1; i <= n; i++) if (dg[i] == 0) q.push(i);

	while (!q.empty()) 
	{
		int now = q.front();
		q.pop();
		cout << now << " ";

		for (int i : arr[now]) {
			dg[i]--;
			if (dg[i] == 0) q.push(i);
		}
	}

	return 0;
}