#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// BOJ 1414

vector <int> parent;
typedef struct Edge {
	int s, e, v;
	bool operator > (const Edge& temp) const {
		return v > temp.v;
	}
} Edge;

int find(int a) {
	if (a == parent[a]) return a;
	else return parent[a] = find(parent[a]);
}

void munion(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) parent[b] = a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, sum = 0;
	cin >> n;
	
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char tmpc = cin.get();
			if (tmpc == '\n') tmpc = cin.get();
			
			int tmp = 0;
			if (tmpc >= 'a' && tmpc <= 'z')
				tmp = tmpc - 'a' + 1;
			else if (tmpc >= 'A' && tmpc <= 'Z')
				tmp = tmpc - 'A' + 27;

			sum += tmp;
			if (i != j && tmp != 0)
				pq.push(Edge{ i, j, tmp });
		}
	}

	parent.resize(n);
	for (int i = 0; i < n; i++) parent[i] = i;

	int useEdge = 0, result = 0;
	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (find(now.s) != find(now.e)) {
			munion(now.s, now.e);
			result += now.v;
			useEdge++;
		}
	}

	if (useEdge == n - 1)cout << sum - result << "\n";
	else cout << -1 << "\n";

	return 0;
}