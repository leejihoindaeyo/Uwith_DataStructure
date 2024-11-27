#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	deque<int> dq;
	while (n--){
		string a; cin >> a;
		if (a == "push_back"){
			int k; cin >> k;
			dq.push_back(k);
		}
		else if (a == "push_front"){
			int k; cin >> k;
			dq.push_front(k);
		}
		else if (a == "pop_front")
		{
			if (dq.empty()) cout << "-1\n";
			else{
				cout << dq.front() << '\n';
				dq.pop_front();
			}
		}
		else if (a == "pop_back")
		{
			if (dq.empty()) cout << "-1\n";
			else{
				cout << dq.back() << '\n';
				dq.pop_back();
			}
		}
		else if (a == "size")
			cout << dq.size() << '\n';
		else if (a == "empty"){
			if (dq.empty()) cout << "1\n";
			else cout << "0\n";
		}
		else if (a == "front"){
			if (dq.empty()) cout << "-1\n";
			else cout << dq.front() << '\n';
		}
		else if (a == "back"){
			if (dq.empty()) cout << "-1\n";
			else cout << dq.back() << '\n';
		}
	}
	return 0;
}