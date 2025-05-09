#include <vector>
#include <iostream>
using namespace std;

pair<int, int> change(pair<int, int> coord){
    int x = coord.first;
    int y = coord.second;
    return {y, x + y + 2};
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> split_arr(m, 0);
    for (int i=0; i<m; i++){
        cin >> split_arr[i];
    }
    if (split_arr[0] != 1) split_arr.insert(split_arr.begin(), 1);
    if (split_arr[m+1] != n) split_arr.push_back(n);

    // for (auto i: split_arr){
    //     cout << i << endl;
    // }

    vector<int> dp(m + 1, 0);

    for (int i=0; i<m; i++){
        for (int j=0; j<m-i; j++){
            auto temp = change({i, j});
            int x_p = temp.first;
            int y_p = temp.second;
            
            dp[j] = min(dp[j], dp[j+1]) + split_arr[y_p] - split_arr[x_p] + 1;
        }
    }

    cout << dp[0] << endl;;

    return 0;
}