#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef long long Int;

const int INF = 1 << 29;

template<class T> void chmin(T &a, T b) { if (a > b) a = b; }
template<class T> void chmax(T &a, T b) { if (a < b) a = b; }

// 章末問題 5.4
int main() {
    int N, K, W;
    cin >> N >> K >> W;
    vector<Int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];

    vector<vector<Int>> dp(N+1, vector<Int>(W+1, INF));

    dp[0][0] = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= W; ++j) {
            // a[i]を選ぶ場合
            if (j - a[i] >= 0) {
                chmin(dp[i + 1][j], dp[i][j - a[i]] + 1);
            }
            // a[i]を選ばない場合
            chmin(dp[i + 1][j], dp[i][j]);
        }
    }

    string res = "No";
    if (dp[N][W] <= K) res = "Yes";

    cout << res << endl;
}
