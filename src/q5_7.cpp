#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long Int;

const int INF = 1 << 29;

template<class T> void chmin(T &a, T b) { if (a > b) a = b; }
template<class T> void chmax(T &a, T b) { if (a < b) a = b; }

// 章末問題 5.7
int main() {
    string S, T;
    cin >> S >> T;

    int N = S.size(), M = T.size();

    vector<vector<int>> dp(S.size() + 1, vector<int>(T.size() + 1, 0));

    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= M; ++j) {
            if (i > 0 && j > 0) {
                if (S[i - 1] == T[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
    }

    cout << dp[N][M] << endl;
}
