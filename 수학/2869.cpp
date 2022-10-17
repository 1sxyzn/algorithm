#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, v;
	int day = 0;
	cin >> a >> b >> v;
	day = (v - a) / (a - b) + 1; //마지막엔 미끄러지지 않으므로 v-a 만큼만 가고, a 만큼 더 가야하니 +1
	if ((v - a) % (a - b) != 0) day++;
	cout << day;
}
