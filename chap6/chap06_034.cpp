#include <iostream>
#include <queue>
using namespace std;

// BOJ 1744

int main() {
	int n,oneCnt=0,zeroCnt=0, sum=0, first, second;
	priority_queue<int> pluspq;
	priority_queue<int, vector<int>, greater<int>> minuspq;

	cin >> n;
	for (int i = 0,tmp; i < n; i++) {
		cin >> tmp;
		if (tmp > 1) pluspq.push(tmp);
		else if (tmp == 1) oneCnt++;
		else if (tmp == 0) zeroCnt++;
		else minuspq.push(tmp);
	}

	while (pluspq.size() != 0) {
		first = pluspq.top();
		pluspq.pop();
		if (pluspq.size() == 0) {
			sum += first;
			break;
		}
		second = pluspq.top();
		pluspq.pop();
		sum += (first * second);
	}

	while (minuspq.size() != 0) {
		first = minuspq.top();
		minuspq.pop();

		if (minuspq.size() == 0) {
			if (zeroCnt == 0) sum += first;
			break;
		}
		second = minuspq.top();
		minuspq.pop();
		sum += (first * second);
	}

	sum += oneCnt;
	cout << sum << "\n";

	return 0;
}