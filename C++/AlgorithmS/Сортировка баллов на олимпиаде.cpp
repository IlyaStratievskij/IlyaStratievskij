#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector <pair <int, int>> a(n);
	int numbers, points;
	for (int i = 0; i < n; i++) { cin >> numbers >> points; a[i] = { -points, numbers}; }
	sort(a.begin(), a.end());
	//reverse(a.begin(), a.end());
	for (auto now : a) cout << now.second << " " << -now.first << endl;
	return 0;
}
    
