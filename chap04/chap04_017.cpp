#include <iostream>
#include <string>
#include <vector>
using namespace std;

// BOJ 1427

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	string s;
	cin >> s;
	vector <int> v(s.size());

	for (int i = 0; i < s.size(); i++) v[i] = stoi(s.substr(i, 1));

	for (int i = 0; i < s.length(); i++) {
		int maxValue = i;
		for (int j = i + 1; j < s.length(); j++) {
			if (v[j] > v[maxValue]) maxValue = j;
		}

		if (v[i] < v[maxValue]) swap(&v[i], &v[maxValue]);
	}

	for (int i = 0; i < s.size(); i++) cout << v[i];
	return 0;
}