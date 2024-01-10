#include <iostream>
#include <deque>
using namespace std;
typedef pair<int, int> Node;

// BOJ 11003

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, l, tmp;
	cin >> n >> l;
	deque<Node> d;

	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (d.size() && d.front().second < i - l+1) d.pop_front();
		while (d.size() && d.back().first > tmp) d.pop_back();
		d.push_back(Node(tmp, i));
		cout << d.front().first << " ";
	}

	return 0;
}