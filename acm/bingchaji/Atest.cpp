#include<iostream> 
using namespace std;

int n;
int Father[10001];

int find(int x) {
	if (Father[x] == x) return x;
	else return Father[x] = find(Father[x]);
}   //查找根结点

int main() {
	int m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) Father[i] = i;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) Father[find(c)] = find(b);   //合并
		if (a == 2) {
			if (find(b) == find(c)) cout << "Yes\n";
			else cout << "NO\n";
		}
	}
	return 0;
}