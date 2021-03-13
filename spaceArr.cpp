/* 
author : HARSH AGRAWAL 
codechef : harshagrawal16
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve()
{
	ll n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());

	int steps = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] <= i + 1) {
			steps = steps + ((i + 1) - arr[i]);
		}
		else {
			cout << "Second" << endl;
			return;
		}
	}

	if (steps % 2 == 0) {
		cout << "Second" << endl;
	}
	else {
		cout << "First" << endl;
	}
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





