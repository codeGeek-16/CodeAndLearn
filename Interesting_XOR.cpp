/* 
author : HARSH AGRAWAL 
codechef : harshagrawal16
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll c;
	cin >> c;
	ll x = 32;
	bool flag = false;
	ll a = 0, b = 0;
    
 
	while (x--) {
		if ((1 << x) & c) {
			if (!flag) {
				//OR operation to add 2^(x) to a
				a = a | (1 << x);
				flag = true;
			}
			else {
				b = b | (1 << x);
			}
		}
		else {
			if (!flag) continue;
			a = a | (1 << x);
			b = b | (1 << x);
		}
	}
	cout << a*b << endl;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

}