#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 章末問題 5.2
int main() {
    int N;
    int W;
    vector<int> a(N);

    cin >> N >> W;
    for (int i = 0; i < N; i++) cin >> a[i];
    
    // 最初のi個目までの総和をjにできるかどうか
    vector<vector<bool>> dp(N+1, vector<bool>(W+1, false));

    dp[0][0] = true;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= W; ++j) {
            // a[i]を選ばない場合
            if (dp[i][j]) dp[i + 1][j] = true;
            // a[i]を選ぶ場合
            if (j >= a[i] && dp[i][j - a[i]]) {
                dp[i + 1][j] = true;
            }
        }
    }

    string res;
    if (dp[N][W]) res = "Yes";
    else res = "No";

    cout << res << endl;
}
