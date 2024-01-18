#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#define MAX 1003002 // 결과가 n보다 클 수 있음!!!
using namespace std;

// BOJ 1747

long n, i, v[MAX];

bool ispalindrome(int n) {
	string s = to_string(n);
	for (int i = 0, j = s.length()-1; i < j; i++, j--)
		if (s[i] != s[j]) return false;
	return true;
}

int main()
{
	cin >> n;

	for (int i = 2; i < MAX; i++) v[i] = i;
	
	for (int i = 2; i <= sqrt(MAX); i++) {
		if (v[i] == 0) continue;
		for (int j = i + i; j < MAX; j += i) v[j] = 0;
	}

	i = n;
	while (true) {
		if (v[i] != 0 && ispalindrome(i)) {
			cout << i;
			return 0;
		}
		else i++;
	}
}