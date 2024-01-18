#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// BOJ 1874

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector <int> v(n);
	vector <char> result;

	for (int i = 0; i < n; i++) cin >> v[i];

	stack<int>st;
	int num = 1;
	bool isresult = true;

	for (int i = 0; i < v.size(); i++) {
		int tmp = v[i];
		if (tmp >= num) {
			while (tmp >= num) {
				st.push(num++);
				result.push_back('+');
			}
			st.pop();
			result.push_back('-');
		}
		else {
			int peek = st.top();
			st.pop();
			if (peek > tmp) {
				cout << "NO";
				isresult = false;
				break;
			}
			else result.push_back('-');
		}
	}

	if (isresult) 
		for (int i = 0; i < result.size(); i++) cout << result[i] << "\n";
	return 0;
}