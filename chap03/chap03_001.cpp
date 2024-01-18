#include <iostream>
using namespace std;

// BOJ 11720

int main()
{
	int n, sum = 0;
	string numbers;
	cin >> n;
	cin >> numbers;

	for (int i = 0; i < numbers.length(); i++) sum += (numbers[i] - '0');
	cout << sum << "\n";
	return 0;
}