#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BOJ 2178

int n, m, maze[101][101], now[2];
int dx[4] = { 0,1,0, -1 }, dy[4] = { 1, 0, -1,0 };
bool visited[101][101] = {false, };

void bfs(int sx, int sy) {
	queue <pair<int, int>>q;
	q.push(make_pair(sx, sy));

	while (!q.empty()) {
		now[0] = q.front().first;
		now[1] = q.front().second;
		q.pop();
		visited[sx][sy] = true;

		for (int i = 0; i < 4; i++) {
			int tx = now[0] + dx[i];
			int ty = now[1] + dy[i];

			if (tx >= 0 && ty >= 0 && tx < n && ty < m) {
				if (maze[tx][ty] != 0 && !visited[tx][ty])
				{
					visited[tx][ty] = true;
					maze[tx][ty] = maze[now[0]][now[1]] + 1;
					q.push(make_pair(tx, ty));
				}
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++)
			maze[i][j] = s[j] - '0';
	}

	bfs(0, 0);
	cout << maze[n - 1][m - 1] << "\n";
	return 0;
}