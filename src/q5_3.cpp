#include <iostream>
#include <vector>
#include <algorithm>

typedef long long Int;

using namespace std;

// 章末問題 5.3
int main() {
    int N, W;
    cin >> N >> W;
    vector<Int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    // i個からjを作れるかどうか
    vector<vector<bool>> dp(N+1, vector<bool>(W+1, false));

    dp[0][0] = true;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= W; ++j) {
            if (dp[i][j]) {
                dp[i + 1][j] = true;
                if (j + a[i] <= W) {
                    dp[i + 1][j + a[i]] = true;
                }
            }
        }
    }

    int res = 0;
    for (int j = 0; j <= W; ++j) {
        if (dp[N][j]) ++res;
    }

    cout << res << endl;
}
