#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

// BOJ 1948

typedef pair<int, int> p;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<p>> arr;
	vector<vector<p>> rarr;
	vector<int> dg;
	vector<int> result;
	vector<bool> visited;
	queue<int> q;
	queue<int> rq;

	int n, m, start, end, resultCnt=0;
	cin >> n >> m;
	arr.resize(n + 1);
	rarr.resize(n + 1);
	dg.resize(n + 1);
	result.resize(n + 1);
	visited.resize(n + 1);

	for (int i = 0; i < m; i++) {
		int s, e, v;
		cin >> s >> e >> v;
		arr[s].push_back(make_pair(e, v));
		rarr[e].push_back(make_pair(s, v));
		dg[e]++;
	}

	cin >> start >> end;
	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (p i : arr[now]) {
			dg[i.first]--;
			result[i.first] = max(result[i.first], result[now] + i.second);
			if (dg[i.first] == 0) q.push(i.first);
		}
	}

	rq.push(end);
	while (!rq.empty()) {
		int now = rq.front();
		rq.pop();

		for (p i : rarr[now]) {
			if (result[i.first] + i.second == result[now]) {
				resultCnt++;
				if (visited[i.first] == false) {
					visited[i.first] = true;
					rq.push(i.first);
				}
			}
		}
	}
	cout << result[end] << "\n" << resultCnt << "\n";

	return 0;
}