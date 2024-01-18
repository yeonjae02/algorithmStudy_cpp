#include <iostream>
#include <queue>
#include <vector>

// BOJ 11286

using namespace std;

struct cmp {
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b)) return a > b;
		return abs(a) > abs(b);
	}
};

int main()
{
	int n, x;
	priority_queue <int, vector<int>, cmp> pq;
	vector <int>v;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x == 0)
		{
			if (pq.empty()) v.push_back(0);
			else
			{
				v.push_back(pq.top());
				pq.pop();
			}
		}
		else pq.push(x);
	}

	for (int i = 0; i < v.size(); i++) cout << v[i] << "\n";
	return 0;
}