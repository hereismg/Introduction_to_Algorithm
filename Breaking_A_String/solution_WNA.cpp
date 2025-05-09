#include <iostream>
using namespace std;

using PII = pair<int, int>;

const int N = 1e5 + 7;

int splits[N];
int result;
int ops[N];
int length;

// TODO: 修改方案, 找到一个 i 使 |L[i] - (nl + nr) / 2| 最小
int fun(int nl, int nr, int ml, int mr) {
	if(mr - ml <= 1) return 0;
	int sm = nr - nl + 1;
	int midml = (ml + mr) / 2;
	int midmr = (ml + mr + 2 - 1) / 2;
	int mid = (nr - splits[midmr] > splits[midml] - nl) ? (midmr) : (midml);
	ops[length] = mid;
	++ length;
	sm += fun(nl, splits[mid], ml, mid);
	sm += fun(splits[mid] + 1, nr, mid, mr);
	return sm;
}

void solve() {
	int n, m;
	cin >> n >> m;
	result = 0;
	length = 0;
	for(int i = 0; i < m; ++ i) {
		int tmp;
		cin >> tmp;
		splits[i] = tmp - 1;
	}
	
	cout << fun(0, n - 1, -1, m) << endl;
	for(int i = 0; i < length; ++ i) {
		if(i > 0) cout << " ";
		cout << (ops[i] + 1);
	}
	cout << endl;
	
}

int main() {
	int T = 1;
//	cin >> T;
	while(T --) {
		solve();
	}
	return 0;
}
