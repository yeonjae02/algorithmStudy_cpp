#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BOJ 1325
typedef long long ll;
static vector<vector<int>> arr;
static vector<int> ans;
static vector<bool> isvisited;

void bfs(int n) {
	queue<int> q;
	q.push(n);
	isvisited[n] = true;

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int i : arr[now]) {
			if (!isvisited[i]) {
				isvisited[i] = true;
				ans[i]++;
				q.push(i);
			}
		}
	}
}

int main() 
{
	ll n, m;
	cin >> n >> m;
	arr.resize(n + 1);
	ans.resize(n + 1);
	isvisited.resize(n + 1);

	for (int i = 0, s, e; i < m; i++)
	{
		cin >> s >> e;
		arr[s].push_back(e);
	}

	for (int i = 0; i <= n; i++) {
		fill(isvisited.begin(), isvisited.end(), false);
		bfs(i);
	}

	int maxValue = -1;
	for (int i = 1; i <= n; i++)
		if (maxValue < ans[i]) maxValue = ans[i];


	for (int i = 1; i <= n; i++)
		if (maxValue == ans[i]) cout << i << " ";

	return 0;
}