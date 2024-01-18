#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BOJ 1516

int main2()
{
	vector<vector<int>> arr;
	vector<int> dg;
	vector<int> cost;
	vector<int> result;
	queue<int>q;

	int n;
	cin >> n;

	arr.resize(n + 1);
	dg.resize(n + 1);
	cost.resize(n + 1);
	result.resize(n + 1);

	for (int i = 1, pre; i <= n; i++) {
		cin >> cost[i];
		while (true) {
			cin >> pre;
			if (pre == -1) break;
			arr[pre].push_back(i);
			dg[i]++;
		}
	}

	for (int i = 1; i <= n; i++)
		if (dg[i] == 0) q.push(i);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i : arr[now]) {
			dg[i]--;
			result[i] = max(result[i], result[now] + cost[now]);
			if (dg[i] == 0) q.push(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << result[i] + cost[i] << "\n";
	}
	return 0;
}