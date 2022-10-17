#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n;
	vector<int>v;
	while (n--) {
		cin >> m;
		v.push_back(m);
	}
	sort(v.begin(), v.end());
	
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
}
