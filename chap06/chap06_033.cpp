#include <iostream>
#include <queue>
using namespace std;

// BOJ 1715

int main()
{
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0, tmp=0; i < n; i++) {
		cin >> tmp;
		pq.push(tmp);
	}

	int first, second, sum=0;
	while (pq.size() != 1) {
		first = pq.top();
		pq.pop();
		second = pq.top();
		pq.pop();

		sum += first + second;
		pq.push(first + second);
	}

	cout << sum << "\n";
	return 0;
}