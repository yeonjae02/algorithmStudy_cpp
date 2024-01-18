#include <iostream>
#include <queue>
using namespace std;

// BOJ 2164

int main() {
	int n, tmp;
	cin >> n;
	queue <int> q;
	for (int i = 0; i < n; i++) q.push(i + 1);

	while (q.size() != 1)
	{
		q.pop();
		q.push(q.front());
		q.pop();
	}

	cout << q.front();
	return 0;
}