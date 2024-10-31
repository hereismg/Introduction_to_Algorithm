#include<iostream>
#include<vector>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> p[i];

        vector<int> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                dp[j] = max(dp[j], dp[j-i] + p[i]);
            }
        }

        cout << dp[n] << endl;
    }
    
    return 0;
}
