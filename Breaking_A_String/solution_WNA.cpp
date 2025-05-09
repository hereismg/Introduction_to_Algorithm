#include <iostream>
using namespace std;

const int N = 1e5 + 7;

int splits[N];
int result;
int ops[N];
int length;

// TODO: 加速方案, 找到一个 i 使 |L[i] - (nl + nr) / 2| 最小
int fun(int nl, int nr, int ml, int mr) {
	if(mr - ml <= 1) return 0;
	int sm = nr - nl + 1;
	
	double mid = 1.0 * (nr - nl) / 2;
	double mn = -7;
	int mnidx;
	for(int i = ml + 1; i < mr; ++ i) {
		double dis = mid - splits[i];
		if(dis < 0) dis = -dis;
		if(mn < -5 || mn > dis) {
			mnidx = i;
			mn = dis;
		}
	}
	
	ops[length] = mnidx;
	++ length;
	sm += fun(nl, splits[mnidx], ml, mnidx);
	sm += fun(splits[mnidx] + 1, nr, mnidx, mr);
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
