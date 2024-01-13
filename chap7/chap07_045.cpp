// BOJ 21568

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

vector<ll> ex(ll a, ll b) {
	vector<ll> ret(2);
	if (b == 0) {
		ret[0] = 1;
		ret[1] = 0;
		return ret;
	}

	ll q = a / b;
	vector<ll>v = ex(b, a % b);
	ret[0] = v[1];
	ret[1] = v[0] - v[1] * q;
	return ret;
}

int main()
{
	ll a, b, c;
	cin >> a >> b >> c;
	ll tgcd = gcd(a, b);

	if (c != tgcd) cout << "-1";
	else {
		int mok = (int)(c / tgcd);
		vector <ll> ret = ex(a, b);
		cout << ret[0] * mok << " " << ret[1] * mok;
	}

	return 0;
}

/*
Âü°í 
https://latter2005.tistory.com/63
https://allmymight.tistory.com/90
*/