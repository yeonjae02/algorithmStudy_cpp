#include <iostream>
using namespace std;
// BOJ 1991

int tree[26][2];

void preorder(int i) {
	if (i == -1) return;
	cout << (char)(i + 'A');
	preorder(tree[i][0]);
	preorder(tree[i][1]);
}

void inorder(int i) {
	if (i == -1) return;
	inorder(tree[i][0]);
	cout << (char)(i + 'A');
	inorder(tree[i][1]);
}

void postorder(int i) {
	if (i == -1) return;
	postorder(tree[i][0]);
	postorder(tree[i][1]);
	cout << (char)(i + 'A');
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char n, l, r;
		cin >> n >> l >> r;

		int idx = n - 'A';
		if (l == '.') tree[idx][0] = -1;
		else tree[idx][0] = l - 'A';

		if (r == '.') tree[idx][1] = -1;
		else tree[idx][1] = r - 'A';
	}

	preorder(0);
	cout << "\n";
	inorder(0);
	cout << "\n";
	postorder(0);
	cout << "\n";
	return 0;
}